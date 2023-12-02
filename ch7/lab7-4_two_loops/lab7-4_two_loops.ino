void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int y = 0; y < 3; ++y) {
    for (int x = 0; x < 6; ++x) {
      Serial.print('*');
    }
    Serial.print('\n');
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
