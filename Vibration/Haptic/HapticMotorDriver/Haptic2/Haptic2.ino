/*
Adafruit Arduino - Lesson 13. DC Motor
*/


int motorPin1 = 3;              // Want this to be scalable for up to 8 motors
unsigned long Time;             // Holder for time at the start of each cycle
int freq;

void setup() 
{ 
  pinMode(motorPin1, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 

void loop() {
  // put your main code here, to run repeatedly:
  for (freq = 0; freq <= 255; freq += 1)
  {
    analogWrite(motorPin1,freq);
    delay(1);
  }
    for (freq = 255; freq >= 0; freq -= 1)
  {
    analogWrite(motorPin1,freq);
    delay(8);
  }
}
