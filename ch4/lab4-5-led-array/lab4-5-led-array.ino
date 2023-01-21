
#define LED1 (2)
#define LED2 (3)
#define LED3 (4)
#define LED4 (5)
#define LED5 (6)

const byte firstLed = LED1;
const byte lastLed = LED5;
byte currLed = firstLed;

void setup() {
  // put your setup code here, to run once:
  for (int led = LED1; led <= LED5; ++led) {
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(currLed, HIGH);
  delay(200);
  digitalWrite(currLed, LOW);
  
  if (currLed < lastLed) {
    ++currLed;
  } else {
    currLed = firstLed;
  }
}
