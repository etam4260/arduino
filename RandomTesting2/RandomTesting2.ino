void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(random(0,10));
  int x = pulseIn(2,HIGH,10000);
  byte y = shiftIn(2,3,LSBFIRST);
  Serial.println(x);
  Serial.println(y);
  tone(4,4500),500;
  interrupts();
  attachInterrupt(digitalPinToInterrupt(5),interrupt, CHANGE); 
  detachInterrupt(digitalPinToInterrupt(5));
  noInterrupts();
  delay(1000);
  Serial.println();
}

void interrupt(){
    int y = 10;
}

