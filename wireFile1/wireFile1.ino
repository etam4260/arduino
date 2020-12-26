#include <Wire.h>
const int potPin = A0; 
const int potPin2 = A1;
void setup(){
Wire.begin();
Serial.begin(9600);
}
byte x = 0;

void loop() {
  int potVal = map(analogRead(potPin), 0, 1023, 0, 255);
  int potVal2 = map(analogRead(potPin2), 0, 1023, 0, 255);
  Serial.println(potVal);
  Serial.println(potVal2);
  Wire.beginTransmission(8);
  Wire.write("Value: ");
  Wire.write(potVal);
  Wire.endTransmission();
  Wire.beginTransmission(8);
  Wire.write("Value: ");
  Wire.write(potVal2);
  Wire.endTransmission();
  
  delay(500);
}

