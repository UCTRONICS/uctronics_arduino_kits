/***********************************************************
File name: Lesson_20_Ultrasonic_distance_sensor.ino
Description: When you move the ultrasonic distance sensor,
             you will find LCD1602 display distance.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
#include <LiquidCrystal.h>
const int echoPin = 5;  // pin connected to Echo Pin in the ultrasonic distance sensor
const int trigPin  = 6; // pin connected to trig Pin in the ultrasonic distance sensor

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);   
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
   pinMode(echoPin, INPUT); //Set the connection pin output mode Echo pin
   pinMode(trigPin, OUTPUT);//Set the connection pin output mode trog pin
   lcd.begin(16, 2);        //set up the LCD's number of columns and rows: 
   lcd.clear();             //Clears the LCD screen and positions the cursor in the upper-left corner 
   delay(1000);             //delay 1000ms
} 

void loop() 
{ 
   int cm = ping(echoPin) ;
   lcd.setCursor(0, 0);          // set the cursor to column 0, line 0
   lcd.print("distance: ");      // Print a message of "Temp: "to the LCD.
   lcd.print(cm);                // Print a centigrade temperature to the LCD. 
   lcd.print(" cm    ");         // Print the unit of the centigrade temperature to the LCD.
   delay(500);
}
     
int ping(int echoPin) 
{ 
   // establish variables for duration of the ping, 
   // and the distance result in inches and centimeters: 
   long duration, cm; 
   // The PING))) is triggered by a HIGH pulse of 2 or more microseconds. 
   // Give a short LOW pulse beforehand to ensure a clean HIGH pulse: 
   pinMode(trigPin, OUTPUT); 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(trigPin, HIGH); 
   delayMicroseconds(5); 
   digitalWrite(trigPin, LOW); 

   pinMode(echoPin, INPUT); 
   duration = pulseIn(echoPin, HIGH); 

   // convert the time into a distance 
   cm = microsecondsToCentimeters(duration); 
   return cm ; 
} 

long microsecondsToCentimeters(long microseconds) 
{ 
   // The speed of sound is 340 m/s or 29 microseconds per centimeter. 
   // The ping travels out and back, so to find the distance of the 
   // object we take half of the distance travelled. 
   return microseconds / 29 / 2; 
} 

        
        
        
        
      
