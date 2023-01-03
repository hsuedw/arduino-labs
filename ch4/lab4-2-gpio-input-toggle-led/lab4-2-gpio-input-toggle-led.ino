#define SWITCH (2)
#define LED (6)

#define HIGH (1)
#define LOW (0)

byte ledState = LOW;
byte prevSWState = LOW;
byte swState = LOW;

void setup() {
  // Setup the GPIO pins.
  pinMode(SWITCH, INPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, ledState);
}

void loop() {
  swState = digitalRead(SWITCH);

  if (swState) {
    prevSWState = swState;
  }

  if (swState != prevSWState) {
    ledState = !ledState;
    digitalWrite(LED, ledState);
    prevSWState = LOW;  
  }
}
