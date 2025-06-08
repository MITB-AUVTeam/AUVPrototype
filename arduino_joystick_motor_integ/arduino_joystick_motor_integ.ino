#include <Arduino.h>

int mf = 3;
int mb = 9;
int ml = 6;
int mr = 5;

float xr,yr,x,y,r;
int d;

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
  xr=analogRead(A2);
  if (xr>=484.5 && xr<=539.5) x=484.5;    //deadzone of 27.5 (obtained from 255*1.9=484.5) => ranges from 0 to 969
  else if (xr<484.5) x=(xr);
  else if (xr>539.5) x=(xr-55.0);

  yr=analogRead(A3);
  if (yr>=484.5 && yr<=539.5) y=484.5;
  else if (yr<484.5) y=(yr);
  else if (yr>539.5) y=(yr-55.0);

  if (x>=484.5 && y>=484.5) {
    r=sqrt(pow(x-484.5,2)+pow(y-484.5,2));
    analogWrite(mr, (r-y)/1.9);
    analogWrite(ml, r/1.9);
  }

  if (x>=484.5 && y<=484.5) {
    r=sqrt(pow(x-484.5,2)+pow(484.5-y,2));
    analogWrite(mr, r/1.9);
    analogWrite(ml, (r+y-484.5)/1.9);
  }
  
  if (x<=484.5 && y<=484.5) {
    analogWrite(mr, 0);
    analogWrite(ml, 0);
  }

  d=analogRead(A1)/4;
    Serial.println(d);
  analogWrite(mf,d);
  analogWrite(mb,d);

}
