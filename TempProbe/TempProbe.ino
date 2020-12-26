
/*
 Rx pin - 4
 Tx pin - 5
*/

#include<SoftwareSerial.h>

SoftwareSerial hc12(4,5);  //RX, TX

const int thermis = A0;     //thermistor input pin
int thermisInt;             //thermistor A/D value

const int led = 13;         //sets led to pin 13

const int chan0 = 8;        //two position DIP switch to determine probe channel
const int chan1 = 9;
int channelNumber = 0;


void setup()    {
  pinMode(led, OUTPUT);     //sets led as output
  digitalWrite(led,LOW);    //set the LED off
  
  pinMode(thermis, INPUT);  //sets thermistor pin as input
  Serial.begin(9600);       //starts console at 9600 bits per second
  hc12.begin(9600);         //start xcvr at 9600 baud
  hc12.listen();            //set radion to listen

  pinMode(chan0, INPUT);    //set probe channel pins to inputs
  pinMode(chan1, INPUT);

  if (digitalRead(chan0)) channelNumber++;
  if (digitalRead(chan1)) channelNumber = channelNumber + 2;
}


void loop() {
  Serial.print(channelNumber);
  if (hc12.available() > 0){                      //check for data received
    String channel = hc12.readStringUntil('\n');
    if (channel == String(channelNumber, DEC)){   //if this probe is queried send data
      digitalWrite(led,HIGH);
      thermisInt = analogRead(thermis);
      String thermisString = String(thermisInt, DEC);
      //Serial.println("Thermistor A/D value: " + thermisString);
      
      hc12.print(thermisString + "\n");
      digitalWrite(led,LOW);
    }
  }
}
