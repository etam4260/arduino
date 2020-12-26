#include <VirtualWire.h>


const int led = 2;

void setup() {
 Serial.begin(9600);
 pinMode(led, OUTPUT);
 vw_setup(2000);
 vw_set_rx_pin(7);
 vw_rx_start();
}

void loop() {
 digitalWrite(led, LOW);
 uint8_t buf[VW_MAX_MESSAGE_LEN];
 uint8_t buflen = VW_MAX_MESSAGE_LEN;
 if (vw_get_message(buf,&buflen)){
  int i;
  digitalWrite(led, HIGH);
  Serial.print("String: ");
  String string = (char*)buf;   //convert hex buffer to string
  Serial.print(string);
  Serial.print("\n");
  digitalWrite(led, LOW);
  memset(buf, 0, sizeof(buf));
 }

}
