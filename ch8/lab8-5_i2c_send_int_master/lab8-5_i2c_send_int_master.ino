#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
   byte b1, b2;
   int val = analogRead(A0);
   b1 = val / 256;
   b2 = val % 256;
   Wire.beginTransmission(3);
   Wire.write(b1);
   Wire.write(b2);
   Wire.endTransmission();
   delay(1000);
}
