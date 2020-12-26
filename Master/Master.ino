#include <Wire.h>
int state = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("I2C Master");
}

void loop() {
  delay(1000);
  Serial.println("Write something");
  Wire.beginTransmission(5);
  Wire.write(state);
  state++;
  Wire.endTransmission();

  Serial.println("Received data");

  Wire.requestFrom(5, 5);

  String response = "";
  while(Wire.available()){
    char b = Wire.read();
    response += b;
  }
  Serial.println(response);
}
