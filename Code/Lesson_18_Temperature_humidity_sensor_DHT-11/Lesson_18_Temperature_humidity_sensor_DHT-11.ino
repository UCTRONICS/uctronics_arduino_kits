/***********************************************************
File name: 18_DHT11.ino
Description: you can see the temperature and humidity data
             displayed on the LCD1602.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/01/16
***********************************************************/
#include <dht11.h>
#include <LiquidCrystal.h>
dht11 DHT11;
int DHT11PIN = A0;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  //Define the connection LCD pin  
/*
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/
void setup()
{ 
     lcd.begin(16, 2);   // set up the LCD's number of columns and rows: 
     lcd.clear();        //Clears the LCD screen and positions the cursor in the upper-left corner 
     delay(1000);        //Delay 1000ms
}
 
void loop()
{
    int chk = DHT11.read(DHT11PIN);
    lcd.setCursor(0, 0); // set the cursor to column 0, line 0
    lcd.print("Humidity:");// Print a message of "Humidity: "to the LCD.
    lcd.print((float)DHT11.humidity, 2);// Print a message of "Humidity: "to the LCD.
    lcd.print(" % "); // Print the unit of the centigrade temperature to the LCD.
    
    lcd.setCursor(0, 1); // set the cursor to column 0, line 1
    lcd.print("Temp:    ");// Print a message of "Temp: "to the LCD.
    lcd.print((float)DHT11.temperature, 2);// Print a centigrade temperature to the LCD. 
    lcd.print(" C "); // Print the unit of the centigrade temperature to the LCD.
    delay(1000);     
}
