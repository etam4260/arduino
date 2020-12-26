#include <EEPROM.h>
#include <avr/pgmspace.h>
unsigned char bits[8] = {};

void setup() {
  Serial.begin(9600);
  DDRD = B00000001;
}
void loop() {
    byte z = PIND;
    Serial.println(PIND, 2);
    Serial.println(z);
    digitalWrite(7, HIGH);
    bits[0] = z >> 7 & B00000001;
    bits[1] = z >> 6 & B00000001;
    bits[2] = z >> 5 & B00000001;
    bits[3] = z >> 4 & B00000001;
    bits[4] = z >> 3 & B00000001;
    bits[5] = z >> 2 & B00000001;
    bits[6] = z >> 1 & B00000001;
    bits[7] = z%2;
    for(int i = 0; i < 8; i++){
      Serial.print(bits[i]);
    }
    Serial.println();
    Serial.println();
    delay(2000);
}



