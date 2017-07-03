/***********************************************************
File name: Lesson_12_Controlling_Serve_motor.ino
Description:   The servo motor are rotated to 15 degrees, 30 
               degrees, 45 degrees, 60 degrees, 75 degrees, 
               90 degrees, 75 degrees, 60 degrees, 45 degrees,
               30 degrees, 15 degrees, 0 degrees, and then from 
               0 degrees to 180 degrees and from 180 degrees to
               0 degrees.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/

#include <Servo.h>
Servo myservo;//create servo object to control a servo

void setup()
{
  myservo.attach(9);//attachs the servo on pin 9 to servo object
  myservo.write(0);//back to 0 degrees 
  delay(1000);//wait for a second
}

void loop()
{  
  myservo.write(15);//goes to 15 degrees 
  delay(1000);//wait for a second

  myservo.write(30);//goes to 30 degrees 
  delay(1000);//wait for a second.33
  
  myservo.write(45);//goes to 45 degrees 
  delay(1000);//wait for a second.33

  myservo.write(60);//goes to 60 degrees 
  delay(1000);//wait for a second.33

  myservo.write(75);//goes to 75 degrees 
  delay(1000);//wait for a second.33

  myservo.write(90);//goes to 90 degrees
  delay(1000);//wait for a second

  myservo.write(75);//back to 75 degrees 
  delay(1000);//wait for a second.33

  myservo.write(60);//back to 60 degrees
  delay(1000);//wait for a second.33

  myservo.write(45);//back to 45 degrees
  delay(1000);//wait for a second.33

  myservo.write(30);//back to 30 degrees
  delay(1000);//wait for a second.33

  myservo.write(15);//back to 15 degrees 
  delay(1000);//wait for a second

  myservo.write(0);//back to 0 degrees 
  delay(1000);//wait for a second
  for(int num=0;num<=180;num++)
  {
     myservo.write(num);//back to 'num' degrees(0 to 180)
     delay(10);//control servo speed
  }
  for(int num=180;num>=0;num--)
  {
     myservo.write(num);//back to 'num' degrees(180 to 0)
     delay(10);//control servo speed 
  }
}
