void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.print("1");   // LED on
  delay(500);
  Serial.print("0");   // LED off
  delay(500);
}