#define objectSensorFront 2
#define objectSensorBack 3
#define objectSensorRight 4
#define objectSensorLeft 5
void setup() {
 Serial.begin(9600);
}

void loop() {
 determinesensorStates(digitalRead(objectSensorFront), digitalRead(objectSensorBack), digitalRead(objectSensorRight), digitalRead(objectSensorLeft));
 delay(300);
}

int determinesensorStates(int stateofdistanceFront,int stateofdistanceBack,int stateofdistanceRight,int stateofdistanceLeft){
  if(stateofdistanceFront == 0 || stateofdistanceBack == 0 || stateofdistanceRight == 0 || stateofdistanceLeft == 0){
  Serial.println("OBSTACLE!"); 
  }
 }

