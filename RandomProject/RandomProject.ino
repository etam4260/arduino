/* Emmet-Tam
 *  
 */

namespace {
  const uint8_t DIGITAL_PIN_2 = 2;
  const uint8_t DIGITAL_PIN_3 = 3;
  const uint8_t DIGITAL_PIN_4 = 4;
  const uint8_t DIGITAL_PIN_5 = 5;
  unsigned long theTime = 0;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  theTime = millis();
  Serial.println(theTime);
}



