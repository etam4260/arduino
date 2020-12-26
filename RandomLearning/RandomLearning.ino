namespace{
  uint8_t angle = 90;
  uint8_t distance = 0;
  uint8_t adjacentDistance = 0;
  uint8_t oppositeDistance = 0;
  uint8_t hypotenuseDistance = 0;
  volatile uint8_t foundIt = 0;
  const uint8_t SPEED_OF_BOT = 10; 
  uint8_t * heapptr, * stackptr;
}
   
void setup() {
  //Sets pins 9-13 as output pins and 8 as an input.
  DDRB = B00111110;
  //Sets pin 8 to pulldown;
  PORTB = B00000000; 
  //Sets the interrupt pins 2 and 3 to trigger on RISING edge;
  EICRA = B00000101;
  //Activates the interrupt pins 2 and 3
  EIMSK = B00000011;
  //Enables global interrupts;
  sei();
  Serial.begin(9600);
}

void loop() {
  Serial.println("Next move it!");
  check_mem();
  Serial.print("Stack "); Serial.println((int)stackptr);
  Serial.print("Heap "); Serial.println((int)heapptr);
  Serial.println();
  if (foundIt){
    scanTheAreaAndCalculateAndMove;
    foundIt = 0;
  } else {
    moveSinceNothingFound();
  }
  delay(1000);
}

void scanTheAreaAndCalculateAndMove(uint8_t &angle, uint8_t &distance, uint8_t &adjacentDistance, uint8_t &oppositeDistance) {
  //Use some sensors to find the angle and distance
  PORTC |= B00000000;
  delay(10);
  PORTC |= B00000001;
  delay(10);
  PORTC ^= B00000001;

  hypotenuseDistance = (pulseIn(10, HIGH)*0.034)/2;
  delay(10);
  
  //Do some calculations to find the distances bot needs to travel straight and to either the left or right

  //Turn on all motors to move forward
  PORTB |= B00011110;
  //Determine the amount of time needed to travel certain distance
  delay(1000 * (adjacentDistance/SPEED_OF_BOT));
  //Turn off motors when distance is reached
  PORTB ^= B00011110;

  //Some method of turning the bot 
  PORTB |= B00000110;
  delay(2000);
  PORTB ^= B00000110;

  //Turn on all motors to move forward
  PORTB |= B00011110;
  //Determine the amount of time needed to travel certain distance
  delay(1000 * (oppositeDistance/SPEED_OF_BOT));
  //Turn off motors when distance is reached
  PORTB ^= B00011110;
  delay(1000);
}

void moveSinceNothingFound() {
  PORTB |= B00011110;
  delay(1000);
  PORTB ^= B00011110;
}

//Interrupt service routine for pin 2
ISR(INT0_vect) {
  foundIt = 1;
}


/* This function places the current value of the heap and stack pointers in the
* variables. You can call it from any place in your code and save the data for
* outputting or displaying later. This allows you to check at different parts of
* your program flow.
* The stack pointer starts at the top of RAM and grows downwards. The heap pointer
* starts just above the static variables etc. and grows upwards. SP should always
* be larger than HP or you'll be in big trouble! The smaller the gap, the more
* careful you need to be. Julian Gall 6-Feb-2009.
*/
void check_mem() {
  stackptr = (uint8_t *)malloc(4);  // use stackptr temporarily
  heapptr = stackptr;                  // save value of heap pointer
  free(stackptr);                        // free up the memory again (sets stackptr to 0)
  stackptr =  (uint8_t *)(SP);       // save value of stack pointer
}


