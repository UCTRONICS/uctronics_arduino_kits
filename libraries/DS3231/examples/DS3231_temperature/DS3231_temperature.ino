/*
  DS3231: Real-Time Clock. Temperature example
  GIT: https://github.com/UCTRONICS/UCTRONICS_Arduino_kits
  Web: www.uctronics.com 
*/

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
}

void loop()
{
  // The temperature registers are updated after every 64-second conversion.
  // If you want force temperature conversion use forceConversion()
  clock.forceConversion();

  Serial.print("Temperature: ");
  Serial.println(clock.readTemperature());

  delay(1000);
}
