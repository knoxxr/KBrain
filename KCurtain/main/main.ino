#define IN1 3
#define IN2 4
#define EN1 2
#define SWUP 7
#define SWDOWN 8
#define SWPOWER 10
#define LED 9
#define MAXSPD a255
#define ACC 1
#define SSID "sugarmanwork1"
#define PASS "sugarmanwork_1"

bool swPowerPushed = false;
bool swUpPushed = false;
bool swDownPushed = false;
bool ledState = false;

unsigned long swPowerPushedTime;
unsigned long swUpPushedTime;
unsigned long swDownPushedTime;
unsigned long ledOnTime;
unsigned long ledOffTime;
unsigned long LONGPUSHTIME = 10000;
unsigned long LEDBLINKTIME = 1000;

char ssid[] = "SK_WiFiGIGAC266"; // your network SSID (name)
char pass[] = "1905000676";      // your network password
int curspd = 0;

void setup()
{

  Serial.begin(9600);
  Serial.println("KBlind is Started");

  //WiFi.init(&Serial1);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SWUP, INPUT);
  pinMode(SWDOWN, INPUT);
  pinMode(SWPOWER, INPUT);

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
}

void loop()
{
  ReadSwitch();
}

/* -----------------------------------------------------*/
/*                         Method                       */
/* -----------------------------------------------------*/
int ReadSwitch()
{
  bool swUp = digitalRead(SWUP);
  bool swDown = digitalRead(SWDOWN);
  bool swPower = digitalRead(SWPOWER);

  if(IsSWUpPushed())
  {

  }
  else if (IsSWDownPushed())
  {
  }
  
}

int ConnectToServer()
{
  Serial.print("ConnectToServer...");
  return -1;
}

void LEDOn()
{
  if (digitalRead(LED) == LOW)
  {
    digitalWrite(LED, HIGH);
    ledState = true;
    ledOnTime = millis();
    Serial.println("LED On");
  }
}

void LEDOff()
{
  if (digitalRead(LED) == HIGH)
  {
    digitalWrite(LED, LOW);
    ledState = false;
    ledOffTime = millis();
    Serial.println("LED Off");
  }
}

void LEDBlink()
{
  unsigned long curTime = millis();

  if (ledState == true)
  {
    if (curTime - ledOnTime > LEDBLINKTIME)
    {
      Serial.println("LED Blink");
      LEDOff();
    }
  }
  else if (ledState == false)
  {
    if (curTime - ledOffTime > LEDBLINKTIME)
    {
      Serial.println("LED Blink");
      LEDOn();
    }
  }
}

bool IsOpened()
{
  return false;
}

int OpenBlind()
{
  Serial.println("Open Blind...");

  if (IsOpened() == false)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }

  Serial.println("Blind Open is Finished");

  return -1;
}

bool IsClosed()
{
  return false;
}
int CloseBlind()
{
  Serial.println("Close Blind...");

  if (IsClosed() == false)
  {
  }

  Serial.println("Blind Close is Finished");
  return -1;
}

int StopBlind()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.println("Blind Stop is Finished");
  return -1;
}

bool IsSWUpPushed()
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

bool IsSWDownPushed()
{
  if (digitalRead(SWDOWN) == HIGH)
  {
    if (swDownPushed == LOW)
    {
      swDownPushedTime = HIGH;
      swDownPushedTime = millis();
      Serial.println("Down Switch is Pushed.");
    }
    return true;
  }

  return false;
}

bool IsSWPowerLongPushed()
{
  bool curState = digitalRead(SWPOWER);

  if (swPowerPushedTime == HIGH && curState == HIGH)
  {
    unsigned long curTime = millis();
    if (curTime - swPowerPushedTime > LONGPUSHTIME)
    {
      Serial.println("Power Switch is Long Pushed.");
      return true;
    }
  }

  return false;
}