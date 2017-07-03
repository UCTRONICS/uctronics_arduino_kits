/***********************************************************
File name: Lesson_15_Intrusion_Detection_based_on_the_PIR.ino
Description: The LED will be turned on when the motion has been detected.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/01/16
***********************************************************/

int ledpin=11;           //Set the digital 11 to LED
int PIRpin=5;           //Set the digital 5 to PIR
void setup() {
  // put your setup code here, to run once:
  pinMode( ledpin,OUTPUT);     //initialize the  led pin as output 
  pinMode( PIRpin,INPUT);     //initialize the  PIR pin as input
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(digitalRead(PIRpin)==LOW)
  {
    digitalWrite(ledpin,LOW);
  }else
  {
    digitalWrite(ledpin,HIGH);
  }
}
