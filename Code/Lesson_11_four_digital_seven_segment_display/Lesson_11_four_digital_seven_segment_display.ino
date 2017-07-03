/***********************************************************
File name: Lesson_11_four_digital_seven_segment_display.ino
Description: use 74HC595 to control 4-digit 7-segment display
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
//Pin connected to ST_CP of 74HC595
int latch=11;  
//Pin connected to SH_CP of 74HC595
int clock=12; 
//Pin connected to DS of 74HC595
int data=8;  

unsigned char table[]=
{0xc0,0xf9,0xa4,0xb0,0x99,
 0x92,0x82,0xf8,0x80,0x90,
 0x88,0x83,0xc6,0xa1,0x86,
 0xff};

void setup() 
{
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
}
void Display(unsigned char num)
{

  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,~table[num]);
  digitalWrite(latch,HIGH);
  
}
void loop() 
{
  Display(1);
  delay(500);
  Display(2);
  delay(500);
  Display(3);
  delay(500);
  Display(4);
  delay(500);
  Display(5);
  delay(500);
  Display(6);
  delay(500);
  Display(7);
  delay(500);
  Display(8);
  delay(500);
  Display(9);
  delay(500);
  Display(10);
  delay(500);
  Display(11);
  delay(500);
  Display(12);
  delay(500);
  Display(13);
  delay(500);
  Display(14);
  delay(500);
  Display(15);
  delay(500);
}
