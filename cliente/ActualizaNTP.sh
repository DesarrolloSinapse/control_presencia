#! /bin/sh 
# /etc/init.d/ActualizaNTP.sh

### BEGIN INIT INFO 
# Provides:          ActualizaNTP 
# Short-Description: Simple script to update system clock via ntp 
### END INIT INFO 

nptd -gq
echo "Se actualiza la hora" 
