#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

#define RED 13
#define YELLOW 12
#define GREEN 11

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
}

void showPhase(int r, int y, int g, const char* text, int timeSec) {
  // 1. Set the LEDs
  digitalWrite(RED, r);
  digitalWrite(YELLOW, y);
  digitalWrite(GREEN, g);

  // 2. Setup the LCD static text
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text);

  // 3. Run the countdown timer
  for (int i = timeSec; i > 0; i--) {
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    
    // Add a leading zero for numbers under 10
    if (i < 10) {
      lcd.print("0");
    }
    lcd.print(i);
    lcd.print("s "); // Trailing space clears leftover digits
    delay(1000);
  }
}

void loop() {
  // Corrected real-world traffic sequence
  showPhase(HIGH, LOW, LOW, "RED - STOP!", 5);
  showPhase(LOW, LOW, HIGH, "GREEN - GO GO", 5);
  showPhase(LOW, HIGH, LOW, "YELLOW - WAIT", 3);
}