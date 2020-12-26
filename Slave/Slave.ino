#include <Wire.h>

String answer = "Cheek";
void setup() {
  Wire.begin(5);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Serial.println("I2C Slave");
}


void loop() {
delay(1000);
}

void receiveEvent(int byteCount){
  while(0 < Wire.available()){
    byte x = Wire.read();
    if(x%2 == 0) {
      digitalWrite(3, HIGH);
    } else {
      digitalWrite(3, LOW);
    }
  }
  Serial.println("Receive Event");
}

void requestEvent() {
  byte response[5];
  for(byte i = 0; i < 5; i++){
    response[i]= (byte)answer.charAt(i);
  }
  Wire.write(response, sizeof(response));
  Serial.println("Request the Event");
}
