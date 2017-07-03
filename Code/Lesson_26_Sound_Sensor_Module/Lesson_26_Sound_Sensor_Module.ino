/***********************************************************
File name: Lesson_26_Sound_Sensor_Module.ino
Description: When you talk to the microphone, the serial 
             port will print out the value of volume,and the 
             LED will be lit when you speak.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
int  sensorPin  =  A0;     // select the input  pin for  the potentiometer 
int  ledPin  =  13;   // select the pin for  the LED
int  sensorValue =  0;  // variable to  store  the value  coming  from  the sensor

void setup()
{
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}
void loop(){
sensorValue =  analogRead(sensorPin);
digitalWrite(ledPin,  HIGH); 
delay(sensorValue); 
digitalWrite(ledPin,  LOW);
delay(sensorValue);
Serial.println(sensorValue,  DEC);
}

