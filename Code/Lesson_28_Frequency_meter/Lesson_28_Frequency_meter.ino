/***********************************************************
File name: Lesson_28_Frequency_meter.ino
Description: Use Arduino UNO R3 or Mega 2560 gathering issued NE555 square wave.
             Square wave frequency values were collected via a 
             serial port will be sent to the serial monitor display.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
int pin = 7;               //attach to the third pin of NE555

unsigned long duration;    //the variable to store the length of the pulse
unsigned long durationhigh;//the variable to store the length of the pulse 
unsigned long durationlow; //the variable to store the length of the pulse

void setup()
{
  pinMode(pin, INPUT);     //set the pin as an input
  Serial.begin(9600);     // start serial port at 9600 bps:
}
void loop()
{
  durationhigh = pulseIn(pin, HIGH); //Reads a pulse on pin
  durationlow = pulseIn(pin, LOW);   //Reads a pulse on pin
  duration = 1000000/(durationhigh + durationlow);
  Serial.print("Freq: ");           //print Freq:
  Serial.print(duration);           //print the length of the pulse on the serial monitor
  Serial.print("Hz  HTime: ");      //print Hz HTime:
  Serial.print(durationhigh);       //print the length of the pulse on the serial monitor
  Serial.print("us  LTime: ");      //print us LTime:
  Serial.print(durationlow);        //print the length of the pulse on the serial monitor
  Serial.print("us ");              //print us
  Serial.println();                 //print an blank on serial monitor
  delay(500);                        //wait for 500 microseconds
} 
