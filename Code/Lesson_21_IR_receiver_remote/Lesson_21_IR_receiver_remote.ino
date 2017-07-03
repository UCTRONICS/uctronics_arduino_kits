/***********************************************************
File name: Lesson_21_IR_receiver_remote.ino
Description: use an IR receiver to receive the remote 
             controller signal.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
#include "NECIRrcv.h"
NECIRrcv IR_1(11);
int i=0;
void setup()
{
  Serial.begin(9600);
  IR_1.begin();
}
void loop() 
{
  while(IR_1.available())
  {
     // Serial.println(IR_1.read(),HEX);
      
     switch(IR_1.read())
    {
      case 0xFF16E9: Serial.println("0");    break;
      case 0xFF0CF3: Serial.println("1");    break;
      case 0xFF18E7: Serial.println("2");    break;
      case 0xFF5EA1: Serial.println("3");    break;
      case 0xFF08F7: Serial.println("4");    break;
      case 0xFF1CE3: Serial.println("5");    break;
      case 0xFF5AA5: Serial.println("6");    break;
      case 0xFF42BD: Serial.println("7");    break;
      case 0xFF52AD: Serial.println("8");    break;
      case 0xFF4AB5: Serial.println("9");    break;
      case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

      default: Serial.println(" other button   ");

     }// End Case
     
  }
}


