/***********************************************************
File name: Lesson_24_real_time_clock_module.ino
Description: Calibration clock.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
#include <Wire.h>
#include <DS3231.h>
DS3231 clock;
RTCDateTime dt;
void setup() 
{
  clock.begin();
  clock.setDateTime(__DATE__, __TIME__);
}

void loop() 
{

}
