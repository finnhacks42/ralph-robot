
#include <NewPing.h>

const int trigger_pin = 14;
const int echo_pin = 15;
const int max_distance = 100; // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int rr = 5;
const int rf = 3;
const int lr = 9;
const int lf = 6;

int ok_dist = 15; 
int max_speed = 200;

NewPing sonar(trigger_pin, echo_pin, max_distance); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(rf,OUTPUT);
  pinMode(rr,OUTPUT);
  pinMode(lf,OUTPUT);
  pinMode(lr,OUTPUT);
}

void loop() {
  
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int microseconds = sonar.ping_median(5); // get median return time of 5 pings in microseconds (uS).
  int distance = sonar.convert_cm(microseconds); // convert microseconds to cm (based on speed of sound)
  if (distance == 0) { // zero is returned if no object in range.
    distance = ok_dist;
  }
   Serial.print("distance:");
   Serial.println(distance);  
  if (distance < ok_dist) {
   Serial.println("turn turn turn"); 
   analogWrite(lf,max_speed);
   analogWrite(rr,max_speed);
   analogWrite(lr,0);
   analogWrite(rf,0);
   
  } else {
    Serial.println("of we go");
    analogWrite(lf,max_speed);
    analogWrite(rf,max_speed);
    analogWrite(rr,0);
    analogWrite(lr,0);
  }
  
}
