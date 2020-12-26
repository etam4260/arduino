char a = (char)(-101);
byte b = 123;
void setup() {
Serial.begin(9600);
}

void loop() {
Serial.println(a);
Serial.println(b);
Serial.println();
}
