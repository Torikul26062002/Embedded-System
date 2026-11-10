# Embedded Systems — Arduino Projects

## Project Overview

Welcome to my **Embedded Systems** repository!

This repository contains practical embedded systems projects developed using the **Arduino Uno microcontroller**, C/C++, and electronic components.

The projects focus on microcontroller programming, LED control, traffic light systems, pedestrian crossing systems, finite state machines, and hardware-software integration.

Each task demonstrates different concepts of embedded systems programming, supported by source code, simulations, and technical documentation.

## Technologies and Tools

- **Microcontroller:** Arduino Uno
- **Programming Language:** Embedded C/C++ (Arduino)
- **Development Environment:** Arduino IDE
- **Simulation Tools:** Wokwi / Tinkercad Circuits
- **Hardware:** Breadboard, LEDs, resistors, push buttons, jumper wires
- **System Modeling:** UML class, state machine, and sequence diagrams
- **Version Control:** Git and GitHub

## Repository Structure

```text
Embedded-System/
│
├── Task 1/
│   └── Basic Traffic Light System
│
├── Task 2/
│   └── Traffic Light with Pedestrian Crossing
│
├── Task 3/
│   ├── Task_03_LED_Blinking.ino
│   └── Task_03_LED_Blinking_Demo.mp4
│
├── Task 4/
│   ├── Task_04_Traffic_Light_Controller.ino
│   └── Traffic Light Demo Link (.md)
│
└── README.md
```

## Project Descriptions

### Task 1 — Basic Traffic Light System

This project implements a basic traffic light controller using an Arduino Uno and three LEDs.

**Features:**
- Red, yellow, and green LED control
- Automatic traffic light switching
- Time-based state transitions
- Finite state machine implementation
- UML modeling and circuit simulation

### Task 2 — Traffic Light with Pedestrian Crossing

This project extends Task 1 by introducing a pedestrian crossing system with a push button.

**Features:**
- Car traffic lights (red, yellow, green)
- Pedestrian traffic lights (red, green)
- Pedestrian push-button detection
- Button debouncing
- Request-based pedestrian crossing
- Six-state traffic light controller
- Two all-red safety phases
- Timing control using `millis()`
- UML state machine and sequence diagrams

The system ensures that car and pedestrian green lights are not activated simultaneously.

### Task 3 — Arduino LED Blinking

This project demonstrates basic LED blinking using an Arduino Uno.

**Features:**
- Digital output pin configuration
- LED ON/OFF control
- Sequential LED blinking
- Timing using `delay()`
- Practical Arduino demonstration

**Files:**
- `Task_03_LED_Blinking.ino` — Arduino source code
- `Task_03_LED_Blinking_Demo.mp4` — Demonstration video

**Learning Objective:**

Understand how Arduino controls digital outputs and how LEDs can be switched using simple programming instructions.

### Task 4 — Traffic Light Controller

This project demonstrates an Arduino-based traffic light controller.

**Features:**
- Traffic light control using Arduino
- LED switching logic
- Time-based light transitions
- Embedded system simulation
- Demonstration link for project testing

**Files:**
- `Task_04_Traffic_Light_Controller.ino` — Arduino source code
- Markdown file containing the traffic light demonstration link

**Learning Objective:**

Develop practical experience implementing and testing traffic light control logic using an Arduino microcontroller.

## Key Learning Outcomes

Through these projects, I am developing skills in:

1. Arduino Uno programming
2. Embedded C/C++
3. Digital input and output (GPIO)
4. LED control and timing
5. Finite state machines
6. `switch-case` programming
7. Non-blocking timing with `millis()`
8. Push-button interfacing and debouncing
9. UML modeling
10. Circuit simulation and debugging
11. GitHub version control and documentation

## How to Run the Projects

1. Install the Arduino IDE or open Wokwi/Tinkercad.
2. Open the desired task folder.
3. Download or open the corresponding `.ino` file.
4. Connect the Arduino Uno and required components.
5. Select Arduino Uno as the target board.
6. Compile and upload the code or start the simulation.
7. Observe the LED behavior and verify the expected results.

## Project Documentation

The repository contains Arduino source code and supporting materials, including:

- UML diagrams
- State machine diagrams
- Sequence diagrams
- Circuit designs
- Simulation demonstrations
- Task-specific documentation

## Future Improvements

Possible future extensions include:

- Sensor-based traffic light control
- Interrupt-based button handling
- Additional pedestrian crossing features
- More advanced finite state machines
- Improved simulation and testing

## Conclusion

These projects demonstrate fundamental concepts of embedded systems development through practical Arduino applications.

The repository documents my progress in microcontroller programming, circuit implementation, system modeling, and hardware-software integration.

---

**Embedded Systems | Arduino Uno | C/C++ | Traffic Light Control | UML | Circuit Simulation**
