#include "controlpresencial.h"
#include "ui_controlpresencial.h"
#include <QTimer>
#include <QDateTime>
#include <QString>
#include <QtCore>
#include <QtSql>
#include <QFileSystemWatcher>
#include <iostream>
#include <fstream>



ControlPresencial::ControlPresencial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlPresencial)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
	connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
	timer->start();
	
		
	QTimer *timer2 = new QTimer(this);
	connect(timer2,SIGNAL(timeout()),this,SLOT(RellenaDatosAula()));
    timer2->start(50000);

    QTimer *timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(LimpiaError()));
    timer3->start(100000);

    MonitorizaFicheros("inicio");


}

void ControlPresencial::MonitorizaFicheros(QString str)
{
   // ControlPresencial* mc = new ControlPresencial;
qDebug() << "Monitoriza ficheros " << str;
 QFileSystemWatcher *watcher = new QFileSystemWatcher(this);
    if(str.contains("inicio")){
        QFile f("/home/pi/Desktop/RFID-US/errorconexion.log");
        f.open(QIODevice::ReadWrite);
        QFile f2("/home/pi/Desktop/RFID-US/erroraulas.log");
        f2.open(QIODevice::ReadWrite);
        QFile f3("/home/pi/Desktop/RFID-US/errorlector.log");
        f3.open(QIODevice::ReadWrite);
        QFile f4("/home/pi/Desktop/RFID-US/usuarioregistrado.log");
        f4.open(QIODevice::ReadWrite);
        QFile f5("/home/pi/Desktop/RFID-US/registro.xml");
        f5.open(QIODevice::ReadWrite);
        QFile f6("/home/pi/Desktop/RFID-US/oklector.log");
        f6.open(QIODevice::ReadWrite);
        QFile f7("/home/pi/Desktop/RFID-US/okconexion.log");
        f7.open(QIODevice::ReadWrite);
		QFile f8("/home/pi/Desktop/RFID-US/errorconexionregistro.log");
        f8.open(QIODevice::ReadWrite);
		QFile f9("/home/pi/Desktop/RFID-US/errorrecibido.log");
        f9.open(QIODevice::ReadWrite);
		QFile f10("/home/pi/Desktop/RFID-US/errordom2.log");
        f10.open(QIODevice::ReadWrite);
		QFile f11("/home/pi/Desktop/RFID-US/erroreneldom.log");
        f11.open(QIODevice::ReadWrite);
		QFile f12("/home/pi/Desktop/RFID-US/errorbbdd.log");
        f12.open(QIODevice::ReadWrite);
		QFile f13("/home/pi/Desktop/RFID-US/reintentarlector.log");
        f13.open(QIODevice::ReadWrite);
		
        QObject::connect(watcher, SIGNAL(fileChanged(QString)),this, SLOT(showModified(QString)));
        watcher->addPath("/home/pi/Desktop/RFID-US/errorconexion.log");
        watcher->addPath("/home/pi/Desktop/RFID-US/erroraulas.log");
        watcher->addPath("/home/pi/Desktop/RFID-US/errorlector.log");
        watcher->addPath("/home/pi/Desktop/RFID-US/usuarioregistrado.log");
        watcher->addPath("/home/pi/Desktop/RFID-US/registro.xml");
        watcher->addPath("/home/pi/Desktop/RFID-US/oklector.log");
        watcher->addPath("/home/pi/Desktop/RFID-US/okconexion.log");
		watcher->addPath("/home/pi/Desktop/RFID-US/errorconexionregistro.log");
		watcher->addPath("/home/pi/Desktop/RFID-US/errorrecibido.log");
		watcher->addPath("/home/pi/Desktop/RFID-US/errordom2.log");
		watcher->addPath("/home/pi/Desktop/RFID-US/erroreneldom.log");
		watcher->addPath("/home/pi/Desktop/RFID-US/errorbbdd.log");
		watcher->addPath("/home/pi/Desktop/RFID-US/reintentarlector.log");
           } else {
        // QFile f(str);
        //f.open(QIODevice::ReadWrite);
        qDebug() << "Creamos el fichero " << str;
        watcher->addPath(str);
    }
}

void ControlPresencial::showModified(QString str)
{
    //Q_UNUSED(str);
    //QMessageBox::information(this, "Directory Modified", "Your Directory is modified");
    qDebug() << "DIRECTORIO MODIFICADO" << str;

    //ui->LabelError->setText(str.replace("/home/pi/Desktop/RFID-US/",""));

    if(str.contains("registr")){
		//El fichero contiene registro
        if(str.contains("registro.xml")){
			//Se esta registrando al usuario
            ui->LabelError->setText("Registrando usuario");
            qDebug() << "Registrando usuario" << QFile(str).exists();
            ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/Logo.gif);");
        }else {
		 //Hay error registrando al usuario o se ha registrado bien
		    if(str.contains("error")){
                ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/exclamation_mark.jpg);");
			     ui->LabelError->setText("Error registrando al usuario");
                 qDebug() << str;
				 QFile file(str); 
				 file.open(QIODevice::ReadOnly | QIODevice::Text);
                 QTextStream in(&file);
			     in.setCodec("UTF-8"); // change the file codec to UTF-8.
				 while(!in.atEnd())
				 {
					QString line = in.readLine();
					qDebug() << line;
					ui->LabelError->setText(line);
					//OR qDebug() << line.toLocal8Bit; None of these ways work
				 }	 
			}else {
				/*ui->LabelError->setText("Usuario registrado");
				qDebug() << "Usuario registrado" << QFile(str).exists();
				ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/Logo.gif);");
				//Y vemos el usuario que se ha registrado
				QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
				db.setHostName("localhost");
				db.setDatabaseName("BD_RFID");
				db.setPort(5432);
				db.setUserName("sinapse");
				db.setPassword("napse1si");
				if (!db.open()){
					qDebug() << "No conectado";
				} else{
					qDebug() << "Conectado";
			    }

				QSqlQuery queryaula(db);
				queryaula.exec("select l_nombre,l_documento,l_datetime from l_logregistros order by l_datetime desc LIMIT 1");

				while (queryaula.next())
				{
				qDebug() << "Los datos de la query son";
				qDebug() << queryaula.value(0).toString();
				qDebug() << queryaula.value(1).toString();
				qDebug() << queryaula.value(2).toString();
				ui->LabelError->setText(queryaula.value(0).toString().replace("D\xc3\xb1a.","Dna.") + " \n Fecha: " + queryaula.value(2).toString() );
*/

				std::ifstream fichero;
				fichero.open("/home/pi/Desktop/RFID-US/usuarioregistrado.log");

				if(fichero.is_open()){
					std::string linea;
					std::getline(fichero,linea);

					char c = linea[linea.length()-1];

					if(c == 'E'){
						QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
						db.setHostName("localhost");
						db.setDatabaseName("BD_RFID");
						db.setPort(5432);
						db.setUserName("sinapse");
						db.setPassword("napse1si");
						if (!db.open()){
							qDebug() << "No conectado";
						} else{
							qDebug() << "Conectado";
					    }

						QSqlQuery queryaula(db);
						queryaula.exec("select l_nombre,l_documento,l_datetime from l_logregistros order by l_datetime desc LIMIT 1");

						/*while (queryaula.next())
						{
							qDebug() << "Los datos de la query son";
							qDebug() << queryaula.value(0).toString();
						}*/

						queryaula.first();

						ui->LabelError->setText("Salida registrada para el usuario: \n"+ queryaula.value(0).toString());
					}else if(c == 'A'){
						QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
						db.setHostName("localhost");
						db.setDatabaseName("BD_RFID");
						db.setPort(5432);
						db.setUserName("sinapse");
						db.setPassword("napse1si");
						if (!db.open()){
							qDebug() << "No conectado";
						} else{
							qDebug() << "Conectado";
					    }

						QSqlQuery queryaula(db);
						queryaula.exec("select l_nombre,l_documento,l_datetime from l_logregistros order by l_datetime desc LIMIT 1");

						/*while (queryaula.next())
						{
							qDebug() << "Los datos de la query son";
							qDebug() << queryaula.value(0).toString();
						}*/

						queryaula.first();

						ui->LabelError->setText("Entrada registrada para el usuario: \n"+ queryaula.value(0).toString());
					}else{
						QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
						db.setHostName("localhost");
						db.setDatabaseName("BD_RFID");
						db.setPort(5432);
						db.setUserName("sinapse");
						db.setPassword("napse1si");
						if (!db.open()){
							qDebug() << "No conectado";
						} else{
							qDebug() << "Conectado";
					    }

						QSqlQuery queryaula(db);
						queryaula.exec("select l_nombre,l_documento,l_datetime from l_logregistros order by l_datetime desc LIMIT 1");

						/*while (queryaula.next())
						{
							qDebug() << "Los datos de la query son";
							qDebug() << queryaula.value(0).toString();
						}*/

						queryaula.first();

						ui->LabelError->setText(queryaula.value(0).toString());
					}
				}
				fichero.close();
			}

		}//Usuario registrado
//     } //Se ha terminado el intento de registro
     } else{
	 //El fichero no contiene registro
         if(str.contains("ok")){
		    if(str.contains("conexion")){ 
				qDebug() << "Es un OK" << QFile(str).exists();
				ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/Logo.gif);");
				//ui->LabelError->setText("Refrescada la lista de aulas");
			}else{
				qDebug() << "Es un OK" << QFile(str).exists();
				ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/Logo.gif);");
				ui->LabelError->setText("Sistema OK");
		}}else{
		    if(str.contains("lector")){
				qDebug() << "Hay algun error: " << QFile(str).exists();
				ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/exclamation_mark.jpg);");
                ui->LabelError->setText("Error con el lector. Vuelva a intentarlo");
			}else{
				if(str.contains("aula")) {
					qDebug() << "Hay algun error: " << QFile(str).exists();
					//ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/exclamation_mark.jpg);");
					//ui->LabelError->setText("No se ha recibido aula o se ha recibido mas de una. Contacte con el administrador del sistema para obtener la nueva ubicacion.");
				}else{
					if(str.contains("reintentar")){
					ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/exclamation_mark.jpg);");
					ui->LabelError->setText("Error leyendo tarjeta. Vuelva a pasar su tarjeta por el lector.");
					}else{
						if(str.contains("errorconexion")) {
							ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/Logo.gif);");
							ui->LabelError->setText("Error de conexion con el servidor remoto. Contacte con el administrador del sistema");
						}else{
							//No es un OK
							qDebug() << "Hay algun error: " << QFile(str).exists();
							ui->frame->setStyleSheet("border-image: url(:/new/es-resources/Resources/exclamation_mark.jpg);");
							ui->LabelError->setText("Error");
							QFile file(str); 
							file.open(QIODevice::ReadOnly | QIODevice::Text);
							QTextStream in(&file);
							in.setCodec("UTF-8"); // change the file codec to UTF-8.
							while(!in.atEnd())
							{
								QString line = in.readLine();
								qDebug() << line;
								ui->LabelError->setText("Error: " + line);
								//OR qDebug() << line.toLocal8Bit; None of these ways work
							}		 
						}
					}
				}
			}
		}
	}

MonitorizaFicheros(str);

}


void ControlPresencial::LimpiaError()
{
   // qDebug << "El valor de la etiqueta es; " << ui->LabelError->text().toStdString();
   // if (ui->LabelError->text().toStdString().contains("Nombre:")){
       ui->LabelError->setText("");
   // }
}

void ControlPresencial::showTime()
{
    QTime time=QTime::currentTime();
	QString time_text=time.toString("hh:mm:ss");
    if ((time.second() % 2) == 0)
	{
        time_text[2] = ' ';
		time_text[5] = ' ';
	}
	ui->Digitalclock->setText(time_text);
	
	QDateTime dateTime=QDateTime::currentDateTime();
    QString datetimetext=dateTime.toString("dd-MM-yyyy");
	ui->DateTime->setText(datetimetext);
}

void ControlPresencial::RellenaDatosAula()
{
     QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
     db.setHostName("localhost");
     db.setDatabaseName("BD_RFID");
     db.setPort(5432);
     db.setUserName("sinapse");
     db.setPassword("napse1si");
     if (!db.open()){
       qDebug() << "No conectado";
      } else{
       qDebug() << "Conectado";
           }

	 QSqlQuery queryaula(db);
      queryaula.exec("select ad_numserie,d_edificio,d_aula from a_deviceconfiguration INNER JOIN d_auladispositivo ON da_iddispositivo=ad_id INNER JOIN d_aulas ON da_idaula=d_id LIMIT 1");
     
      while (queryaula.next())
      {
	   qDebug() << "Los datos de la query son";
      qDebug() << queryaula.value(0).toString();
      qDebug() << queryaula.value(1).toString();
      qDebug() << queryaula.value(2).toString();
      ui->LabelDispositivo->setText("Dispositivo: " + queryaula.value(0).toString());
      ui->LabelEdificio->setText(queryaula.value(2).toString());
	  }
	  
	  QSqlQuery queryip(db);
      queryip.exec("SELECT ipdevice FROM a_serverconfigurations");
     
      while (queryip.next())
      {
	  qDebug() << "Los datos de la query son";
      qDebug() << queryip.value(0).toString();
      ui->LabelIP->setText("IP: " + queryip.value(0).toString());
	  }
	  
}

ControlPresencial::~ControlPresencial()
{
    delete ui;
}


