#include "KAutoBlind.h"
#include "stdio.h"

KAutoBlind Blind;

void setup()
{

  Serial.begin(9600);
  Serial.println("KAutoBlind is Started");

  //WiFi.init(&Serial1);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SWUP, INPUT);
  pinMode(SWDOWN, INPUT);
  pinMode(SWFUNCTION, INPUT);
  pinMode(SENSOROPEN, INPUT);
  pinMode(SENSORCLOSE, INPUT);

  //Wifi.begin(SSID, PASS); // SSID, PW

  Serial.print("Connecting");
  //while(Wifi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();

  Serial.print("Connected, IP address : ");
  //Serial.println(Wifi.localIO());

  // server.on("/up", Open);
  // server.on("/down", Close);

  // server.begin();
  analogWrite(EN1, 0);

  Blind.ChangeOperateState(INITIAL);
}

void loop()
{
  Blind.ReadSwitch();

  if(Blind.IsSWFunctionPushed())
  {
    Blind.StopBlind();
  }
  else if(Blind.IsSWFunctionLongPushed())
  {
    //Power Off
  }
  else if(Blind.IsSWFunctionPushed() && Blind.IsSWUpPushed())
  {
    Blind.ManualOpen(); 
  }
  else if(Blind.IsSWFunctionPushed() && Blind.IsSWDownPushed())
  {
    Blind.ManualClose();
  }
  else if (Blind.IsSWUpPushed() && operationState == STOP)
  {
    Blind.OpenBlind();
  }
  else if (Blind.IsSWDownPushed() && operationState == STOP)
  {
    CloseBlind();
  }
}