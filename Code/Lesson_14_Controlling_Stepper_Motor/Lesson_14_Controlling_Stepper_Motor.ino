/***********************************************************
File name: Lesson_14_Controlling_Stepper_Motor.ino
Description: You can observe the stepper motor is fast and 
             forward in a circle, next the stepper motor is 
             slow and reverse in a circle.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
int Pin0 = 11;//definition digital 11 pins as pin to control the IN1 (ULN24L01)
int Pin1 = 10;//definition digital 10 pins as pin to control the IN2 (ULN24L01)
int Pin2 = 9;//definition digital 9 pins as pin to control the IN3 (ULN24L01)
int Pin3 = 8;//definition digital 8 pins as pin to control the IN4 (ULN24L01)

int _step = 512; 
int _speed = 1; 
void setup()
{
 pinMode(Pin0, OUTPUT);//Set digital 8 port mode, the OUTPUT for the output
 pinMode(Pin1, OUTPUT);//Set digital 9 port mode, the OUTPUT for the output
 pinMode(Pin2, OUTPUT);//Set digital 10 port mode, the OUTPUT for the output
 pinMode(Pin3, OUTPUT);//Set digital 11 port mode, the OUTPUT for the output
}

void loop()
{
   Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
  Step(512);//Stepper motor forward 512 steps ---- 360 angle    
  delay(2000);// delay 2S
   Speed(1); //Stepper motor speed = 1 slow  (note:speed from 1 to 15)
  Step(-512);//Stepper motor backward 512 steps ---- 360 angle    
  delay(2000);//delay 2S
}
void Speed(int stepperspeed)//set Stepper speed 
{
    _speed = 15 - stepperspeed;
    if( _speed<1){
     _speed = 1;
    }
    if( _speed>15){
     _speed = 15;
    }
}
void Step(int _step)//Stepper motor rotation
{
  if(_step>=0){  // Stepper motor forward
    for(int i=0;i<_step;i++){   
      setStep(1, 0, 0, 1);
      delay(_speed); 
      setStep(1, 0, 0, 0);
      delay(_speed);
      setStep(1, 1, 0, 0);
      delay(_speed);
      setStep(0, 1, 0, 0);
      delay(_speed);
      setStep(0, 1, 1, 0);
      delay(_speed);
      setStep(0, 0, 1, 0);
      delay(_speed);
      setStep(0, 0, 1, 1);
      delay(_speed); 
      setStep(0, 0, 0, 1);
      delay(_speed);
    }
  }else{ // Stepper motor backward
     for(int i=_step;i<0;i++){  
      setStep(0, 0, 0, 1);
      delay(_speed);
      setStep(0, 0, 1, 1);
      delay(_speed);
      setStep(0, 0, 1, 0);
      delay(_speed);
      setStep(0, 1, 1, 0);
      delay(_speed);
      setStep(0, 1, 0, 0);
      delay(_speed);
      setStep(1, 1, 0, 0);
      delay(_speed);
      setStep(1, 0, 0, 0);
      delay(_speed);
      setStep(1, 0, 0, 1);
      delay(_speed);
    }
   }
}
void setStep(int a, int b, int c, int d)  
{  
    digitalWrite(Pin0, a);     
    digitalWrite(Pin1, b);     
    digitalWrite(Pin2, c);     
    digitalWrite(Pin3, d);     
}  


