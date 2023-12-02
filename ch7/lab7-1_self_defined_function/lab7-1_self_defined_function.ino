
float pow(int r, int p) {
  int ans = 1;
  for (int i = 1; 0 < i && i <= p; ++i) {
    ans = ans * r;
  }
  return ans;
}

float cirArea(int r) {
  return 3.14 * pow(r, 2);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  float ans;
  ans = cirArea(10);
  Serial.println(ans);
  ans = cirArea(20);
  Serial.println(ans);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Edward");
}
