#define SWITCH (2)
#define LED (6)

void setup() {
  // put your setup code here, to run once:
  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool inputVal = digitalRead(SWITCH);
  digitalWrite(LED, inputVal);
}
