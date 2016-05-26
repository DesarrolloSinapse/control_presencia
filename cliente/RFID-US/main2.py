import sys
import httplib2
import xml.etree.cElementTree as ET
import datetime
import time
from threading import Thread
import os
import concurrent.futures
import subprocess
from xml.dom.minidom import parse, parseString
import os.path
import time
from urllib.parse import urlencode

def main():

    #t1 = Thread(target=arranca_rails, args=(myip,))
    #t1.start()

	
    with concurrent.futures.ThreadPoolExecutor(max_workers=2) as executor:
        #future1 = executor.submit( arranca_rails, myip)
        #future2 = executor.submit( reading_card)
        future3 = executor.submit( get_list)
        #print( future1.result() )
        #print( future2.result() )
        #print( future3.result() )

	# Welcome message
######################  MOSTRAR POR PANTALLA FECHA-HORA 
    print("Welcome to RFID Sinapse")
    #bucle donde me quedo leyendo continuamente
	# This loop keeps checking for chips. If one is near it will get the UID and authenticate


def get_list():
  print("FICHERO DE CONFIGURACION")
  while True:
    #h = httplib2.Http(timeout=10, disable_ssl_certificate_validation=True)
    h = httplib2.Http(timeout=20, disable_ssl_certificate_validation=True)
    httplib2.force_exception_to_status_code = True
    try:    
#################### IMPRIMIR EN PANTALLA ACTUALIZACION         
        print("Actualizacion de configuracion a la url ")
        params = {'solicitud': '<horfeus><firma><IP>150.214.143.117</IP><TipoCliente>4</TipoCliente><tiempo>24/09/2014 12:34:26</tiempo><edificio>48</edificio><TipoAula>4</TipoAula><aula>RM14IFIQ</aula><serie>00369512</serie></firma></horfeus>'}
        (resp_headers, content) = h.request("https://172.20.15.136:8443/registro/index.php", "POST", urlencode(params), headers={'content-type':'application/x-www-form-urlencoded'})
 		
        print("Se ha obtenido respuesta") 
        #print(resp_headers)
        print(content)
        dom3 = parseString(content)
        #print(dom3)
        registro = dom3.getElementsByTagName("registro")[0].firstChild.data
        tiempo = dom3.getElementsByTagName("tiempoServidor")[0].firstChild.data
        documento = dom3.getElementsByTagName("documento")[0].firstChild.data
        nombre = dom3.getElementsByTagName("nombre")[0].firstChild.data

        print(registro)
        print(tiempo)
        print(documento)
        print(nombre)
        
    except:
#################### IMPRIMIR EN PANTALLA ERROR DE CONEXION CON EL SERVIDOR, SEGURAMENTE SEA TIMEOUT
        print("Error peticion getlist:", sys.exc_info()[0])
        print("Error peticion getlist:", sys.exc_info()[1])
		##a partir de aqui estoy depurando
        dom3 = parse("resultado.xml")
 
        
        #HASTA AQUI COPIO
        open("errorconexion.log", 'w')
        time.sleep(float(1) * 60)
       
       
print("Ejecutamos el script Python")

main()

#t = Thread(target=get_list, args=())
#t.join
