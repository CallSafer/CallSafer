#include <ControlMotor.h>               //모터제어 라이브러리를 사용합니다. 
                                        // 아두이노 보드에서 사용할 핀을 설정합니다. 
ControlMotor control(2, 3, 7, 4, 5, 6); // 우측모터1,우측모터2,좌측모터1,좌측모터2,우측PWM,좌측PWM 
 
#include <Ultrasonic.h>         //HC-SR04 초음파센서 라이브러리를 사용합니다. 
Ultrasonic sensor(9, 8, 30000); // (Trig핀, Echo핀, 최대거리 단위는 us) 즉 30000us = 약 5미터 
 
#include <SoftwareSerial.h> //블루투스 제어 라이브러리 
 
int Tx = 12;                     //전송 보내는핀  (블루투스) 
int Rx = 13;                     //수신 받는핀    (블루투스) 
SoftwareSerial BtSerial(Tx, Rx); // BTSerial 객체를 만들과 초기화 
 
int mesurement_speed = 5; //센서 측정 속도를 조정합니다. 
long int distance = 0;    //거리를 저장할 변수를 선언합니다. 
int random_value = 0;     //랜덤값을 저장합니다. 
char val = '0'; 
 
void setup() 
{ 
  Serial.begin(9600);    //시리얼포트를 초기화합니다. 
  BtSerial.begin(9600);  // 블루투스센서 초기화. 
  Serial.println("Start"); // 연결 시 문구 
} 
 
void loop() 
{ 
  // put your main code here, to run repeatedly: 
  if (BtSerial.available())
  { 
    val = BtSerial.read(); 
    Serial.write(BtSerial.read()); // 블루투스에서 읽어라. 읽은 정보를 시리얼에 출력 
  } 
  if (Serial.available()) 
  { 
    BtSerial.write(Serial.read()); 
  } 
  if (val == '1') 
  { 
    control.Motor(300, 1);         // 150의 속도로 자동차가 전진합니다. 
    distance = sensor.Ranging(CM); //거리를 측정하고 distance 변수에 저장합니다. 
    MotorCode(); 
  } 
  else if (val == '0') 
  { 
    control.Motor(0, 1); 
  } 
} // 블루투스 센서 

void MotorCode() 
{ 
  delay(mesurement_speed); //센서측정 속도를 제어하기 위한 딜레이. 
 
  //다음은 장애물이 없는 경우에 해당합니다. 
  random_value = random(2); //자동차가 한쪽 방향으로만 회전하는 것을 막기 위해 랜덤값을 만듭니다. 
 
  while (distance < 50) 
  { //장애물과의 거리가 30cm이하일 경우에 적용됩니다. 
 
    delay(mesurement_speed); //센서측정 속도를 제어하기 위한 딜레이. 
                             // control.Motor(0,1);//모터를 정지시킵니다. 
    distance = sensor.Ranging(CM); 
 
    if (random_value == 0) // 랜덤값이 0인경우에 해당됩니다. 
    { 
      MotorRight(); 
    } 
 
    else if (random_value == 1) //랜덤값이 1인경우에 해당됩니다. 
    { 
      MotorLeft(); 
    } 
  } 
} 

void MotorRight() 
{ 
  control.Motor(130, 100);      //자동차가 0.4초동안 오른쪽으로 회전합니다. 
  delay(200); 
} 
 
void MotorLeft() 
{ 
  control.Motor(130, -100);     //자동차가 0.4초동안 왼쪽으로 회전합니다. 
  delay(200); 
}