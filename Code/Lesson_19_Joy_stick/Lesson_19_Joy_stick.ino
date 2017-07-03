/***********************************************************
File name: Lesson_19_Joy_stick.ino
Description: you can see the joy stick information on the 1602.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
#include <LiquidCrystal.h>
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
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  
int JoyStick_X = A1; //PS2 joystick X-axis is defined, ANALOG IN of Pin0
int JoyStick_Y = A0; //PS2 joystick Y axis is defined, ANALOG IN of Pin1
int JoyStick_Z = 2; //Defined PS2 joystick Z axis,
void setup(void)
{
     lcd.begin(16, 2);    // set up the LCD's number of columns and rows: 
     lcd.clear();         //Clears the LCD screen and positions the cursor in the upper-left corner 
     pinMode(JoyStick_Z, INPUT_PULLUP); //Z axis is defined as an input PS2
}
void loop(void)
{
    int x,y,z;
    x=analogRead(JoyStick_X);
    y=analogRead(JoyStick_Y);
    z=digitalRead(JoyStick_Z);
    
    
 //  lcd.setCursor(0, 0); // set the cursor to column 0, line 0
 //   lcd.print("uctronics joy stick");// Print a message of "Temp: "to the LCD.

    lcd.setCursor(0, 0); // set the cursor to column 0, line 0
    lcd.print("X:");// Print a message of "Temp: "to the LCD.
    lcd.print(x);// Print a centigrade temperature to the LCD.
    lcd.print("   ");// Print a message of "Temp: "to the LCD
    lcd.setCursor(6, 0); // set the cursor to column 0, line 0 
    lcd.print("Y:"); // Print the unit of the centigrade temperature to the LCD.
    lcd.print(y);// Print a centigrade temperature to the LCD
    lcd.print("   ");// Print a message of "Temp: "to the LCD
    lcd.setCursor(13, 0 ); // set the cursor to column 0, line 0 
    lcd.print("Z:"); // Print the unit of the centigrade temperature to the LCD.
    lcd.print(z);// Print a centigrade temperature to the LCD
    delay(500);
}
