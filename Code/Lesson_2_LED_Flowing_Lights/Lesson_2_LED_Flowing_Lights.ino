/***********************************************************
File name: Lesson_2_LED_Flowing_Lights.ino
Description: LED turn lighting control
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
//Pin connected to ST_CP of 74HC595
int latchPin = 11;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 8;

void setup() 
{
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() 
{
  int j=1,dire;
  while (1)       //count up routine
  {
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, j);       //return the latch pin high to signal chip that it 
                                                    //no longer needs to listen for information
    digitalWrite(latchPin, HIGH);
    if (j==1)
      dire=1;
    else if (j==128)
      dire=0;
    if (dire==1)
      j=j<<1;
    else
      j=j>>1; 
    delay(1000);
  }
}
