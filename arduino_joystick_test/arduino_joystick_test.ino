#include <Arduino.h>

 float xr,yr,x,y;

void setup()
{
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

  Serial.print(x);
  Serial.print("    ");
  Serial.print(y);
  Serial.print("    ");
  Serial.println(analogRead(A4));
  delay(100);
}