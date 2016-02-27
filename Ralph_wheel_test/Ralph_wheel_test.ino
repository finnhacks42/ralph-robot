
const int rr = 5;
const int rf = 3;
const int lr = 9;
const int lf = 6;
int motor_speed = 200;
int run_time = 1000;

void setup() {
  pinMode(rf,OUTPUT);
  pinMode(rr,OUTPUT);
  pinMode(lf,OUTPUT);
  pinMode(lr,OUTPUT);
  
  analogWrite(lr,LOW);
  analogWrite(lf,LOW);
  analogWrite(rr,LOW);
  analogWrite(rf,LOW);
  

}

void loop() {
  analogWrite(lf,motor_speed);
  delay(run_time);
  analogWrite(lf,LOW);
  
  analogWrite(lr,motor_speed);
  delay(run_time);
  analogWrite(lr,LOW);
  
  analogWrite(rf,motor_speed);
  delay(run_time);
  analogWrite(rf,LOW);
  
  analogWrite(rr,motor_speed);
  delay(run_time);
  analogWrite(rr,LOW);
  
  delay(2000);
  
}
