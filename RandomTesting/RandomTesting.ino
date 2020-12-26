String string1 = String(13);
String string2 = String(45, HEX);
String string3 = String(255, BIN);
String string4 = String(5.69428, 3);
String string5 = String(34.241, DEC);
String string6 = String("Hello");
String string7 = String("He");
String string8 = String(123.123);



void setup() {
  Serial.begin(9600);
}

void loop() {
  String string9 = String("Hello     my      bro           ");
  string9.trim();
  Serial.println(string1);
  Serial.println(string2);
  Serial.println(string3);
  Serial.println(string4);
  Serial.println(string5);
  Serial.println(string6.endsWith("o"));
  string6.c_str();
  Serial.println(string6.lastIndexOf("l", 4));
  Serial.println(string6.startsWith(string7));
  Serial.println(string1.toFloat());
  Serial.println(string8.toInt());
  Serial.println(string9);
  Serial.println();
  Serial.println();
  delay(1000);
}
