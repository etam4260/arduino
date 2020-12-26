void setup() {
  Serial.begin(9600);
  pinMode(A7, OUTPUT);
}

void loop() {
  analogWrite(A7, 255);
  int sensorValue = analogRead(A7);
  analogWrite(A7, 255);
  Serial.println(sensorValue);
  delay(1000);
}
