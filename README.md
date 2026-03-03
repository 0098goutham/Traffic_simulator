# Traffic Light Simulator with I2C LCD



A microcontroller-based traffic management system that mimics real-world signal sequences. This project features an \*\*Arduino Uno\*\*, high-visibility LEDs, and a \*\*16x2 LCD\*\* interface using the I2C protocol for real-time status updates and live countdown timers.


## 🚀 Overview

This simulator provides a visual and functional representation of a standard traffic intersection. 

\* \*\*Logic:\*\* Implements the Red → Green → Yellow sequence.

\* \*\*Efficiency:\*\* Uses I2C communication to reduce the wiring footprint to just 4 pins for the LCD.

\* \*\*User Interface:\*\* Displays a live countdown timer for each phase to inform "drivers" of the remaining duration.

---


## 🛠️ Hardware Components

| Component | Quantity | Purpose |

| :--- | :--- | :--- |

| \*\*Arduino Uno R3\*\* | 1 | System Controller |

| \*\*16x2 LCD (with I2C)\*\* | 1 | State \& Timer Display |

| \*\*LEDs (R, Y, G)\*\* | 3 | Traffic Signals |

| \*\*220Ω Resistors\*\* | 3 | Current limiting for LEDs |

| \*\*Breadboard \& Wires\*\* | 1 | Circuit Prototyping |



---


## 🖇️ Circuit Configuration



The circuit is designed for simplicity and reliability. Below is the pin mapping:



### LED Connections

\* \*\*Red LED:\*\* Pin 13

\* \*\*Yellow LED:\*\* Pin 12

\* \*\*Green LED:\*\* Pin 11



### LCD (I2C) Connections

\* \*\*SCL:\*\* Pin A5

\* \*\*SDA:\*\* Pin A4

\* \*\*VCC:\*\* 5V

\* \*\*GND:\*\* Ground



---



## 💻 Software Logic

The firmware is built in C++ and utilizes the `Adafruit\_LiquidCrystal` library. The core logic is encapsulated in the `showPhase()` function, which handles LED actuation, LCD messaging, and a precise 1-second countdown loop.



```cpp

void loop() {

&nbsp; // Sequence: Red (5s) -> Green (5s) -> Yellow (3s)

&nbsp; showPhase(HIGH, LOW, LOW, "RED - STOP!", 5);

&nbsp; showPhase(LOW, LOW, HIGH, "GREEN - GO GO", 5);

&nbsp; showPhase(LOW, HIGH, LOW, "YELLOW - WAIT", 3);

}

```



## ⚙️ Setup Instructions

1\. \*\*Hardware:\*\* Wire the components as per the circuit description above.

2\. \*\*Libraries:\*\* Open the Arduino Library Manager and install:

\* `Adafruit LiquidCrystal`

\* `Wire.h` (Built-in)

3\. \*\*Upload:\*\* Connect your Arduino via USB and upload the provided `.ino` file.

4. **Simulation:** You can view and run the project online via [Tinkercad Traffic Light Simulator](https://www.tinkercad.com/things/8mny8VDLIAQ-mini-project-traffic-simulator?sharecode=QOwnRuXn3igLao3jpFfystlotIsorkCzA727tHLX5jU)

---

## 🌟 Future Scope

\* \*\*Sensor Integration:\*\* Adding ultrasonic sensors to detect vehicle presence and adjust timing dynamically.

\* \*\*Pedestrian Mode:\*\* Adding a physical interrupt button for pedestrian crossing requests.

---

## 👤 Author

\*\*Developed by Cohort 6 Group\*\*





