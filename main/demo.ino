void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  }

void loop()
{
  digitalWrite(13, !(digitalRead(13)));
    Serial.println("aaa");
  delay(500);

  }