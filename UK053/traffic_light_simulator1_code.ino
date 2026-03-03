#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// If LCD doesn't show text, change 0x27 to 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

int red = 13;
int yellow = 12;
int green = 11;

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  lcd.setCursor(0,0);
  lcd.print("Traffic Light");
  delay(2000);
  lcd.clear();
}

void loop()
{
  // ===== GREEN =====
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

  for(int i = 5; i >= 1; i--)
  {
    lcd.setCursor(0,0);
    lcd.print("GO - GREEN     ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("   ");
    delay(1000);
  }

  // ===== YELLOW =====
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);

  for(int i = 3; i >= 1; i--)
  {
    lcd.setCursor(0,0);
    lcd.print("WAIT - YELLOW  ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("   ");
    delay(1000);
  }

  // ===== RED =====
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);

  for(int i = 5; i >= 1; i--)
  {
    lcd.setCursor(0,0);
    lcd.print("STOP - RED     ");
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("   ");
    delay(1000);
  }

  digitalWrite(red, LOW);
}