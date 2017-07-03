/***********************************************************
File name: Lesson_27_max7219_led_dot_matrix_module.ino
Description: control a 8x8 dot-matrix display the characters 
             for the word "UCTRONICS" one after the other 
             on the matrix 
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
#include "LedControl.h"
/*
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,10,11,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime1=1000;
unsigned long delaytime2=50;
void setup() 
{
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}
/*
 This method will display the characters for the
 word "UCTRONICS" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() 
{
  /* here is the data for the characters */
  byte u[7]={B00010001,B00010001,B00010001,B00010001,B00010001,B00010001,B00001110};
  byte c[7]={B00001111,B00010000,B00010000,B00010000,B00010000,B00010000,B00001111};
  byte t[7]={B00011111,B00000100,B00000100,B00000100,B00000100,B00000100,B00000100};
  byte r[7]={B00011100,B00010010,B00010010,B00011100,B00011000,B00010100,B00010010};
  byte o[7]={B00001110,B00010001,B00010001,B00010001,B00010001,B00010001,B00001110};
  byte n[7]={B00000000,B00010001,B00011001,B00010101,B00010011,B00010001,B00000000};
  byte i[7]={B00011111,B00000100,B00000100,B00000100,B00000100,B00000100,B00011111};
  byte s[7]={B00001111,B00001000,B00001000,B00001111,B00000001,B00000001,B00001111};

  /* now display them one by one with a small delay */
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  lc.setRow(0,5,u[5]);
  lc.setRow(0,6,u[6]);
  delay(delaytime1);
  lc.setRow(0,0,c[0]);
  lc.setRow(0,1,c[1]);
  lc.setRow(0,2,c[2]);
  lc.setRow(0,3,c[3]);
  lc.setRow(0,4,c[4]);
  lc.setRow(0,5,c[5]);
  lc.setRow(0,6,c[6]);
  delay(delaytime1);
  lc.setRow(0,0,t[0]);
  lc.setRow(0,1,t[1]);
  lc.setRow(0,2,t[2]);
  lc.setRow(0,3,t[3]);
  lc.setRow(0,4,t[4]);
  lc.setRow(0,5,t[5]);
  lc.setRow(0,6,t[6]);
  delay(delaytime1);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  lc.setRow(0,5,r[5]);
  lc.setRow(0,6,r[6]);
  delay(delaytime1);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  lc.setRow(0,5,o[5]);
  lc.setRow(0,6,o[6]);
  delay(delaytime1);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  lc.setRow(0,5,n[5]);
  lc.setRow(0,6,n[6]);
  delay(delaytime1);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  lc.setRow(0,5,i[5]);
  lc.setRow(0,6,i[6]);
  delay(delaytime1);
  lc.setRow(0,0,c[0]);
  lc.setRow(0,1,c[1]);
  lc.setRow(0,2,c[2]);
  lc.setRow(0,3,c[3]);
  lc.setRow(0,4,c[4]);
  lc.setRow(0,5,c[5]);
  lc.setRow(0,6,c[6]);
  delay(delaytime1);
  lc.setRow(0,0,s[0]);
  lc.setRow(0,1,s[1]);
  lc.setRow(0,2,s[2]);
  lc.setRow(0,3,s[3]);
  lc.setRow(0,4,s[4]);
  lc.setRow(0,5,s[5]);
  lc.setRow(0,6,s[6]);
  delay(delaytime1);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  lc.setRow(0,5,0);
  lc.setRow(0,6,0);
  delay(delaytime1);
}

void clearLed ()
{
  for(int row=0;row<8;row++) 
  {
    for(int col=0;col<8;col++) 
    {
      lc.setLed(0,row,col,false);
    }
  }
}
void loop() 
{ 
  writeArduinoOnMatrix();
  clearLed ();
}
