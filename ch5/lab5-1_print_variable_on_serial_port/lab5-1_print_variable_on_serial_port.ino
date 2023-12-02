char val;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  Serial.print("Welcome to Arduino!");

  val = '0';
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
    if ('1' <= val && val <= '9') {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED ON");
      val = '1';
    } else {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED OFF");
      val = '0';
    }
  }
}
