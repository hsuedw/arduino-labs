
#define LED1 (2)
#define LED2 (3)
#define LED3 (4)
#define LED4 (5)
#define LED5 (6)

byte leds[] = {LED1, LED2, LED3, LED4, LED5};
byte numLeds = sizeof(leds) / sizeof(leds[0]);

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < numLeds; ++i) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < numLeds - 1; ++i) {
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
  }

  for (int i = numLeds - 1; i > 0; --i) {
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
  }
}
