#include <SimpleDHT.h>

SimpleDHT11 dht11;
int pinDHT11 = 2;
int pinSoil = A0;
int pinPowerMoist = 7;
int moisture[12] = {};
int temperature[12] = {};
int humidity[12] = {};
int i = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  // start working...
  Serial.println("Sample DHT11...");
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
  }
  Serial.println("");
  Serial.print("Sample RAW Bits: ");
  for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);
    if (i > 0 && ((i + 1) % 4) == 0) {
      Serial.print(' ');
    }
  }
  Serial.println("");
  Serial.print("Sample OK: ");
  int t = (int)temperature; 
  int h = (int)humidity;
  Serial.print(t); Serial.print(" *C, ");
  Serial.print(h); Serial.println(" %");
  Serial.print("Soil Moisture: ");
  readMoisture();
  printMData();
  delay(2000);
}

void readMoisture()
{
  digitalWrite(pinPowerMoist ,HIGH);
  delay(100);
  if(i < 12){
  moisture[i] = analogRead(pinSoil);
  Serial.println(moisture[i]);
  i++;
  } else {
  int v = calcAvg(moisture);
    for(int i = 0; i < 12; i++){
      moisture[i] = 0;
    }
  i = 0;
  moisture[i] = analogRead(pinSoil);
  Serial.println(moisture[i]);
  Serial.print("AvgMoisture: ");
  Serial.println(v);
  i++;  
  }
  digitalWrite(pinPowerMoist ,LOW);
}
void printMData()
{
    Serial.print("Moisture Data: ");
  for(int i = 0; i < sizeof(moisture)/2; i++){
    Serial.print("[");
    Serial.print(moisture[i]);
    Serial.print("]");
  }
  Serial.println();
}

double calcAvg(int z[])
{
  int total = 0;
  for(int i = 0; i < 12; i++){
     total = total + z[i];   
  }
  return total/12;
}



