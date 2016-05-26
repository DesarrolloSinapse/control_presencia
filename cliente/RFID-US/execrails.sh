#!/bin/sh
cd /home/pi/Desktop/RFID-US
su pi | rails s -b $1 -p 3000 > /home/pi/Desktop/rails_server.log 2>&1 &
