void setup(){
    pinMode(12,OUTPUT);
}

void loop(){
    digitalWrite(12, HIGH);
    delay(3000);
    digitalWrite(12, LOW);
    delay(3000);
}