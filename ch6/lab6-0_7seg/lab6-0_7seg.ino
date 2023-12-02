int index = 9;
const byte LEDs[10] = {
  B1111110,
  B0110000,
  B1101101,
  B1111001,
  B0110011,
  B1011011,
  B1011111,
  B1110000,
  B1111111,
  B1111011
};

void setup() {
  // put your setup code here, to run once:
  //DDRD = B11111111;
  for (int i = 0; i < 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD = LEDs[index];

  index--;
  if (index < 0) {
    index = 9;
  }
  delay(1000);
}
