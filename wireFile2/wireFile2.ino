#include <Wire.h>

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}
void loop() {
  delay(100);
}
void receiveEvent(int justaNumber) {
  while (1 < Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  int x = Wire.read();
  Serial.println(x);
  while (1 < Wire.available()) {
    char d = Wire.read();
    Serial.print(d);
  }
  int y = Wire.read();
  Serial.println(y);
}

