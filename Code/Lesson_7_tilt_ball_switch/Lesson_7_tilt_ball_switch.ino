/***********************************************************
File name: Lesson_7_tilt_ball_switch.ino
Description: Tilt switches to control the LED light on or off
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
int ledpin=11;       //definition digital 11 pins as pin to control the LED
int tiltSwitchpin=7; //Set the digital 7 to tilt switch interface 
int val;             //Define variable val 

void setup()
{
  pinMode(ledpin,OUTPUT);      //Define small lights interface for the output interface 
  pinMode(tiltSwitchpin,INPUT_PULLUP);//define the tilt switch interface for input interface
}

void loop()
{
  val=digitalRead(tiltSwitchpin);//Read the number seven level value is assigned to val 
  if(val==LOW)                   //Detect tilt switch is disconnected, the tilt switch when small lights go out 
  { digitalWrite(ledpin,LOW);}   //Output low, LED OFF
  else                           //Detection of tilt switch is conduction, tilt the little lights up when the switch conduction +
  { digitalWrite(ledpin,HIGH);}  //Output high, LED ON
}
