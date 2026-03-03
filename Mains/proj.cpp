#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int red = 8;
int yellow = 9;
int green = 10;

void showSignal(String name, int pin, int timeSec) {
  
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  
  digitalWrite(pin, HIGH);

  for (int i = timeSec; i > 0; i--) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(name);
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(i);
    delay(1000);
  }
}

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  showSignal("GREEN SIGNAL", green, 5);
  showSignal("YELLOW SIGNAL", yellow, 3);
  showSignal("RED SIGNAL", red, 5);
}