#include <Wire.h>

void receiveEvent(int numBytes) {
  while(Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
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
  delay(1000);
}
