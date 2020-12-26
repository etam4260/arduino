#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  
  if(mySerial.available() > 1){
    
    String input = mySerial.readString();//read string
    Serial.println(input);
    
    String first4 = input.substring(0,4);//first 4 characters
    Serial.println(first4);
    
    String last = input.substring(4);//all characters after the 4th character
    Serial.println(last);
    
    int integer = last.toInt();//Convert to integer
    Serial.println(integer);
  }
  delay(20);
}
