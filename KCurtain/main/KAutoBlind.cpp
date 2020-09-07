#include "KAutoBlind.h"

int KAutoBlind::ReadSwitch()
{
  bool swUpPushed = digitalRead(SWUP);
  bool swDownPushed = digitalRead(SWDOWN);
  bool swFunctionPushed = digitalRead(SWFUNCTION);
}

int KAutoBlind::ConnectToServer()
{
  Serial.print("ConnectToServer...");
  return -1;
}

void KAutoBlind::ChangeOperateState(enumOperationState state)
{
  Serial.print("Change Operate State : ");
  Serial.print(operationState);
  Serial.print("->");
  Serial.println(state);

  operationState = state;
}

void KAutoBlind::LEDOn()
{
  if (digitalRead(LED) == LOW)
  {
    digitalWrite(LED, HIGH);
    ledState = true;
    ledOnTime = millis();
    Serial.println("LED On");
  }
}

void KAutoBlind::LEDOff()
{
  if (digitalRead(LED) == HIGH)
  {
    digitalWrite(LED, LOW);
    ledState = false;
    ledOffTime = millis();
    Serial.println("LED Off");
  }
}

void KAutoBlind::LEDBlink()
{
  unsigned long curTime = millis();
  Serial.println("LED Blink");

  if (ledState == true)
  {
    if (curTime - ledOnTime > LEDBLINKTIME)
    {
      LEDOff();
    }
  }
  else if (ledState == false)
  {
    if (curTime - ledOffTime > LEDBLINKTIME)
    {
      LEDOn();
    }
  }
}

int KAutoBlind::CW()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

int KAutoBlind::CCW()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

int KAutoBlind::ManualOpen()
{
  CW();
}

int KAutoBlind::ManualClose()
{
  CCW();
}

bool KAutoBlind::IsOpened()
{
  int state = digitalRead(SENSOROPEN);
  if (state == HIGH)
    return true;
  else
    return false;
}

int KAutoBlind::OpenBlind()
{
  Serial.println("Open Blind...");

  if (IsOpened() == false)
  {
    CW();
  }

  Serial.println("Blind Open is Finished");

  return -1;
}

bool KAutoBlind::IsClosed()
{
  int state = digitalRead(SENSORCLOSE);
  if (state == HIGH)
    return true;
  else
    return false;
}

int KAutoBlind::CloseBlind()
{
  Serial.println("Close Blind...");

  if (IsClosed() == false)
  {
    CCW();
  }

  Serial.println("Blind Close is Finished");
  return -1;
}

int KAutoBlind::StopBlind()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.println("Blind Stop is Finished");
  return -1;
}

bool KAutoBlind::IsSWUpPushed()
{
  if (digitalRead(SWUP) == HIGH)
  {
    if (swUpPushed == LOW)
    {
      swUpPushed = HIGH;
      swUpPushedTime = millis();
      Serial.println("Up Switch is Pushed.");
    }
    return true;
  }

  return false;
}

bool KAutoBlind::IsSWDownPushed()
{
  if (digitalRead(SWDOWN) == HIGH)
  {
    if (swDownPushed == LOW)
    {
      swDownPushed = HIGH;
      swDownPushedTime = millis();
      Serial.println("Down Switch is Pushed.");
    }
    return true;
  }

  return false;
}

bool KAutoBlind::IsSWFunctionPushed()
{
  if (digitalRead(SWFUNCTION) == HIGH)
  {
    if(swFunctionPushed == LOW)
    {
      swFunctionPushed = HIGH;
      swFunctionPushedTime = millis();
      Serial.println("Power Switch is Pushed.");
    }
    return true;
  }

  return false;
}

bool KAutoBlind::IsSWFunctionLongPushed()
{
  bool curState = digitalRead(SWFUNCTION);

  if(swFunctionPushed == HIGH && curState == HIGH)
  {
    unsigned long curTime = millis();
    if (curTime - swFunctionPushedTime> LONGPUSHTIME)
    {
      Serial.println("Function Switch is Long Pushed.");
      return true;
    }
  }

  return false;
}

extern KAutoBlind Blind;
