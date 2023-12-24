#include <Wire.h>

void receiveEvent(int numBytes) {
  while (Wire.available() >= 2) {
    byte b1 = Wire.read();
    byte b2 = Wire.read();
    int val = b1 * 255 + b2;

    Serial.println(val);
  }
}

void setup() {
  // put your setup code here, to run once:
  Wire.begin(3);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}
