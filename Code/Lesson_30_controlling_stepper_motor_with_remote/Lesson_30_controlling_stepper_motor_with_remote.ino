/***********************************************************
File name: Lesson_30_controlling_stepper_motor_with_remote.ino
Description: control a stepper motor from a distance using 
             an IR remote control.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
#include "Stepper.h"
#include "NECIRrcv.h"
NECIRrcv IR_1(12);

/*----- Variables, Pins -----*/
#define STEPS  32   // Number of steps per revolution of Internal shaft
int  Steps2Take;  // 2048 = 1 Revolution

/*-----( Declare objects )-----*/
// Setup of proper sequencing for Motor Driver Pins
// In1, In2, In3, In4 in the sequence 1-3-2-4
uint32_t Val = 0;
Stepper small_stepper(STEPS, 8, 10, 9, 11);
void setup()
{ 
  IR_1.begin();
  Serial.begin (9600);
}

void loop()
{
if (IR_1.available()) // have we received an IR signal?

  {
    Val = IR_1.read();
    Serial.println(Val,HEX);
    switch(Val)
    {

      case 0xFF0CF3: // 1 button pressed
                      small_stepper.setSpeed(500); //Max seems to be 500
                      Steps2Take  =  2048;  // Rotate CW
                      small_stepper.step(Steps2Take);
                      delay(2000); 
                      break;

      case 0xFF18E7: // 2 button pressed
                      small_stepper.setSpeed(500);
                      Steps2Take  =  -2048;  // Rotate CCW
                      small_stepper.step(Steps2Take);
                      delay(2000); 
                      break;
                
    }
                 digitalWrite(8, LOW);
                 digitalWrite(9, LOW);
                 digitalWrite(10, LOW);
                 digitalWrite(11, LOW);       
  }  


}/* --end main loop -- */
