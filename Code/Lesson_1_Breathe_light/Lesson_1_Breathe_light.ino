/***********************************************************
File name: Lesson_1_Breathe_light.ino
Description: PWM control the LED gradually from dark to 
             brighter, then from brighter to dark
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
int ledpin=11; //definition digital 11 pins as pin to control the LED

void setup ()
{
  pinMode(ledpin,OUTPUT); //Set digital 11 port mode, the OUTPUT for the output
}
 
void loop()
{
   for (int a=0; a<=255;a++)  //Loop, PWM control of LED brightness increase
   {
     analogWrite(ledpin,a);   //PWM output value a (0~255)
     delay(15);                //The duration of the current brightness level. 15ms           
   }
   for (int a=255; a>=0;a--)  //Loop, PWM control of LED brightness Reduced
   {
     analogWrite(ledpin,a);   //PWM output value a (255~0)
     delay(15);                //The duration of the current brightness level. 15ms 
   }
   delay(100);                //100ms delay
}
