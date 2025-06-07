#include <Arduino.h>

 int x,y;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (analogRead(A2)>=484.5 && analogRead(A2)<=539.5) x=512;    //deadzone of 27.5 (obtained from 255*1.9=484.5)
  else x=analogRead(A2);
  if (analogRead(A3)>=484.5 && analogRead(A3)<=539.5) y=512;
  else y=analogRead(A3);

  Serial.print(x);
  Serial.print("    ");
  Serial.print(y);
  Serial.print("    ");
  Serial.println(analogRead(A4));
  delay(100);
}