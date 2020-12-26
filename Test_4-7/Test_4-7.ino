const int D2 = D2, D3 = D3, D4 = D4, D5 = D5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  for(int i = 6; i < 12; i++){
    if(!(i == 12)){
    digitalWrite(i, HIGH);
    }
  }
}
