/*Emmet Tam
 *4-7 Segement
 *12/25/17 
 */
int a = 1111;
char c[4];
void setup() {
  Serial.begin(9600);
}//end of setup

void loop() {
if(sizeof(c) <= 4){
  itoa(a, c, 10);
  Serial.println(c);  
  int number = 0;
  for(int i = 2; i < 5; i++){
    digitalWrite(i, HIGH);
      if(c[number] == 0){
        zero();
      }else if(c[number] == 1){
        one();
      }else if(c[number] == 2){
        two();
      }else if(c[number] == 3){
        three();
      }else if(c[number] == 4){
        four();
      }else if(c[number] == 5){
        five();
      }else if(c[number] == 6){
        six();
      }else if(c[number] == 7){
        seven();
      }else if(c[number] == 8){
        eight();
      }else if(c[number] == 9){
        nine();
      }
  }
  number++;
  delay(100);
}//end of for loop
}//end of loop

void zero(){
  for(int i = 6; i < 12; i++){
    if(!(i == 12)){
    digitalWrite(i, HIGH);
    }
  }
}
void one(){
  for(int i = 6; i < 12; i++){
    if(i == 7 || i == 8){
    digitalWrite(i, HIGH);
    }
  }
}
void two(){
  for(int i = 6; i < 12; i++){
    if(!(i == 8 || i == 11)){
    digitalWrite(i, HIGH);
    }
  }
}
void three(){
  for(int i = 6; i < 12; i++){
    if(!(i == 10 && i == 11)){
    digitalWrite(i, HIGH);
    }
  }
}
void four(){
  for(int i = 6; i < 12; i++){
    if(!(i == 6 && i == 9 && i == 10)){
    digitalWrite(i, HIGH);
    }
  }
}
void five(){
  for(int i = 6; i < 12; i++){
    if(!(i == 7 && i == 10)){
    digitalWrite(i, HIGH);
    }
  }
}
void six(){
  for(int i = 6; i < 12; i++){
    if(!(i == 7)){
    digitalWrite(i, HIGH);
    }
  }
}
void seven(){
  for(int i = 6; i < 12; i++){
    if(i == 6 || i == 7 || i == 8){
    digitalWrite(i, HIGH);
    }
  }
}
void eight(){
  for(int i = 6; i < 12; i++){
    digitalWrite(i, HIGH);
  }
}
void nine(){
  for(int i = 6; i < 12; i++){
    if(!(i == 9 && i == 10)){
    digitalWrite(i, HIGH);
    }
  }
}

