# Embedded Systems — Arduino Projects

## Project Overview

Welcome to my **Embedded Systems** repository!

This repository contains practical embedded systems projects developed using the **Arduino Uno microcontroller**, C/C++, and electronic components.

The projects focus on microcontroller programming, digital input/output operations, LED control, traffic light systems, pedestrian crossing systems, finite state machines, and hardware-software integration.

Each task includes Arduino implementations and supporting materials such as circuit diagrams, UML diagrams, simulation demonstrations, and technical documentation.

## Technologies and Tools

| Category | Technologies |
|---|---|
| Microcontroller | Arduino Uno |
| Programming Language | Embedded C/C++ |
| Development Environment | Arduino IDE |
| Simulation | Wokwi / Tinkercad Circuits |
| Hardware | Breadboard, LEDs, resistors, push buttons, jumper wires |
| System Modeling | UML Class, State Machine and Sequence Diagrams |
| Version Control | Git and GitHub |

## Repository Structure

```text
Embedded-System/
│
├── Task 1/
│   ├── First_Scenario_Task_1_Basic_Traffic_Light_Circuit.png
│   ├── Task_1_Traffic_Light_State_Diagram.png
│   ├── Task_1_Traffic_Light_UML_Diagram.png
│   ├── README.md
│   └── Task 1 – Sequential Traffic Light LED Blinking
│
├── Task 2/
│   ├── Task_02_Traffic_Light_Circuit.png
│   ├── Task_02_Traffic_Light_Controller.ino
│   ├── Task_02_UML_Class_Diagram.png
│   ├── Task2_Sequence_Diagram.png
│   └── Task 2 - Traffic Light System with Pedestrian Button and Safety Phases.png
│
├── Task 3/
│   ├── Task_03_LED_Blinking.ino
│   └── Task_03_LED_Blinking_Demo.mp4
│
├── Task 4/
│   ├── Task_04_Traffic_Light_Controller.ino
│   └── ask_04_Traffic_Light_Demo_Link.md
│
└── README.md
```

---

## Task 1 — Basic Traffic Light System

### Project Description

Task 1 implements a basic traffic light system using an Arduino Uno and three LEDs representing red, yellow, and green traffic signals.

The traffic lights change automatically according to predefined timing intervals.

### Features

- Automatic traffic light switching
- Red, yellow, and green LED control
- Time-based state transitions
- Finite state machine design
- UML class and state machine diagrams
- Arduino circuit simulation

### Circuit Diagram

![Task 1 Circuit Diagram](Task%201/First_Scenario_Task_1_Basic_Traffic_Light_Circuit.png)

### State Machine Diagram

![Task 1 State Machine Diagram](Task%201/Task_1_Traffic_Light_State_Diagram.png)

### UML Class Diagram

![Task 1 UML Class Diagram](Task%201/Task_1_Traffic_Light_UML_Diagram.png)

### Documentation

[View Task 1 Documentation](Task%201/README.md)

---

## Task 2 — Traffic Light with Pedestrian Button and Safety Phases

### Project Description

Task 2 extends the basic traffic light system by introducing a pedestrian crossing system with a push button.

When a pedestrian presses the button, the Arduino stores the crossing request and activates the pedestrian green light after the required car traffic phases and safety interval.

The system uses a finite state machine with six states to coordinate car and pedestrian traffic lights.

### Features

- Three car traffic lights: red, yellow and green
- Two pedestrian traffic lights: red and green
- Pedestrian push-button detection
- Button debouncing (30 ms)
- Request-based pedestrian crossing
- Six-state traffic light controller
- Two additional all-red safety phases
- Non-blocking timing using `millis()`
- Finite state machine using `enum` and `switch-case`
- UML class, state machine and sequence diagrams

### Hardware Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Breadboard | 1 |
| Car LEDs (Red, Yellow, Green) | 3 |
| Pedestrian LEDs (Red, Green) | 2 |
| Push Button | 1 |
| Current-Limiting Resistors | 5 |
| Jumper Wires | As required |

### Arduino Pin Configuration

| Component | Arduino Pin |
|---|---|
| Car Red LED | 13 |
| Car Yellow LED | 12 |
| Car Green LED | 11 |
| Pedestrian Red LED | 10 |
| Pedestrian Green LED | 9 |
| Pedestrian Push Button | 2 |

The pedestrian push button uses `INPUT_PULLUP`, so a valid button press produces a LOW signal.

### State Machine

The traffic light controller consists of six states:

| State | Description | Duration |
|---|---|---|
| S0 — CAR_GREEN_WAIT | Car Green, Pedestrian Red | 10 seconds |
| S1 — CAR_YELLOW_PHASE | Car Yellow, Pedestrian Red | 3 seconds |
| S2 — CAR_RED_PHASE | Car Red, Pedestrian Red | 5 seconds |
| S3 — SAFETY_BEFORE | Both Signals Red | 2 seconds |
| S4 — PEDESTRIAN_CROSSING | Car Red, Pedestrian Green | 5 seconds |
| S5 — SAFETY_AFTER | Both Signals Red | 2 seconds |

### System Operation

**Without a Pedestrian Request**

CAR_GREEN_WAIT → CAR_YELLOW_PHASE → CAR_RED_PHASE → CAR_GREEN_WAIT

The car traffic lights continue their normal cycle while the pedestrian light remains red.

**With a Pedestrian Request**

CAR_GREEN_WAIT → CAR_YELLOW_PHASE → CAR_RED_PHASE → SAFETY_BEFORE → PEDESTRIAN_CROSSING → SAFETY_AFTER → CAR_GREEN_WAIT

The pedestrian button stores a crossing request until the controller reaches the end of the car-red phase.

### Safety Mechanism

The system maintains two important safety conditions:

1. When the car green light is ON, the pedestrian red light is ON.
2. When the pedestrian green light is ON, the car red light is ON.

Two additional safety phases provide clearance intervals:

- **SAFETY_BEFORE:** Both signals remain red for 2 seconds before pedestrian crossing.
- **SAFETY_AFTER:** Both signals remain red for 2 seconds before cars receive green.

### Circuit Diagram

![Task 2 Circuit Diagram](Task%202/Task_02_Traffic_Light_Circuit.png)

### State Machine Diagram

![Task 2 State Machine Diagram](Task%202/Task%202%20-%20Traffic%20Light%20System%20with%20Pedestrian%20Button%20and%20Safety%20Phases.png)

### UML Class Diagram

![Task 2 UML Class Diagram](Task%202/Task_02_UML_Class_Diagram.png)

### UML Sequence Diagram

![Task 2 Sequence Diagram](Task%202/Task2_Sequence_Diagram.png)

### Source Code

[View Task 2 Arduino Code](Task%202/Task_02_Traffic_Light_Controller.ino)

---

## Task 3 — Arduino LED Blinking

### Project Description

Task 3 demonstrates basic LED control using an Arduino Uno.

The LEDs switch ON and OFF sequentially to demonstrate digital output operations and timing control.

### Features

- Digital output pin configuration
- LED ON/OFF control
- Sequential LED blinking
- Timing using `delay()`
- Arduino Uno programming

### Learning Objectives

- Understand digital output operations
- Use `pinMode()` to configure output pins
- Use `digitalWrite()` to control LEDs
- Understand HIGH and LOW signals
- Implement basic timing using `delay()`

### Arduino Source Code

[View Task 3 LED Blinking Code](Task%203/Task_03_LED_Blinking.ino)

### Demonstration Video

[Watch Task 3 LED Blinking Demo](Task%203/Task_03_LED_Blinking_Demo.mp4)

---

## Task 4 — Arduino Traffic Light Controller

### Project Description

Task 4 demonstrates an Arduino-based traffic light controller.

The project focuses on controlling traffic lights using programmed switching logic and observing the operation through simulation.

### Features

- Arduino traffic light control
- Red, yellow and green LED switching
- Digital output programming
- Time-based light transitions
- Traffic light simulation and demonstration

### Learning Objectives

- Understand traffic light control logic
- Practice Arduino digital output programming
- Implement timed LED transitions
- Test and demonstrate an embedded control system

### Arduino Source Code

[View Task 4 Traffic Light Controller](Task%204/Task_04_Traffic_Light_Controller.ino)

### Demonstration

[View Task 4 Traffic Light Demo Link](Task%204/ask_04_Traffic_Light_Demo_Link.md)

---

## Key Learning Outcomes

Through these projects, I have practiced:

1. Arduino Uno microcontroller programming
2. Embedded C/C++ programming
3. Digital input and output operations (GPIO)
4. LED control and timing
5. Finite state machine design
6. `enum` and `switch-case` programming
7. Non-blocking timing using `millis()`
8. Push-button interfacing and debouncing
9. UML class diagrams
10. UML state machine diagrams
11. UML sequence diagrams
12. Circuit simulation and debugging
13. GitHub version control and technical documentation

## How to Run the Projects

1. Install the Arduino IDE or open an Arduino simulator such as Wokwi or Tinkercad.
2. Navigate to the desired task folder.
3. Open the corresponding `.ino` file.
4. Connect the Arduino Uno and required electronic components.
5. Select Arduino Uno as the target board.
6. Compile and upload the program or start the simulation.
7. Observe the LED behavior and verify the expected output.

## Future Improvements

Possible future extensions include:

- Sensor-based traffic light control
- Interrupt-based push-button handling
- Advanced pedestrian crossing control
- More complex finite state machines
- Additional embedded systems experiments
- Improved simulation and testing

## Conclusion

This repository documents my practical learning and development in embedded systems using Arduino Uno.

The projects demonstrate fundamental concepts of microcontroller programming, digital electronics, traffic light control, UML modeling, circuit simulation, and hardware-software integration.

---

**Embedded Systems | Arduino Uno | C/C++ | UML | Traffic Light Control | Circuit Simulation**
