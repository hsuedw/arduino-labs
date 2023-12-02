
#define SW_PIN (7)
#define LED_PIN (12)

unsigned long lastTime = 0;
const long interval = 3000;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long now = millis();
  bool val = digitalRead(SW_PIN);

  digitalWrite(LED_PIN, !val);

  if (now - lastTime >= interval) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    lastTime = now;
  }
}
