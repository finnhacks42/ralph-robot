
#include <NewPing.h>

#define TRIGGER_PIN  14  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     15  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int rr = 5;
const int rf = 3;
const int lr = 9;
const int lf = 6;

int ok_dist = 15; 

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(rf,OUTPUT);
  pinMode(rr,OUTPUT);
  pinMode(lf,OUTPUT);
  pinMode(lr,OUTPUT);
}

void loop2(){
     digitalWrite(lf,LOW);
     digitalWrite(rr,LOW);
     digitalWrite(lr,LOW);
     digitalWrite(rf,HIGH);
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
   digitalWrite(lf,HIGH);
   digitalWrite(rr,HIGH);
   digitalWrite(lr,LOW);
   digitalWrite(rf,LOW);
   
  } else {
    Serial.println("of we go");
    digitalWrite(lf,HIGH);
    digitalWrite(rf,HIGH);
    digitalWrite(rr,LOW);
    digitalWrite(lr,LOW);
  }
  
}
