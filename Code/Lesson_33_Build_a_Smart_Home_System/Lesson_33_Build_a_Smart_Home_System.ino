/***********************************************************
File name: Lesson_33_Build_a_Smart_Home_System.ino
Description: Build a simulated smart home system by 
using the ESP8266 and some other sensor
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
#include <dht11.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <DS3231.h>
#include "uartWIFI.h"
#include <SoftwareSerial.h>

#define SSID "KK"                  //type your own SSID name
#define PASSWORD "12345687"        //type your own WIFI password


#define Temp_maxlimit  30         // type your Maximum temperature 
#define Temp_minlimit  24         // type your Minimum temperature 


WIFI wifi;
extern int chlID;        //client id(0-4)

DS3231 clock;
RTCDateTime dt;
dht11 DHT11;
                                                                                                                                                                                                                                                                                                                      
const int DHT11PIN = A0;
const int IN1 = 3; 
const int IN2 = 4;
const int IN3 = 5; 
const int IN4 = 6;

int lcd_off1=0,n=0;
int data1,data2;

int  now_temp,now_distance,now_light;
bool send_tmp_EN=0,send_hum_EN=0,send_DEBUG_EN=0,send_con_EN=0;
int  timer1_counter;

bool warning_1,warning_2,MODE_0=0;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() 
{
   pinMode(IN1, OUTPUT);
   pinMode(IN2, OUTPUT);
   pinMode(IN3, OUTPUT);
   pinMode(IN4, OUTPUT);   
   Serial.begin(9600);  
   clock.begin();  
   lcd.begin(16, 2);        //set up the LCD's number of columns and rows: 
   lcd.clear();             //Clears the LCD screen and positions the cursor in the upper-left corner 
   ESP8266_init ();
   delay(1000);             //delay 1000ms
}

void loop() 
{

  dt = clock.getDateTime();  //Get time from RTC module
  wifi_recv ();              //Receive wifi data
  
  n++;
  if (n==5)                 //Loop 5 times 
  {  
    DHT11.read(DHT11PIN);   //Get temperature and humidity from the DHT11
    now_temp = DHT11.temperature; 
    //Serial.println(now_temp);
    LCD_display ();         //Refresh the LCD1602
    n=0;
  }  
  
  Update_data ();           //Update the temperature and humidity to APP
  SenorData_process ();     //Check the data from each channel
  Control ();               //Control motor according to the result of the previous function


  delay (100);

}
/***********************************************************
 * 
 *   The function of update the temperature and humidity
 * 
***********************************************************/
void Update_data (void)
{
  if (send_tmp_EN)
  {
    data1=(int)DHT11.temperature;
    data2=(int)DHT11.humidity;
    send_data ();
  }
  if (send_hum_EN)
  {
    data2=(int)DHT11.humidity;
    
    send_data ();
  }
  if (send_DEBUG_EN||send_con_EN)
  { 
    send_data ();
  }
}
/***********************************************************
 * 
 *   The function of Wifi data send
 *   
***********************************************************/
void send_data (void)
{
  if (send_tmp_EN==1||send_hum_EN==1||send_DEBUG_EN==1||send_con_EN)
  {
    _cell.print("AT+CIPSEND=0,126\r\n");
    unsigned long start;
    bool found;
    start = millis();
    while (millis()-start<250) 
    {                            
        if(_cell.find(">")==true )
        {
          found = true;
          break;
        }
    }
    if(found)
    {        
      _cell.print("HTTP/1.1 200 OK\r\nDate: Sat, 31 Dec 2005 23:59:59 GMT\r\nContent-Type: text/html;charset=ISO-8859-1\r\nContent-Length: 7\r\n\r\n");  // Data header
      
      if (send_tmp_EN)                    // Updata Humidity and Temperature
      {
        _cell.print("tmp");
        _cell.print(data1);
        _cell.print(data2);
        send_tmp_EN=0;
        Serial.println ("Update");
      }
      if (send_DEBUG_EN)                  // Response control signal
      {
        _cell.print("debugen");
        send_DEBUG_EN=0;
      }
      if (send_con_EN)                    // Response detection of connection status
      {
        _cell.print("connect");
        send_con_EN=0;
      }
      _cell.print("\r\n");
      _cell.print("AT+CIPCLOSE=0\r\n");   // Close port
     }
      else
     {
        wifi.closeMux();
     }
     String data;
     start = millis();
     while (millis()-start<250) 
     {
       if(_cell.available()>0)
       {
         char a =_cell.read();
         data=data+a;
       }
       if (data.indexOf("SEND OK")!=-1)
       {
         Serial.println("Send OK");
         break;
       }
     }
  }
}
/***********************************************************
 * 
 *   The function of Wifi data receiving
 * 
***********************************************************/
void wifi_recv (void)
{
  char buf[100];
  int iLen = wifi.ReceiveMessage(buf);

    if (iLen>0)
  {
    //Serial.println(buf);

    if (buf[5]=='o'&&buf[6]=='n')                           // CH0 ON
    {      
     
      send_DEBUG_EN=1;
      if (MODE_0==1)
      {
        warning_1=1;
        lcd.clear();   
        lcd.setCursor(0, 0);   
        lcd.print("CH0 ON");
        
        Serial.println("CH0 ON");
        delay (500);
      }
    }
    if (buf[5]=='o'&&buf[6]=='f'&&buf[7]=='f')              // CH0 OFF
    {
      send_DEBUG_EN=1;
      if (MODE_0==1)
      {   
        warning_1=0;
        lcd.clear();
        lcd.setCursor(0, 0);   
        lcd.print("CH0 OFF");
        Serial.println("CH0 OFF");
        delay (500);
      }
    }
    if (buf[5]=='m'&&buf[6]=='o'&&buf[7]=='d'&&buf[8]=='e') // MODE CHANGE 
    {
      
      MODE_0=!MODE_0;
      lcd.clear();       
      if (MODE_0==0)                   //Switch to automatic mode
      {
         lcd.setCursor(0, 0);   
         lcd.print("automatic");  
         send_DEBUG_EN=1;
         Serial.println("Mode Change:automatic");
         delay (500);
      }
      else                            //Switch to manual mode
      {
         lcd.setCursor(0, 0);   
         lcd.print("manual");  
         warning_1=0;
         send_DEBUG_EN=1;
         Serial.println("Mode Change:manual");
         delay (500);
      }
    }
    if (buf[5]=='c'&&buf[6]=='o'&&buf[7]=='n')          // Check the connection status
    {
      send_con_EN=1;
      lcd.clear();   
      lcd.setCursor(0, 0);  
      lcd.print("Connected");  
      Serial.println("Connected");
      delay (500);
    }
    if (buf[5]=='t'&&buf[6]=='m'&&buf[7]=='p')          // Temperature and Humidity update
    {
      send_tmp_EN=1;
      /*lcd.clear();   
      lcd.setCursor(0, 0);  
      lcd.print("temp update");  
      Serial.println("TEMP");
      delay (500);*/
      delay (50);
    }
  }
}
/***********************************************************
 * 
 *       The function of data processing
 * 
***********************************************************/
void SenorData_process (void)
{
  if (now_temp>Temp_maxlimit&&(!MODE_0))          //Check temperature,High temperature will turn on the fan 
  {
    warning_1=1;
  }
  if ((now_temp<Temp_minlimit||now_temp==Temp_minlimit)&&(!MODE_0)) //when the emperature back to safety level,the fan will be turned off
  {
    warning_1=0;
  }
}

/***********************************************************
 * 
 *     Control
 * 
***********************************************************/
void Control (void)
{
  if (warning_1==1)
  {
    motor1_start ();
  }
  else
  {
    motor1_stop ();
  }
}
/***********************************************************
 * 
 *    Motor control 
 * 
***********************************************************/
void motor1_start (void)
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}
void motor1_stop (void)
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}
void motor2_start (void)
{
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void motor2_stop (void)
{
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
/***********************************************************
 * 
 *      Refresh the LCD1602
 * 
***********************************************************/
void LCD_display (void)
{ 
  n=0; 
  lcd.setCursor(0, 0);   
  lcd.print(clock.dateFormat("jS M y, h:ia", dt)+lcd_off1);  
  lcd.setCursor(0, 1);
  //Serial.println(DHT11.humidity);
  //Serial.println(DHT11.temperature);
  lcd.print((float)DHT11.humidity, 2);// Print a message of Humidity to the LCD.
  lcd.print(" % "); // Print the unit of the centigrade temperature to the LCD.
  lcd.print((float)DHT11.temperature, 2);// Print a centigrade temperature to the LCD. 
  lcd.print(" C "); // Print the unit of the centigrade temperature to the LCD.
  lcd_off1++; 
  if (lcd_off1==3)
  {
    lcd_off1=0;
  }
}
/***********************************************************
 * 
 *     The initialization of ESP8266
 * 
***********************************************************/
void ESP8266_init (void)
{
  bool result=wifi.begin();
  if (result==1)
  {
    lcd.clear();    
    lcd.print("Module is ready");
  }
  else
  {
    lcd.clear();    
    lcd.print("Module not ready");
  } 

  bool b = wifi.Initialize(AP_STA, SSID, PASSWORD);
  lcd.clear();   
  if(!b)
  {
    Serial.println("Init error"); 
    lcd.print("Init error");
  }
  else 
  {
    lcd.print("reboot wifi OK");
  }
    delay(2000); //make sure the module can have enough time to get an IP address 
  
  String ipstring = wifi.showIP();
  int ip_dress_1=ipstring.indexOf('"');
  int ip_dress_2=ipstring.indexOf('"',ip_dress_1 + 1);
  int ip_dress_3=ipstring.indexOf('"',ip_dress_2 + 40);
  int ip_dress_4=ipstring.indexOf('"',ip_dress_3 + 1);
  Serial.print("APIP:");                                             //show the ip address of module
  Serial.println(ipstring.substring(ip_dress_1,ip_dress_2+1));        
  Serial.print("STAIP:");             
  Serial.println(ipstring.substring(ip_dress_3,ip_dress_4+1));       
  lcd.clear();    
  lcd.setCursor(0, 0);
  lcd.print(ipstring.substring(ip_dress_1,ip_dress_2+1));     
  lcd.setCursor(0, 1);
  lcd.print(ipstring.substring(ip_dress_3,ip_dress_4+1));   
              
  delay(2000);
  wifi.confMux(1);
  delay(100);
  if(wifi.confServer(1,8089))
  {
    Serial.println("Server is set up");
    lcd.clear();    
    lcd.print("Server is set up");
  }
}

