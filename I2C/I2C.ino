namespace {
  uint8_t SCK = A5;
  uint8_t SDA = A4;
  const uint8_t clockSignal = 10;
}

void setup() {
  PRR = PRR ^ (1 << 7);
  TWCR = (1<<TWINT)|(1<<TWSTA)|
  (1<<TWEN);
}

void loop() {
  // put your main code here, to run repeatedly:

}
