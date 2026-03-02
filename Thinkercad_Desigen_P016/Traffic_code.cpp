#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// (If 0x27 doesn't work, try 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Using 'byte' instead of 'int' saves memory space 
const byte redLED = 8;
const byte yellowLED = 9;
const byte greenLED = 10;

void countdown(int time, String lightName) {
  lcd.clear(); // Clear ONCE before the loop to prevent screen flickering
  lcd.setCursor(0, 0);
  lcd.print(lightName);
  
  for (int i = time; i > 0; i--) { 
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    
    // Add a leading zero for cleaner formatting (e.g., 09, 08)
    if (i < 10) {
      lcd.print("0"); 
    }
    lcd.print(i);
    lcd.print("s "); // Extra space to cleanly overwrite leftover characters
    
    delay(1000);
  }
}

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  // Initialize the I2C LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  countdown(8, "RED");
  
  // Red to Green (Standard traffic sequence)
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  countdown(8, "GREEN");
  
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, LOW);
  countdown(3, "YELLOW");
}