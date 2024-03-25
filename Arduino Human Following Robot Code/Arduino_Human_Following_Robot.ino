/*Human folling robot using Arduino nano.
 * code created by: DIY Burner
 *NOTE : Please don't forget to include the library "Servo.h".
 *For any query contact me on Instagram. (id: diy.burner)
 *code version: 1.0.0
 */
 
#include <Servo.h>
const int trigPin = 10 ; //Servo trig pin to D10
const int echoPin = 11; // Servo echo pin to D11
const int in1 = 5; // Motor driver pin
const int in2 = 4; 
const int in3 = 3;
const int in4 = 2;
const int enA = 6;
const int enB = 7;
#define motorArpm 170 // Default speed for "enA". you can change this speed from 0 to 300
#define motorBrpm 170 // Default speed for "enB". you can change this speed from 0 to 300

Servo servo_motor; //Servo
int pos =0;

void setup(){
  Serial.begin(9600);
servo_motor.attach(8); //Servo signal pin to D8

{
  for(pos = 90; pos <= 180; pos += 1){
  servo_motor.write(pos);
  delay(15);
} for(pos = 180; pos >= 0; pos-= 1) {
  servo_motor.write(pos);
  delay(15);
}for(pos = 0; pos<=90; pos += 1) {
  servo_motor.write(pos);
  delay(15);
}

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
}
}
long duration;
int distance;

void loop(){
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin , LOW);

  duration = pulseIn(echoPin , HIGH);
  distance = (duration/2) / 28.5;

  if(distance < 5) // It will go Backward if distance is less than 5.
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, motorArpm);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, motorBrpm);
  }
  if(distance >40) // It will Stop if distance is More than 40.
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }

  if(distance > 10 && distance < 20){ // to turn Forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, motorArpm);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, motorBrpm);
  }
  
  if(distance > 20 && distance < 30)//// to turn left
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 150);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 160);
  }

  if(distance > 30 && distance <40 ) //// to turn Right
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, motorArpm);
  }