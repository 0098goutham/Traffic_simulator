#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for 16x2 display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions
const byte redLED = 8;
const byte yellowLED = 9;
const byte greenLED = 10;
const byte buzzerPin = 11;

/**
 * countdown function
 * @param time - seconds to count down
 * @param lightName - text to show on Line 1
 * @param isGreen - if true, pulses the buzzer every second
 * @param isRedStart - if true, triggers a single 2-second long beep at the start
 */
void countdown(int time, String lightName, bool isGreen, bool isRedStart) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(lightName);
  
  for (int i = time; i > 0; i--) { 
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    
    // Formatting: Add leading zero for single digits
    if (i < 10) lcd.print("0"); 
    lcd.print(i);
    lcd.print("s ");

    // --- AUDIO LOGIC ---
    
    // 1. Initial 2-second Warning for RED
    if (isRedStart && i == time) {
      tone(buzzerPin, 400); // 800Hz warning tone
      delay(2000);          // 2-second long beep
      noTone(buzzerPin);
      // We subtract 2 from the loop because the beep took 2 seconds
      i = i - 1; 
    } 
    // 2. Pulsing Beeps for GREEN (Pedestrian safe)
    else if (isGreen) {
      tone(buzzerPin, 400); // 1KHz crossing tone
      delay(100);            // Short chirp
      noTone(buzzerPin);
      delay(900);            // Wait for rest of the second
    } 
    // 3. Standard Delay for YELLOW/RED (after initial beep)
    else {
      delay(1000);
    }
  }
}

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  // Initial LCD Greeting
  lcd.setCursor(0,0);
  lcd.print("Traffic System");
  lcd.setCursor(0,1);
  lcd.print("Initializing...");
  delay(2000);
}

void loop() {
  // --- RED PHASE ---
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  // Parameters: 8s, Label, IsGreen=False, IsRedStart=True
  countdown(8, "RED - STOP!", false, true);
  
  // --- GREEN PHASE ---
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  // Parameters: 8s, Label, IsGreen=True, IsRedStart=False
  countdown(8, "GREEN - GO GO", true, false);
  
  // --- YELLOW PHASE ---
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, LOW);
  // Parameters: 3s, Label, IsGreen=False, IsRedStart=False
  countdown(3, "YELLOW - WAIT", false, false);
}