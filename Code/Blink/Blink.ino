/***********************************************************
File name: Blink.ino
Description: Turns on an LED on for one second.then off for 
             one second,repeatedly.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
void setup() 
{
  //initialize digital pin LED_BUILTIN as an output .
  pinMode (LED_BUILTIN,OUTPUT);
}

void loop()  
{
  // put your main code here, to run repeatedly:
  digitalWrite (LED_BUILTIN,HIGH);  //turn the LED on
  delay (1000);                     //wait for a second 
  digitalWrite (LED_BUILTIN,LOW);   //turn the LED off 
  delay (1000);                     //wait for a second
}
