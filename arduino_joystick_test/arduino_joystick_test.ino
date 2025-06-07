#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print(analogRead(A2));
  Serial.print("    ");
  Serial.print(analogRead(A3));
  Serial.print("    ");
  Serial.println(analogRead(A4));
  delay(100);
}
