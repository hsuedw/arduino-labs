
#include <SPI.h>

const byte NOOP = 0x0;
const byte DECODE = 0x9;
const byte INTENSITY = 0xA;
const byte SCANLIMIT = 0xB;
const byte SHUTDOWN = 0xC;
const byte DISPLAYTEST = 0xF;

const byte symbol[8]= {0x60, 0xF0, 0xF0, 0x7F, 0x07, 0x06, 0x0C, 0x08};

void max7219(byte reg, byte data) {
  digitalWrite(SS, LOW);
  SPI.transfer(reg);
  SPI.transfer(data);
  digitalWrite(SS, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(SS, OUTPUT);
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH);
  SPI.begin();

  max7219(SCANLIMIT, 7);
  max7219(DECODE, 0);
  max7219(INTENSITY, 8);
  max7219(DISPLAYTEST, 0);
  max7219(SHUTDOWN, 1);

  for (byte i = 0; i < 8; ++i) {
    max7219(i + 1, 0);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for (byte i = 0; i < 8; ++i) {
    max7219(i + 1, symbol[i]);
  }  
}
