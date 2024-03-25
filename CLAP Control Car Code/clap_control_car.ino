// How To Make Clap Control Car
// Code Written By Shahbaz Owner of roboattic Lab
// All copyrights reserved to roboattic Lab
// For any any quries contact me on Instagram (INSTAGRAM ID: roboattic_lab)
// Lets get Started...
#include<AFMotor.h>

int sound = 10;
int st = 0;

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int cont = 0;

void Forward()

{

 motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
  delay(1500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void Backward()

{

 motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  delay(1500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void Left()

{

 motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
  delay(500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void Right()

{

 motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  delay(500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void setup()

{

//put your setup code here,to run once;

pinMode (sound, INPUT);

}

void loop()

{

//put your main code here,to run repeatedly;

  if (digitalRead(sound) == HIGH) {
    delay(10);
    if (cont == 0)
      st = millis();
    cont = cont + 1;
    while (digitalRead(sound) != LOW) {
      if (millis() - st > 2000) {
        Serial.print(cont);
        Serial.println(" aplausos");

        doOrders(cont);
        cont = 0;
      }
    }
  }
  if (millis() - st > 2000 && cont != 0) {
    Serial.print(cont);
    Serial.println(" aplausos");
    doOrders(cont);
    cont = 0;
  }
}
void doOrders(int apl) {
 if (cont==1)

{

Forward();

}

else if (cont == 2)

{

Backward();

}

else if (cont == 3)
{

Left();

}

else if (cont == 4)

{

Right();

}
}