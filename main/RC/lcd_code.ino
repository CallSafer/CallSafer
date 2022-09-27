#include <Ultrasonic.h>         //HC-SR04 초음파센서 라이브러리를 사용합니다. 
Ultrasonic sensor(9, 8, 30000); // (Trig핀, Echo핀, 최대거리 단위는 us) 즉 30000us = 약 5미터 

#include <LiquidCrystal.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup()
{
  lcd.begin();
  lcd.backlight();

  pinMode(trigPin, OUTPUT); // 센서 Trig 핀
  pinMode(echoPin, INPUT);  // 센서 Echo 핀
}

void loop()
{
  digitalWrite(trigPin, HIGH);  // 센서에 Trig 신호 입력
  delayMicroseconds(10);        // 10us 정도 유지
  digitalWrite(trigPin, LOW);   // Trig 신호 off

  long duration = pulseIn(echoPin, HIGH);    // Echo pin: HIGH->Low 간격을 측정
  long distance = duration / 29 / 2;         // 거리(cm)로 변환

  char buf[20];
  snprintf(buf, sizeof(buf), "Distance %4d cm", distance);
  lcd.setCursor(0, 0);
  lcd.println(buf);

  delay(200);
}