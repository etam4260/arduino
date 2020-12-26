char str[4];

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  int i = 0;
  if(Serial1.available()) {
    delay(100);
    while(Serial1.available() && i<4) {
      str[i++] = Serial1.read();
    }
    str[i++]= '\0';
  }
 if(i>1){
  Serial.println(str,4);
 }
}
