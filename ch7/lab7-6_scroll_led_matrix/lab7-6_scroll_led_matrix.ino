#include <SPI.h>
#include "fonts.h"

byte buffer[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//char msg[] = {'A', 'r', 'd', 'u', 'i', 'n', 'o', ' '};
char msg[] = {'A', 'n', 'g', 'u', 's', ' '};
//char msg[] = {'E', 'd', 'w', 'a', 'r', 'd', ' '};
int msgSize = sizeof(msg);
  
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

void scroll(byte chr) {
  for (byte j = 0; j < 8; ++j) {
    for (byte i = 0; i < 7; ++i) {
      buffer[i] = buffer[i + 1];
      max7219(i + 1, buffer[i]);
    }
    buffer[7] = fonts[chr][j];
    max7219(8, buffer[7]);
    delay(500);
  }
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
  byte chr;

  for (int i = 0; i < msgSize; ++i) {
    chr = msg[i];
    scroll(chr);
  }
}
