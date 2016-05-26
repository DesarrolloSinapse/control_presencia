Guia para actualización vía NTP:

1.- Mover script ActualizaNTP.sh a /etc/init.d/

2.- Editar el listado de servidores que aparecen en /etc/ntp.conf, 
añadiendo el que nos interese.

3.- Editar /etc/crontab añadiendo la siguiente línea :

0 */2 * * *	root	/etc/init.d/ActualizaNTP.sh

4.- Reiniciar el equipo