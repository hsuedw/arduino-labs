const byte SEG_PIN[2] = {8, 9};
const byte NUM_OF_SEG = sizeof(SEG_PIN);
int number = 0;
byte digits[2] = {0, 0};
const byte dataPin = 2;
const byte latchPin = 3;
const byte clockPin = 4;

unsigned long previousMills = 0;
const long interval = 1000;

const byte LEDs[10] = {
  0x7E, 0x30, 0x6D, 0x79, 0x33,
  0x5B, 0x5F, 0x70, 0x7F, 0x73
};

// 每隔一秒數字加一，並猜解數字
void counter() {
  unsigned long currentMills = millis();

  if (currentMills - previousMills >= interval) {
    previousMills = currentMills;

    if (++number > 99) {
      number = 0;
    }

    digits[0] = number %10;
    digits[1] = number /10 %10;
  }
}

void display() {
  byte num;

  for (byte i = 0; i < NUM_OF_SEG; i++) {
    num = digits[i];

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LEDs[num]);
    digitalWrite(latchPin, HIGH);

    digitalWrite(SEG_PIN[i], LOW);
    delay(5);

    for (byte j = 0; j < NUM_OF_SEG; j++) {
      digitalWrite(SEG_PIN[j], HIGH);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (byte i = 0; i < NUM_OF_SEG; i++) {
    pinMode(SEG_PIN[i], OUTPUT);
    digitalWrite(SEG_PIN[i], HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  counter();
  display();
}
