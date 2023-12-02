
#define SW_PIN (7)
#define LED_PIN (12)

void setup() {
  pinMode(SW_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool val = digitalRead(SW_PIN);

  digitalWrite(LED_PIN, !val);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(10000);
}
