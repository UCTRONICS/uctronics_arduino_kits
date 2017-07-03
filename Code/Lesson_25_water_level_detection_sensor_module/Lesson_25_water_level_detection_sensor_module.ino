/***********************************************************
File name: Lesson_25_water_level_detection_sensor_module.ino
Description: when you open the serial monitor, you can see 
the serial port prints data of water level.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
int adc_id = A0;
int HistoryValue = 0;
char printBuffer[128];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
long  temp_max,temp_min, temp_value,temp;
long value = 0;
  temp_max  = analogRead(adc_id); // get adc value
  temp_min  = temp_max;
  temp_value= temp_max;
    
    for(int i = 0; i < 201; i ++ ){
      temp =  analogRead(adc_id);
      if(temp_max<temp)  temp_max = temp;
       if(temp_min>temp) temp_min = temp;
       temp_value += temp;
      }
      value =(temp_value-temp_max-temp_min)/200;
    if(HistoryValue!=value)
    {
      sprintf(printBuffer,"ADC%d level is %d\n",adc_id, value);
      Serial.print(printBuffer);
      HistoryValue = value;  
        delay(500);
      }
  
}
