# 🚦 Smart Traffic Management System (Tinkercad Simulation)

This sub-project focuses on a **density-aware and accessible** traffic signaling system. It uses an I2C-enabled LCD for real-time countdowns and synchronized audio feedback for enhanced safety.

## 🖼️ Circuit Design
![Traffic Simulator Circuit Design]()

## 🛠️ Components List
* **Microcontroller:** Arduino Uno R3
* **Display:** 16x2 LCD with I2C Module (PCF8574)
* **Visual Output:** High-intensity LEDs (Red, Yellow, Green)
* **Audio Output:** Piezo Buzzer (5V)
* **Passive Components:** 220Ω Resistors (x3)

## 🔊 Acoustic Signaling Logic (UX Optimization)
Unlike standard beepers, this system uses specific frequencies to reduce noise pollution while maintaining safety:
* **RED Phase Start:** A single **2-second "Stop Alert" at 500Hz**. This lower frequency provides a "smooth" yet firm warning for vehicles to clear the junction.
* **GREEN Phase:** A **1Hz pulsing tone at 600Hz**. This acts as an **Acoustic Pedestrian Signal (APS)**, assisting visually impaired users in crossing safely.
* **YELLOW Phase:** Silent transition to minimize unnecessary noise during short intervals.

## 📜 Code Features
* **Memory Efficient:** Uses `byte` data types for pin mapping to save SRAM.
* **Non-Blocking Logic:** The countdown function manages the LCD refresh and Buzzer tones simultaneously.
* **I2C Integration:** Reduced wiring complexity by using only 2 data pins (SDA/SCL) for the display.

## 📂 Project Structure
* `traffic_logic.ino`: Main Arduino C++ source code.
* `README.md`: Project documentation and logic overview.
* `components.txt`: Detailed hardware pin mapping.
