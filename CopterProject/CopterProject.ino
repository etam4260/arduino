#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include <Wire.h>
#endif
#define OUTPUT_READABLE_ACCELGYRO
#define motorFrontRight A0
#define motorFrontLeft A1
#define motorBackRight A2
#define motorBackLeft A3
#define objectSensorFront 2
#define objectSensorBack 3
#define objectSensorRight 4
#define objectSensorLeft 5
#define gyroScope
#define tempModule 
#define LED_PIN 13
MPU6050 accelgyro;
const int MPU_addr = 0x68;
int16_t ax, ay, az;
int16_t gx, gy, gz;
bool blinkState = false;

void setup() {
 Wire.begin();
 Wire.beginTransmission(MPU_addr);
 Serial.begin(38400);
 Serial.println("Initializing I2C devices...");
 accelgyro.initialize();
 Serial.println("Testing device connections...");
 Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop() {
  accelgyro.getAcceleration(&ax, &ay, &az);
  accelgyro.getRotation(&gx, &gy, &gz);
  determinesensorStates(digitalRead(objectSensorFront), digitalRead(objectSensorBack), digitalRead(objectSensorRight), digitalRead(objectSensorLeft));
#ifdef OUTPUT_READABLE_ACCELGYRO
        Serial.print("a/g:\t");
        Serial.print(ax); Serial.print("\t");
        Serial.print(ay); Serial.print("\t");
        Serial.print(az); Serial.print("\t");
        Serial.print(gx); Serial.print("\t");
        Serial.print(gy); Serial.print("\t");
        Serial.println(gz); Serial.print("\n");
    #endif
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
    delay(1000);
}


 int determinesensorStates(int stateofdistanceFront,int stateofdistanceBack,int stateofdistanceRight,int stateofdistanceLeft){
  if(stateofdistanceFront == 0){
    Serial.println("Front Obstacle!");
  }
  if(stateofdistanceBack == 0){
    Serial.println("Back Obstacle!");
  }
  if(stateofdistanceRight == 0){
    Serial.println("Right Obstacle!");
  }
  if(stateofdistanceLeft == 0){
    Serial.println("Left Obstacle!");
  }
 }

