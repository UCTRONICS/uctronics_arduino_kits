/***********************************************************
File name: Lesson_8_7-segement_display.ino
Description:Segment display Numbers 0 to 9, each digital display 
            1 second.After the cycle show
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
int a=4; //definition digital 4  pins as pin to control 'a' section(segment)
int b=5; //definition digital 5  pins as pin to control 'b' section(segment)
int c=7; //definition digital 7  pins as pin to control 'c' section(segment)
int d=8;//definition digital 8 pins as pin to control 'd' section(segment)
int e=9;//definition digital 9 pins as pin to control 'e' section(segment)
int f=11; //definition digital 11  pins as pin to control 'f' section(segment)
int g=10; //definition digital 10  pins as pin to control 'g' section(segment)
int dp=6;//definition digital 6  pins as pin to control 'dp' section(segment)
void digital_0(void) //Segment display digital 0
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp,HIGH);
}
void digital_1(void) //Segment display digital 1
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,HIGH);
}
void digital_2(void) //Segment display digital 2
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}
void digital_3(void) //Segment display digital 3
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}
void digital_4(void) //Segment display digital 4
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}
void digital_5(void) //Segment display digital 5
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}
void digital_6(void) //Segment display digital 6
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);  
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}
void digital_7(void) //Segment display digital 7
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);  
  digitalWrite(c,LOW);  
  digitalWrite(d,HIGH); 
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,HIGH);
}
void digital_8(void) //Segment display digital 8
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}
void digital_9(void) //Segment display digital 9
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}

void setup()
{
  int i;             //Define variables
  for(i=4;i<=11;i++)
  pinMode(i,OUTPUT); //Set up 4 ~ 11 pins to output mode
}
void loop()
{
  digital_0(); //Segment display digital 0
  delay(1000); //Delay 1s
  digital_1(); //Segment display digital 1
  delay(1000); //Delay 1s
  digital_2(); //Segment display digital 2
  delay(1000); //Delay 1s
  digital_3(); //Segment display digital 3
  delay(1000); //Delay 1s
  digital_4(); //Segment display digital 4
  delay(1000); //Delay 1s
  digital_5(); //Segment display digital 5
  delay(1000); //Delay 1s
  digital_6(); //Segment display digital 6
  delay(1000); //Delay 1s
  digital_7(); //Segment display digital 7
  delay(1000); //Delay 1s
  digital_8(); //Segment display digital 8
  delay(1000); //Delay 1s
  digital_9(); //Segment display digital 8
  delay(1000); //Delay 1s
}

