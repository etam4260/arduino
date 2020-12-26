
#include <VirtualWire.h>          //calls the library

const int pot = A0;         // sets potentiometer pin to A0
int potInt;                   //sets a new value that is based off the potentiometer value
const int led = 2;          //sets led to pin 2


void setup()    {
pinMode(led, OUTPUT);     //sets led as output

pinMode(pot, INPUT);      //sets potentiometer as input
Serial.begin(9600);       //starts console at 9600 bits per second
vw_set_tx_pin(7);         //part of the Virtualwire library that sets the transmitter pin to 7
vw_setup(2000);           //starts a virtual wire that sends at 2000 bits per second
}


void loop() {
char potString[4];                              //sets a four char string
potInt = analogRead(pot);
itoa(potInt, potString, 10);                    //converts pot A/D value to 0 to 1024 char string
Serial.print(potString);                       
Serial.print("\n");                         
digitalWrite(led, HIGH);                              //sets the LED on
vw_send((uint8_t *) potString, strlen(potString));    //xmit char string with virtual wire library
vw_wait_tx();                                         //waits until all data is received
digitalWrite(led,LOW);    //set the LED off
delay(200);
}
