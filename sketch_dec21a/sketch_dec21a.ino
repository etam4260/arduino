int r;
int b;
int g;
void setup() {
 Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A3));
  Serial.println(map (analogRead(A4), 0, 1023, 0, 255));
 if(analogRead(A3) < 341 ){
   digitalWrite(3, HIGH);
   r = map (analogRead(A4), 0, 1023, 0, 255);
 } else {
   digitalWrite(3, LOW);
 }
 if(analogRead(A3) > 341 && analogRead(A3) < 682 ){
   digitalWrite(4, HIGH);
   b = map (analogRead(A4), 0, 1023, 0, 255 );
 } else {
   digitalWrite(4, LOW);
 }
 if(analogRead(A3) > 682 && analogRead(A3) <= 1023 ){
   digitalWrite(5, HIGH);
   g = map (analogRead(A4), 0, 1023, 0, 255 );
 } else {
   digitalWrite(5, LOW);
 }
 analogWrite(A0, r);
 analogWrite(A1, b);
 analogWrite(A2, g);
}
