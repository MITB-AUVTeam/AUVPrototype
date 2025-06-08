#include <Arduino.h>

int mf = 3;
int mb = 5;
int ml = 6;
int mr = 9;

float xr,yr,x,y,r;

void setup()
{
    pinMode(mf, OUTPUT);
    pinMode(mb, OUTPUT);
    pinMode(ml, OUTPUT);
    pinMode(mr, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
  xr=analogread(A2);
  if (xr>=484.5 && xr<=539.5) x=484.5;    //deadzone of 27.5 (obtained from 255*1.9=484.5) => ranges from 0 to 969
  else if (xr<484.5) x=(xr);
  else if (xr>539.5) x=(xr-55.0);

  yr=analogread(A3);
  if (yr>=484.5 && yr<=539.5) y=484.5;
  else if (yr<484.5) y=(yr);
  else if (yr>539.5) y=(yr-55.0);

  if ((x-484.5)<484.5) {
    analogWrite(mr, (x-484.5)/1.9);
    analogWrite(ml, (x-484.5)/1.9);
  }
  
}
