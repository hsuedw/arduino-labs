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
    // Arduino detects that the button has been pressed.
    // To de-bounce, delay 20 ms.
    delay(20);

    // After 20 ms, read the button status again.
    // If the button status is still pressed, 
    // the status of LED will be changed.
    byte swTmpState = digitalRead(SWITCH);

    if (swState == swTmpState) {
      prevSWState = swState;
    }
  }

  if (swState != prevSWState) {
    ledState = !ledState;
    digitalWrite(LED, ledState);
    prevSWState = LOW;  
  }
}
