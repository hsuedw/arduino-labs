#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

DHT dht(2, DHT11);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  dht.begin();
  lcd.init();                                                                         
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("Temp");
  lcd.setCursor(0, 1);
  lcd.print("Humidity");
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed to read");
    lcd.setCursor(0, 1);
    lcd.print("from DHT sensor!");
    return;
  }
  lcd.setCursor(9, 0);
  lcd.print(t, 2);
  lcd.print((char) 0xDF);
  lcd.print("C");

  lcd.setCursor(9, 1);
  lcd.print(h, 2);
  lcd.print("%");

  delay(2000);
}
