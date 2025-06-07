#include <Arduino.h>

int m1 = 3;
int m2 = 5;
int m3 = 6;
int m4 = 9;

void setup()
{
    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);
    pinMode(m3, OUTPUT);
    pinMode(m4, OUTPUT);
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
