/***********************************************************
File name: Lesson_24_real_time_clock_module.ino
Description: Show real time by DS3231 ,The clock still run 
even if the module is powered down.
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
  Serial.begin(9600);

  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);

  // Set from UNIX timestamp
  // clock.setDateTime(1397408400);

  // Manual (YYYY, MM, DD, HH, II, SS
   clock.setDateTime(2016, 12, 9, 11, 46, 00);
}

void loop()
{
  dt = clock.getDateTime();
  Serial.print("Long number format:          ");
  Serial.println(clock.dateFormat("d-m-Y H:i:s", dt));
  Serial.print("Long format with month name: ");
  Serial.println(clock.dateFormat("d F Y H:i:s",  dt));
  Serial.print("Short format witch 12h mode: ");
  Serial.println(clock.dateFormat("jS M y, h:ia", dt));
  Serial.print("Today is:                    ");
  Serial.print(clock.dateFormat("l, z", dt));
  Serial.println(" days of the year.");
  Serial.print("Actual month has:            ");
  Serial.print(clock.dateFormat("t", dt));
  Serial.println(" days.");
  Serial.print("Unixtime:                    ");
  Serial.println(clock.dateFormat("U", dt));
  Serial.println();
  delay(500);
}

