#include <LiquidCrystal.h>
#define TRIG 8
#define ECHO 9

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// 라이브러리 예에서는 숫자가 내림차순으로 되어 있기에 같은순으로 구성함
// 12=Rs(레지스터 설정), 11=E(쓰기모드 활성화), 10=V0(글자대비값)=GND, 5=D4, 4=D6, 3=D7, 2=D8
// LCD기판에서는 우측 방향이 우노에서는 감소하는 방향이다.

void setup(){
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
lcd.begin(16,2);
}
// TRIG가 신호를 발사, ECHO는 반환된 신호를 받는다
// lcd.begin(세로,가로);

void loop(){
digitalWrite(TRIG, LOW);
delayMicroseconds(2);

digitalWrite(TRIG, HIGH);
delayMicroseconds(10);

digitalWrite(TRIG, LOW);
// delay를 주어서 신호를 처리할 충분한 시간을 준다

long distance = pulseIn(ECHO, HIGH)/58.2;
// 초음파 센서의 필수적인 함수 pulseIn(확인할 핀, 목표 상태값)이다.
// 58.2로 나누면 cm가 된다

lcd.clear();
// LCD 화면에 나오기 전에 전체를 백지장으로 만든 다음에 이후에 그리기
lcd.setCursor(0,0);
// PRINT되는 문자열의 커서위치
lcd.print(distance);
lcd.print("cm");
delay(200);
// 글자가 유지되는 시간을 0.2초로 부여한다.
}