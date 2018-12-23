
#include <FastLED.h>

#define NUM_LEDS 51
#define LED_PIN 3
#define Del 60
#define fst 10;
CRGB led[NUM_LEDS];
int s,e,st;
int toggle=0;

void setup() {
  // put your setup code here, to run once:
FastLED.addLeds<NEOPIXEL, LED_PIN>(led, NUM_LEDS);

  for (int i =0; i<NUM_LEDS;i++)
  {
     led[i]= CRGB(0,0,0);
  }
  FastLED.show();
  s=0;
  e=NUM_LEDS-1;
  st=1;

  Serial.begin(9600);
  
}

void swap()
{
   int temp;
   
   temp=s;
   s=e;
   e=temp;
   st= 1;
   if (s>e)
     st= -1;

  //Serial.print("hello\n");
  //Serial.print(s);Serial.println();
  //Serial.print(e);Serial.println();
 // Serial.print(st);Serial.println();
 // Serial.println();
   
  
}


void debugprint(int r, int g, int b)
{
  Serial.print(r);
  Serial.print(" ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print(b);
  Serial.print(" ");
  Serial.println();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
int j,k;
 

  int r,g,b;
  CRGB next;
  int pr,pg,pb,ir,ib,ig;
  int sr,sg,sb;
  int fading;
  

  delay(100);
  //swap();
  toggle+=1;
  if ((toggle & 0x3) == 0x0)
  {
    r = 255; //random(255);
    g = 0; //random(120);
    b = random(40); //random(120);
    }
  else if ((toggle & 0x3) == 0x01)
  {
    r = random(30); //random(255);
    g = 255; //random(120);
    b = 0; //random(120);
  }
  else
  {
    r = random(40); //random(255);
    g = 0; //random(120);
    b = 255; //random(120);
    toggle+=1;
  }
  debugprint(s,e,st);

  for (j=s;j!=e;j=j+st)
  {
      
      for (int k=0;k<5;k++)
      {
        if (k & 0x1)
        {
          led[j].r=0;
          led[j].g=0;
          led[j].b=0;        
        }
        else
        {
          led[j].r=r;
          led[j].g=b;
          led[j].b=g;
        }
        FastLED.show();                     
        delay(2);
      }
      delay(10);
      FastLED.show();                     
  }

}
