# 🚦 Tinkercad Traffic Simulator Design

This folder contains the circuit simulation and logic for the Traffic Simulator project.

## 🖼️ Circuit Preview
![Circuit Schematic](./your_image_name.png)
*Link to Tinkercad: [Paste your Tinkercad Public Link Here]*

## 🛠️ Components Used
* **Microcontroller:** Arduino Uno R3
* **Sensors:** 4x PIR/IR Sensors (for vehicle detection)
* **Outputs:** 12x LEDs (Red, Yellow, Green for 4-way junction)
* **Resistors:** 12x 220Ω Resistors

## 📜 Logic Overview
The code implements a **Density-Based Traffic Control System**. 
1. The sensors check for vehicle presence on each road.
2. If density is high on Road A, the Green light duration is extended.
3. Uses `millis()` for non-blocking timing to ensure smooth transitions.

## 📂 Files in this Folder
* `traffic_logic.ino` - The primary Arduino/C++ code.
* `schematic.png` - Full circuit wiring diagram.
* `components.txt` - Detailed list of hardware.