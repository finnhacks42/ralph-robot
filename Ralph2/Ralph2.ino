
#include <NewPing.h>

#define TRIGGER_PIN  14  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     15  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int rr = 5;
const int rf = 3;
const int lr = 9;
const int lf = 6;

const int max_ok_dist = 500;
const int min_ok_dist = 50;

int ok_dist = 200; 
int motor_speed=200;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(rf,OUTPUT);
  pinMode(rr,OUTPUT);
  pinMode(lf,OUTPUT);
  pinMode(lr,OUTPUT);
}

void loop() {
  
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int microseconds = sonar.ping_median(5); // get median return time of 5 pings in microseconds (uS).
  int distance = sonar.convert_cm(microseconds); // convert microseconds to cm (based on speed of sound)
  if (distance == 0) {
    distance = ok_dist;
  }
  Serial.print("distance:");
  Serial.print(distance);
  Serial.print("  ok-distance:");
  Serial.println(ok_dist/10);
  
  if (distance < ok_dist/10) {
   Serial.println("turn turn turn"); 
   if (ok_dist > min_ok_dist) {
     ok_dist -= 1;
   }
   analogWrite(lf,motor_speed);
   analogWrite(rr,motor_speed);
   analogWrite(lr,LOW);
   analogWrite(rf,LOW);
  } else {
    Serial.println("of we go");
    if (ok_dist < max_ok_dist) {
      ok_dist +=1;
    }
    digitalWrite(lf,motor_speed);
    digitalWrite(rf,motor_speed);
    digitalWrite(rr,LOW);
    digitalWrite(lr,LOW);
  }
  
  
}
