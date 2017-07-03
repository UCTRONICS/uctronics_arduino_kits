/***********************************************************
File name: Lesson_4_Controlling_a_RGB_LED_by_PWM.ino
Description:Control the RGB LED emitting red, green, blue, yellow,
            white and purple light, then the RGB LED will be off,
            each state continues 1s, after repeating the above 
            procedure.   
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
*************************************************************/
int redPin = 11;   // R petal on RGB LED module connected to digital pin 11 
int greenPin = 10; // G petal on RGB LED module connected to digital pin 10 
int bluePin = 9;   // B petal on RGB LED module connected to digital pin 9 
void setup()    
{   
   pinMode(redPin, OUTPUT);   // sets the redPin to be an output 
   pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
   pinMode(bluePin, OUTPUT);  // sets the bluePin to be an output 
}    
void loop()  // run over and over again  
{    
    // Basic colors:  
    color(255, 0, 0); // turn the RGB LED red  
    delay(1000);      // delay for 1 second  
    color(0,255, 0);  // turn the RGB LED green  
    delay(1000);      // delay for 1 second  
    color(0, 0, 255); // turn the RGB LED blue
    delay(1000);      // delay for 1 second  
  
    // Example blended colors:  
    color(255,255,0);   // turn the RGB LED yellow   
    delay(1000);        // delay for 1 second  
    color(255,255,255); // turn the RGB LED white  
    delay(1000);        // delay for 1 second  
    color(128,0,255);   // turn the RGB LED purple  
     delay(1000);       // delay for 1 second  
     color(0,0,0);      // turn the RGB LED off  
     delay(1000);       // delay for 1 second  
}     
     
void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
     analogWrite(redPin, red);     // PWM signal output   
     analogWrite(greenPin, green); // PWM signal output
     analogWrite(bluePin, blue);   // PWM signal output
}     


