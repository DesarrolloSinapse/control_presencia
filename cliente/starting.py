import os
import psycopg2
import sys

def main():
    con = psycopg2.connect(host='localhost', database='BD_RFID', user='sinapse', password='napse1si')
    cur = con.cursor()
    query = "SELECT ipdevice,networkmask,gateway,dns1 FROM a_serverconfigurations"
  
    cur.execute(query) 
    resultado = cur.fetchone()
    ipdevice=str(resultado[0]) 
    networkmask=str(resultado[1])
    gateway=str(resultado[2])
    dns1=str(resultado[3])
    # This will create a new file or **overwrite an existing file**.
    f = open("/etc/network/interfaces", "w")
    f.write("auto lo\n iface lo inet loopback\n allow-hotplug wlan0\n iface wlan0 inet manual\n wpa-roam /etc/wpa_supplicant/wpa_supplicant.conf\n iface eth0 inet static\n    address " + ipdevice + "\n    netmask " + networkmask + "\n    gateway " +  gateway + "\n      dns-nameservers " + dns1 ) # Write a string to a file
	
    f.close()

    #os.system("sudo sed -i 'auto lo\n iface lo inet loopback\n iface eth0 inet dhcp\n allow-hotplug wlan0\n iface wlan0 inet manual\n wpa-roam /etc/wpa_supplicant/wpa_supplicant.conf\n iface eth0 inet static\n     address " + ipdevice + "\n    netmask " + netmask + "\n    gateway " +  gateway + "' /etc/network/interfaces")
    os.system("sleep 10")
    os.system("sudo reboot")

if __name__=="__main__":
   main()
