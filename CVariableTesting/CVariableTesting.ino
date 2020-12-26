namespace{ //space to declare constants and final and #defines. Protects leaking into other areas/ files.
  
}

auto z = false; // auto keyword allows C to determine the best type. Type can't be changed onced defined.

using fp = void(*)(int, const char*); //fp is a pointer to a function that takes an int and char parameter

auto res = nullptr;

int8_t bb = 3; //Can now specify integer sizes

assert(bb == 3); //Used to set bounds or debug 

boolean a = 6;
char b = 'c';
unsigned char c = 'b'; 
byte d = 255; //Smallest in terms of numbers
int e = 32000;  //Same as short and word
unsigned int f = -1;
word g = -1; //Same as short and int
long h = 323224; //Largest integers
unsigned long i = -10; //Largest integers
short j = 32000;   //Same as word and int
float k = 13.4212343255; //Same as double
double l = 13.343255325; //Same as float

char ab = (char)a;
unsigned char ba = (char)a;
byte bc = c;
byte cb = b;
byte cd = a;

int gc = d;


void setup() {
  Serial.begin(9600);
  gc = a;
  gc = b;
  gc = c;

  
}

void loop() {
  Serial.println(ab);
  Serial.println(ba);
  Serial.println(bc);
  Serial.println(cd);
  Serial.println(cb);
  Serial.println(gc);
  Serial.println(f);
  Serial.println(g);
  Serial.println(i);
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  delay(2000);
}
