#include <SPI.h>

const byte sprite[4][8] {
  {0x30, 0x7C, 0xAE, 0x3E, 0x3E, 0xAE, 0x7C, 0x30},  
  {0x18, 0xBE, 0x57, 0x1F, 0x1F, 0x57, 0xBE, 0x18},
  {0x30, 0xBC, 0x6E, 0x3E, 0x3E, 0x6E, 0xBC, 0x30},
  {0x18, 0x9E, 0x57, 0xBF, 0xBF, 0x57, 0x9E, 0x18}
};

const byte NOOP = 0x0;
const byte DECODE = 0x9;
const byte INTENSITY = 0xA;
const byte SCANLIMIT = 0xB;
const byte SHUTDOWN = 0xC;
const byte DISPLAYTEST = 0xF;


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

  for (byte j = 0; j < 4; ++j) {
    for (byte i = 0; i < 8; ++i) {
      max7219(i + 1, sprite[j][i]);
    }
    delay(200);
  }
}
