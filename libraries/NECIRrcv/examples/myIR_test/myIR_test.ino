#include "NECIRrcv.h"

NECIRrcv IR_1(2);
int i=0;
void setup()
{
  Serial.begin(9600);
  IR_1.begin();
}
void loop() {
  while(IR_1.available())
  {
    Serial.println(IR_1.read(),HEX);
  }
}



