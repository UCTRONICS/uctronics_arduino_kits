/***********************************************************
File name: Lesson_6_Play_the_Music.ino
Description:  you can hear the passive buzzer playing music,
              and you can see flickering LED follow the rhythm
              of the music at the same time.
Website: www.uctronics.com 
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/06/12
***********************************************************/
#define NTD0 -1                    //bass  1#   2#   3#   4#   5#   6#   7# 
#define NTD1 294                   // A    221  248  278  294  330  371  416 
#define NTD2 330                   // B    248  278  294  330  371  416  467
#define NTD3 350                   // C    131  147  165  175  196  221  248
#define NTD4 393                   // D    147  165  175  196  221  248  278
#define NTD5 441                   // E    165  175  196  221  248  278  312
#define NTD6 495                   // F    175  196  221  234  262  294  330
#define NTD7 556                   // G    196  221  234  262  294  330  371
                                   
#define NTDL1 147                  //Alto  1    2    3    4    5    6    7
#define NTDL2 165                  // A    441  495  556  589  661  742  833
#define NTDL3 175                  // B    495  556  624  661  742  833  935
#define NTDL4 196                  // C    262  294  330  350  393  441  495
#define NTDL5 221                  // D    294  330  350  393  441  495  556
#define NTDL6 248                  // E    330  350  393  441  495  556  624
#define NTDL7 278                  // F    350  393  441  495  556  624  661  
                                   // G    393  441  495  556  624  661  742
#define NTDH1 589
#define NTDH2 661                  //high pitch  1#   2#   3#   4#   5#   6#   7#  
#define NTDH3 700                  //    A       882  990  1112 1178 1322 1484 1665   
#define NTDH4 786                  //    B       990  1112 1178 1322 1484 1665 1869 
#define NTDH5 882                  //    C       525  589  661  700  786  882  990
#define NTDH6 990                  //    D       589  661  700  786  882  990  1112
#define NTDH7 112                  //    E       661  700  786  882  990  1112 1248
//c pinlv                          //    F       700  786  882  935  1049 1178 1322
#define WHOLE 1                    //    G       786  882  990  1049 1178 1322 1484
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625

int tune[]=      //Music tones
{
  NTD3,NTD3,NTD4,NTD5,
  NTD5,NTD4,NTD3,NTD2,
  NTD1,NTD1,NTD2,NTD3,
  NTD3,NTD2,NTD2,
  NTD3,NTD3,NTD4,NTD5,
  NTD5,NTD4,NTD3,NTD2,
  NTD1,NTD1,NTD2,NTD3,
  NTD2,NTD1,NTD1,
  NTD2,NTD2,NTD3,NTD1,
  NTD2,NTD3,NTD4,NTD3,NTD1,
  NTD2,NTD3,NTD4,NTD3,NTD2,
  NTD1,NTD2,NTDL5,NTD0,
  NTD3,NTD3,NTD4,NTD5,
  NTD5,NTD4,NTD3,NTD4,NTD2,
  NTD1,NTD1,NTD2,NTD3,
  NTD2,NTD1,NTD1
};
float durt[]= //Each musical tone delay time
{
  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1+0.5,0.5,1+1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1+0.5,0.5,1+1,
  1,1,1,1,
  1,0.5,0.5,1,1,
  1,0.5,0.5,1,1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,0.5,0.5,
  1,1,1,1,
  1+0.5,0.5,1+1,
};
int length;
int tonepin=6;  //Buzzer connected digital pin 6
int ledp=3;     //LED connected digital pin 3
void setup()
{
  pinMode(tonepin,OUTPUT); //Digital pin 6 output mode
  pinMode(ledp,OUTPUT);    //Digital pin 3 output mode
  length=sizeof(tune)/sizeof(tune[0]);//Calculate the total number of musical tones
}
void loop()
{ 
  for(int x=0;x<length;x++)
  {
    tone(tonepin,tune[x]);    //Open buzzer
    digitalWrite(ledp, HIGH); //LED On
    delay(400*durt[x]);       //Tone Delay. Note:400 can be replaced
    digitalWrite(ledp, LOW);  //LED Off
    delay(100*durt[x]);       //Tone Delay. Note:100 can be replaced
    noTone(tonepin);          //Turn off the buzzer
  }  
  delay(2000);                //delay 2S
}
