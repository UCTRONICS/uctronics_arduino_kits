/***********************************************************
File name: Lesson_13_Controlling_DC_motor.ino
Description: drive the motor using
              the L9110 chip
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
#define DIRA 4
#define DIRB 3

int i;
 
void setup() 
{
  //---set pin direction
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
}

void loop() 
{
  //---back and forth example
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
    delay(1000);
    digitalWrite(DIRA,LOW);  //reverse
    digitalWrite(DIRB,HIGH);
    delay(1000);
}
   
