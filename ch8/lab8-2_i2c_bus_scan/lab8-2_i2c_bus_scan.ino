#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  byte total = 0, code;

  Wire.begin();
  Wire.setClock(100000UL);
  Serial.begin(9600);
  Serial.println("I2C Scanning...");

  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    code = Wire.endTransmission();

    if (code == 0) {
      Serial.print("Found one at: 0x");
      Serial.println(addr, HEX);
      ++total;
    } else if (code == 4) {
      Serial.print("Unknown error at: 0x");
      Serial.println(addr, HEX);
    }
  }

  if (total == 0)
    Serial.println("No I2C devices found.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
