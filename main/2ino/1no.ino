void setup(){
  Serial.begin(9600);
  Serial.print("Start");
}

void loop(){
  if(Serial.available()){
   char c = (char)Serial.read();
    if(c == '1') {
      Serial.print("YES");
    } else {
      Serial.print("NO");
    }
  }  
}