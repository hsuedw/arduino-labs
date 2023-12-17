#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(3);
  Wire.write("Hello Edward\n");
  Wire.endTransmission();

  delay(1000);
}
