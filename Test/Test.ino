#include "I2Cdev.h"
#include "MPU6050.h"
MPU6050 accelgyro;
void setup(){
  Serial.begin(9600);
}

void loop(){
Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}
