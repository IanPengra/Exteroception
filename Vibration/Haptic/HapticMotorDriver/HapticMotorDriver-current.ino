/*
Adafruit Arduino - Lesson 13. DC Motor
*/


int motorPin1 = 3;              // Want this to be scalable for up to 8 motors
unsigned long Time;             // Holder for time at the start of each cycle
int freq;
int period;

void setup() 
{ 
  pinMode(motorPin1, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
//    for (freq = 0; freq <= 400; freq += 1)
      int freq = 100;                         //Serial.parseInt();       // Store the desired frequency
      if (freq >= 0 && freq <= 255)       // Arbitrary constraints - this is the range of frequencies I allow
      {
        int period = 1000/freq;  
          digitalWrite(motorPin1, HIGH);
        Time = millis();                  // Period of one full cycle (1 HIGH phase + 1 LOW phase)
//        while (millis()<500000)            // Go for 500 seconds
//        {
//          if (millis()-Time<period/2)
//          {
//            digitalWrite(motorPin1, HIGH);
//          }
//          else if (millis()-Time>=period/2 && millis()-Time<period)
//          {
//            digitalWrite(motorPin1, LOW);
//          }
//          else if (millis()-Time>=period)
//          {
//            Time = millis();
//          }
//        }
      }
    }
}
