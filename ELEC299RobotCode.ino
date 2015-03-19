
//ELEC299 Robot Code
//By: Mitchell Waite
//March 5, 2015

#include <QSerial.h>
#include <Servo.h>
#include "FcnDefs.h"

QSerial myCereal;
Servo panServo;
Servo tiltServo;
Servo gripServo;

bool leftGot, rightGot, midGot;

void setup() {
  
  
  
 Serial.begin(115200); //open serial for USB or bt
 myCereal.attach(3,-1); //pin 4 receieve
  panServo.attach(pan);
  panServo.write(90);
  tiltServo.attach(tilt);
  tiltServo.write(110);
  gripServo.attach(grip); 
  gripServo.write(0);
  
  
  leftGot = false;
  rightGot = false;
  midGot = false;
  delay(1000);
  
  
}

void loop() {
  
  
  
  
}

void center()
{
  
}

void left()
{
  
}

void right()
{
  //gets the ball from the spot to the right of the start pos
}

void grabBall()
{
  tiltServo.write(20);
  delay(1000);
  gripServo.write(40);
  delay(500);
  tiltServo.write(110);
  delay(500);
}

void driveAndStop()
{
  int right, mid, left;
  digitalWrite(rightDir,HIGH);
  digitalWrite(leftDir,HIGH);
  
  
  while(true)
  {
     if (right<rlth)
  {
   analogWrite(rightSpeed,80);
   digitalWrite(rightDir,HIGH);
   analogWrite(leftSpeed,100);
   digitalWrite(leftDir,HIGH); 
  }
  else if (left<llth)
  {
   analogWrite(rightSpeed,100);
   digitalWrite(rightDir,HIGH);
   analogWrite(leftSpeed,80);
   digitalWrite(leftDir,HIGH); 
  }
  else if (right<rlth && left<llth)
  {
   analogWrite(rightSpeed,0);
   analogWrite(leftSpeed,0);
   return;
  }
  else
  {
    analogWrite(leftSpeed,110);
    analogWrite(rightSpeed,100);
  }
  delay(20);
    
  }
}

void turnLeft(int times)
{
  for(int i = 0;i<times;i++)
  {
    digitalWrite(leftDir, LOW);
    digitalWrite(rightDir, HIGH);
    analogWrite(leftSpeed, 100);
    analogWrite(rightSpeed, 100);
    delay(50);
    while(analogRead(MPin) > mlth)
    {
      //yoloswag
    }
    analogWrite(leftSpeed,0);
    analogWrite(rightSpeed,0);
    delay(50);
  }
}

void turnRight(int times)
{
  for(int i = 0;i<times;i++)
  {
    digitalWrite(leftDir, HIGH);
    digitalWrite(rightDir, LOW);
    analogWrite(leftSpeed, 100);
    analogWrite(rightSpeed, 100);
    delay(50);
    while(analogRead(MPin) > mlth)
    {
      //yoloswag
    }
    analogWrite(leftSpeed,0);
    analogWrite(rightSpeed,0);
    delay(50);
  }
}

void driveAndSense()
{
  int right, mid, left;
  digitalWrite(rightDir,HIGH);
  digitalWrite(leftDir,HIGH);
  
  
  while(true)
  {
     if (right<rlth)
  {
   analogWrite(rightSpeed,80);
   digitalWrite(rightDir,HIGH);
   analogWrite(leftSpeed,100);
   digitalWrite(leftDir,HIGH); 
  }
  else if (left<llth)
  {
   analogWrite(rightSpeed,100);
   digitalWrite(rightDir,HIGH);
   analogWrite(leftSpeed,80);
   digitalWrite(leftDir,HIGH); 
  }
  else if (analogRead(IRPin) < IRThresh)
  {
   analogWrite(rightSpeed,0);
   analogWrite(leftSpeed,0);
   return;
  }
  else
  {
    analogWrite(leftSpeed,110);
    analogWrite(rightSpeed,100);
  }
  delay(20);
    
  }
}
