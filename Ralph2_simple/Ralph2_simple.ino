
#include <NewPing.h>

const int TRIGGER_PIN = 14;
const int ECHO_PIN = 15;
const int MAX_DISTANCE = 100; // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int RR = 5;
const int RF = 3;
const int LR = 9;
const int LF = 6;
const int MAX_SPEED = 200;
const int OK_DIST = 15; 


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(RF,OUTPUT);
  pinMode(RR,OUTPUT);
  pinMode(LF,OUTPUT);
  pinMode(LR,OUTPUT);
}

void loop() {
  
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int microseconds = sonar.ping_median(5); // get median return time of 5 pings in microseconds (uS).
  int distance = sonar.convert_cm(microseconds); // convert microseconds to cm (based on speed of sound)
  if (distance == 0) { // zero is returned if no object in range.
    distance = MAX_DISTANCE;
  }
   Serial.print("distance:");
   Serial.println(distance);  
  if (distance < OK_DIST) {
   Serial.println("turn turn turn"); 
   analogWrite(LF,MAX_SPEED);
   analogWrite(RR,MAX_SPEED);
   analogWrite(LR,0);
   analogWrite(RF,0);
   
  } else {
    Serial.println("off we go");
    analogWrite(LF,MAX_SPEED);
    analogWrite(RF,MAX_SPEED);
    analogWrite(RR,0);
    analogWrite(LR,0);
  }
  
}
