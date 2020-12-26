const int motorOne = A1;
const int motorTwo = A2;
const int motorThree = A3;
const int motorFour = A4;
const int potPin = A5;
double potVal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potVal = map(analogRead(potPin), 0, 1023, 0, 255);
  Serial.print("Speed: ");
  Serial.println(potVal);
  Serial.println("");
  analogWrite(motorOne, potVal);
  analogWrite(motorTwo, potVal);
  analogWrite(motorThree, potVal);
  analogWrite(motorFour, potVal);
  delay(200);
}
