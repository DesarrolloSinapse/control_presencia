import psycopg2
import httplib2
import sys
import time
import http.server
import socketserver
from xml.dom.minidom import parse, parseString
import xml.etree.cElementTree as ET
import binascii
import smtplib
import http

def create_val(ip_lec):
	
	bd = psycopg2.connect(host='localhost', database='BD_SERVER', user='sinapse', password='napse1si')
	cursor = bd.cursor()

	cursor.execute("SELECT * FROM equipos WHERE ip='"+ip_lec+"'")

	res = cursor.fetchone()

	root = ET.Element("horfeus")
	aula = ET.SubElement(root,"aula")
	c1 = ET.SubElement(aula,"codigo")
	c1.text = str(res[0])
	c2 = ET.SubElement(aula,"edificio")
	c2.text = str(res[2])
	c3 = ET.SubElement(aula,"tipo")
	c3.text = 'ENTRADA/SALIDA'
	c4 = ET.SubElement(aula,"nombre")
	c4.text = str(res[1])
	c5 = ET.SubElement(root,"dispositivo")
	c5.text = str(res[0])
	text = ET.tostring(root)

	cursor.execute('UPDATE equipos SET updated_at = %s WHERE ip = %s',(time.strftime('%Y-%m-%d %H:%M:%S'), ip_lec,))

	return text

def create_reg(codigo, nombre, documento, acceso):
	
	root = ET.Element("resultado")
	c1 = ET.SubElement(root, "registro")
	c1.text = str(codigo)
	c2 = ET.SubElement(root, "tiempoServidor")
	c2.text = time.strftime("%Y-%m-%d %H:%M:%S")
	c3 = ET.SubElement(root, "nombre")
	c3.text = nombre
	c4 = ET.SubElement(root, "documento")
	c4.text = documento
	c5 = ET.SubElement(root, "acceso")
	if(acceso):
		c5.text = "ENTRA"
	else:
		c5.text = "SALE"

	if(codigo < 0):
		c5.text = " "

	text = ET.tostring(root)

	return text

def procesa_post(cadena):
	p1 = cadena.find('3C')
	c1 = binascii.unhexlify(bytes(cadena[p1:p1+2],'UTF-8'))
	m1 = cadena.replace('3C',c1.decode(encoding='UTF-8'))
	
	p2 = cadena.find('3E')
	c2 = binascii.unhexlify(bytes(cadena[p2:p2+2],'UTF-8'))
	m2 = m1.replace('3E',c2.decode(encoding='UTF-8'))
	
	p3 = cadena.find('2F')
	c3 = binascii.unhexlify(bytes(cadena[p3:p3+2],'UTF-8'))
	m3 = m2.replace('2F',c3.decode(encoding='UTF-8'))

	p4 = cadena.find('3A')
	c4 = binascii.unhexlify(bytes(cadena[p4:p4+2],'UTF-8'))
	m4 = m3.replace("3A",c4.decode(encoding='UTF-8'))

	m5 = m4.replace('%','')
	m6 = m5.replace('+',' ')

	p_ini_tiempo = m6.find('<tiempo>')+8
	p_fin_tiempo = m6.rfind('</tiempo>')

	tiempo = m6[p_ini_tiempo:p_fin_tiempo]

	p_ini_codigo = m6.find('<serie>')+7
	p_fin_codigo = m6.rfind('</serie>')
	codigo = m6[p_ini_codigo:p_fin_codigo]

	cod_usuario = codigo[4:]
	cod_tarjeta = codigo[:4]
	
	return(tiempo,cod_usuario,cod_tarjeta)

def envio_email(asunto, mensaje):

	bd = psycopg2.connect(host='localhost', database='BD_SERVER', user='sinapse', password='napse1si')
	cursor = bd.cursor()

	cursor.execute("SELECT * FROM emails")
	if(cursor.rowcount != 0):
		servidor = cursor.fetchone()

		if(servidor[5]):
			server = smtplib.SMTP_SSL(servidor[3],servidor[4])
		else:
			server = smtplib.SMTP(servidor[3],servidor[4])

		if servidor[2] != '':
    			server.login(servidor[1],servidor[2])
	
		cursor.execute("SELECT * FROM users WHERE admin = 1")
		administradores = cursor.fetchall()
		for admin in administradores:
			msg = '''From: SERVIDOR CONTROL DE PRESENCIA <%s>
			To: %s <%s>
			MIME-Version: 1.0
			Content-Type: text/html
			Subject: %s
			%s
			''' % (servidor[1], admin[1], admin[1], asunto, mensaje)
				
			server.sendmail(servidor[1],admin[1],msg.encode("ascii","ignore"))			
	else:
		print("\n-----------------------------------\n"+asunto+"\n\n"+mensaje+"\n-----------------------------------\n")


def genera_xml(ip, t_lectora, cod_usuario, cod_tarjeta):
	bd = psycopg2.connect(host='localhost', database='BD_SERVER', user='sinapse', password='napse1si')
	bd.autocommit=True
	cursor = bd.cursor()

	cursor.execute('SELECT * FROM usuarios WHERE codigo=%s',(cod_usuario,))
	usuario = cursor.fetchone()

	cursor.execute('SELECT * FROM cards WHERE codigo=%s',(cod_tarjeta,))
	tarjeta = cursor.fetchone()

	cursor.execute('SELECT * FROM equipos WHERE ip=%s',(ip,))
	lectora = cursor.fetchone()

	cursor.execute('UPDATE equipos SET updated_at = %s WHERE id = %s',(time.strftime('%Y-%m-%d %H:%M:%S'), lectora[0],))

	if(usuario[12] != tarjeta[1] or tarjeta[2] != usuario[1]):
		codigo = -1
		nombre = "**ACCESO CON TARJETA INCORRECTA**"
		documento = '********'
		acceso = False
		mensaje = "EL usuario %s %s ha intentado acceder con una tarjeta incorrecta" % (usuario[2], usuario[3])

		envio_email(nombre,mensaje)
		
		return create_reg(codigo, nombre, documento, acceso)
	elif(lectora[4] == 0):
		codigo = -2
		nombre = "**ACCESO DESDE LECTORA DESACTIVADA**"
		documento = '********'
		acceso = False
		mensaje = "EL usuario %s %s ha intentado desde la lectora con IP %s, que se encuentra desactivada" % (usuario[2], usuario[3], lectora[3])

		envio_email(nombre,mensaje)
		
		return create_reg(codigo, nombre, documento, acceso)
	elif(tarjeta[3] == 0):
		codigo = -3
		nombre = "**ACCESO CON TARJETA DESACTIVADA**"
		documento = '********'
		acceso = False
		mensaje = "EL usuario %s %s ha intentado acceder con la tarjeta %s, actualmente desactivada" % (usuario[2], usuario[3], tarjeta[1])

		envio_email(nombre,mensaje)
		
		return create_reg(codigo, nombre, documento, acceso)
	elif(usuario[9] == 0):
		codigo = -4
		nombre = "**USUARIO DADO DE BAJA**"
		documento = '********'
		acceso = False
		mensaje = "EL usuario %s %s ha intentado acceder estando dado de baja" % (usuario[2], usuario[3])

		envio_email(nombre,mensaje)
		
		return create_reg(codigo, nombre, documento, acceso)
	else:

		cursor.execute("SELECT * FROM logs ORDER BY id DESC LIMIT 1")
		ultima = cursor.fetchone()

		if(cursor.rowcount != 0):
			t_ultima = int(time.mktime(time.strptime(str(ultima[2]),"%Y-%m-%d %H:%M:%S")))
			t_actual = int(time.time())

			diferencia = t_actual - t_ultima
		else:
			diferencia = 100

		if(diferencia > 60):

			nombre= usuario[2]+' '+usuario[3]
			documento= tarjeta[1]+usuario[1]

			if(usuario[8] == 0):
				acceso = True
			else:
				acceso = False

			hora_reg = time.strftime('%Y-%m-%d %H:%M:%S')

			cursor.execute('INSERT INTO logs (tiempo_lectora, tiempo_registro, equipo_id, card_id, usuario_id, created_at, updated_at, entrada) VALUES (%s,%s,%s,%s,%s,%s,%s,%s) RETURNING id',(t_lectora, hora_reg, lectora[0], tarjeta[0], usuario[0], hora_reg, hora_reg, acceso, ))
			codigo = cursor.fetchone()[0]

			if(acceso):
				cursor.execute('UPDATE usuarios SET dentro = 1 WHERE id = %s',(usuario[0],))
			else:
				cursor.execute('UPDATE usuarios SET dentro = 0 WHERE id = %s',(usuario[0],))

			return create_reg(codigo,nombre,documento,acceso)
		else:
			codigo = -5
			documento = '********'
			nombre = '**Ultimo acceso fue hace menos de 1 minuto**'
			acceso = False
			return create_reg(codigo,nombre,documento,acceso)

class Auxiliar(http.server.BaseHTTPRequestHandler):
	def do_GET(self):

		res = create_val(self.client_address[0])
		r =res.decode(encoding='UTF-8')

		self.send_response(200)
		self.send_header("Content-type", "text/xml")
		self.send_header("Content-length", str(len(r)))
		self.end_headers()
		self.wfile.flush()
		self.wfile.write(bytes(r,'UTF-8'))
		self.wfile.flush()

	def do_POST(self):

		ip = self.client_address[0]
		longitud = int(self.headers.get('Content-Length',0))
		post = self.rfile.read(longitud)
		res = post.decode(encoding='UTF-8')
		(t_lectora, cod_usuario, cod_tarjeta) = procesa_post(res)

		respuesta = genera_xml(ip, t_lectora, cod_usuario, cod_tarjeta)
		r = respuesta.decode(encoding='UTF-8')

		self.send_response(200, 'OK')
		self.send_header("content-type", 'application/xml; charset="UTF-8')
		self.send_header("content-length", str(len(r)))
		self.send_header('Access-Control-Allow-Credentials', 'true')
		self.send_header('Access-Control-Allow-Origin', '*')
		self.end_headers()

		self.wfile.write(r.encode('UTF-8'))
		self.wfile.flush()

		
def main():
	server_add = ('', 9000)
	httpd = http.server.HTTPServer(server_add,Auxiliar)
	httpd.serve_forever()

main()