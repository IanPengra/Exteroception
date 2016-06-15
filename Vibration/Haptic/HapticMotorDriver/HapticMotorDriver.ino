/*
Adafruit Arduino - Lesson 13. DC Motor
*/


int motorPin1 = 3;              // Want this to be scalable for up to 8 motors
unsigned long Time;             // Holder for time at the start of each cycle
unsigned long period = 10000;
unsigned long HIGHperiod = period / 2;
unsigned long diff;

void setup()
{
  pinMode(motorPin1, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
}


void loop()
{
  digitalWrite(motorPin1, HIGH);
  Time = micros();                  // Period of one full cycle (1 HIGH phase + 1 LOW phase)
  Serial.println("Initial Time: ");
  Serial.print(Time);
  
  while (millis() < 100000)
  {
    if (micros() - Time < HIGHperiod)
    {
      digitalWrite(motorPin1, HIGH);
      Serial.println("HIGH");
      diff = micros() - Time;
      Serial.println(diff);
    }
    else if (micros() - Time >= HIGHperiod && micros() - Time < period)
    {
      digitalWrite(motorPin1, LOW);
      Serial.println("LOW");
      diff = micros() - Time;
      Serial.println(diff);
    }
    else if (micros() - Time >= period)
    {
      Serial.println("end of period");
      diff = micros() - Time;
      Serial.println(diff);
      Time = micros();
    }
  }
  Serial.println("New Sketch");
}
