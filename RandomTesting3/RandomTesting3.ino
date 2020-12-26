String inputString = "";
unsigned char myChar = 'j';
byte bet = 'j';
String met = "Herro";
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(50);
  Serial.write(5);
  Serial.write(100);
  Serial.println();
  Serial.println(bet);
  Serial.println(myChar);
  Serial.println(sizeof(bet));
  Serial.println(sizeof(myChar));
    Serial.println(sizeof(met));
  Serial.write("hello");
  if(Serial){
    Serial.println("Hi");
    Serial.println();
  }
  delay(1000);
}



