#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int red = 8;
int yellow = 9;
int green = 10;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {

  // GREEN SIGNAL
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GREEN SIGNAL");
  delay(5000);


  // YELLOW SIGNAL
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("YELLOW SIGNAL");
  delay(3000);


  // RED SIGNAL
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RED SIGNAL");
  delay(5000);
}