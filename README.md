# Embedded Systems — Arduino Projects

Welcome to my **Embedded Systems** repository!

This repository contains practical embedded systems projects developed using the **Arduino Uno**, C/C++, and electronic components.

The projects focus on microcontroller programming, digital input/output operations, traffic light control, finite state machines, hardware-software integration, and simulation.

## Technologies and Tools

| Category | Technologies |
|---|---|
| Microcontroller | Arduino Uno |
| Programming | Embedded C/C++ |
| Development | Arduino IDE |
| Simulation | Wokwi, Tinkercad Circuits |
| Hardware | LEDs, resistors, breadboard, push buttons |
| Modeling | UML Class, State Machine, Sequence Diagrams |
| Version Control | Git and GitHub |

## Repository Structure

```text
Embedded-System/
│
├── Task 1/
│   └── Traffic Light System
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
├── images/
│   ├── task1_circuit.png
│   ├── task1_state_diagram.png
│   ├── task2_circuit.png
│   ├── task2_state_diagram.png
│   ├── task2_sequence_diagram.png
│   └── task3_led_demo.png
│
└── README.md
```

*The `images/` folder contains suggested filenames for the project gallery. Upload your images using these names or update the paths below.*

---

## Task 1 — Basic Traffic Light System

### Project Description

This project implements a basic traffic light controller using an Arduino Uno and three LEDs: red, yellow, and green.

The traffic lights operate automatically according to predefined timing intervals.

### Features

- Automatic traffic light switching
- Red, yellow, and green LED control
- Time-based state transitions
- Finite state machine implementation
- UML class and state machine diagrams
- Arduino circuit simulation

### Circuit Diagram

![Task 1 Circuit Diagram](images/task1_circuit.png)

### State Machine Diagram

![Task 1 State Machine](images/task1_state_diagram.png)

---

## Task 2 — Traffic Light with Pedestrian Crossing

### Project Description

This project extends Task 1 by adding a pedestrian crossing system with a push button.

When a pedestrian presses the button, the Arduino stores the crossing request and activates the pedestrian green light after the required car traffic light phases and safety interval.

The system uses six states to coordinate the car and pedestrian traffic lights.

### Features

- Car traffic lights: red, yellow, green
- Pedestrian traffic lights: red, green
- Pedestrian push-button input
- Button debouncing
- Finite state machine using `enum` and `switch-case`
- Non-blocking timing using `millis()`
- Two additional all-red safety phases
- UML modeling and simulation

### Arduino Pin Configuration

| Component | Arduino Pin |
|---|---|
| Car Red LED | 13 |
| Car Yellow LED | 12 |
| Car Green LED | 11 |
| Pedestrian Red LED | 10 |
| Pedestrian Green LED | 9 |
| Push Button | 2 |

### State Machine Timing

| State | Description | Duration |
|---|---|---|
| S0 | Car Green | 10 seconds |
| S1 | Car Yellow | 5 seconds |
| S2 | Car Red | 5 seconds |
| S3 | Safety Before Crossing | 2 seconds |
| S4 | Pedestrian Crossing | 5 seconds |
| S5 | Safety After Crossing | 2 seconds |

### Safety Conditions

The system follows two important safety rules:

1. When the car green light is ON, the pedestrian red light must be ON.
2. When the pedestrian green light is ON, the car red light must be ON.

Both car and pedestrian lights remain red during the safety phases.

### Circuit Diagram

![Task 2 Circuit Diagram](images/task2_circuit.png)

### State Machine Diagram

![Task 2 State Machine](images/task2_state_diagram.png)

### UML Sequence Diagram

![Task 2 Sequence Diagram](images/task2_sequence_diagram.png)

### System Operation

**Without a pedestrian request:**

Car Green → Car Yellow → Car Red → Car Green

**With a pedestrian request:**

Car Green → Car Yellow → Car Red → Safety Before → Pedestrian Green → Safety After → Car Green

---

## Task 3 — Arduino LED Blinking

### Project Description

This project demonstrates basic LED control using an Arduino Uno.

The LEDs are switched ON and OFF sequentially to demonstrate digital output operations and timing control.

### Features

- Arduino digital output control
- LED blinking
- Sequential LED switching
- Timing using `delay()`
- Basic circuit implementation

### Source Code

[View Arduino LED Blinking Code](Task%203/Task_03_LED_Blinking.ino)

### Demonstration Video

[Watch Task 3 LED Blinking Demo](Task%203/Task_03_LED_Blinking_Demo.mp4)

### Project Image

![Task 3 LED Blinking](images/task3_led_demo.png)

---

## Task 4 — Arduino Traffic Light Controller

### Project Description

This project demonstrates an Arduino-based traffic light controller using digital output pins and programmed timing intervals.

The project focuses on implementing traffic light switching logic and observing its operation through simulation.

### Features

- Arduino traffic light control
- Red, yellow, and green LED switching
- Time-based light transitions
- Digital output programming
- Traffic light demonstration

### Source Code

[View Task 4 Arduino Code](Task%204/Task_04_Traffic_Light_Controller.ino)

### Demonstration

The Task 4 folder includes a Markdown file containing the traffic light demonstration link.

---

## Key Learning Outcomes

Through these projects, I have practiced:

- Arduino Uno microcontroller programming
- Embedded C/C++
- Digital input/output operations
- LED control and timing
- Finite state machine design
- `switch-case` programming
- Non-blocking timing with `millis()`
- Push-button interfacing
- Button debouncing
- UML class diagrams
- State machine diagrams
- Sequence diagrams
- Circuit simulation and debugging
- GitHub version control and documentation

## How to Run the Projects

1. Install the Arduino IDE or open Wokwi/Tinkercad.
2. Navigate to the desired task folder.
3. Open the corresponding `.ino` file.
4. Connect the Arduino Uno and required electronic components.
5. Select Arduino Uno as the target board.
6. Compile and upload the program or start the simulation.
7. Observe the LED behavior and verify the expected output.

## Future Improvements

Future extensions may include:

- Sensor-based traffic light control
- Interrupt-based push-button handling
- Advanced pedestrian crossing control
- More complex finite state machines
- Additional embedded systems experiments

## Conclusion

This repository documents my practical learning and development in embedded systems using Arduino Uno.

The projects demonstrate fundamental concepts of microcontroller programming, digital electronics, traffic light control, UML modeling, and hardware-software integration.

---

**Embedded Systems | Arduino Uno | C/C++ | UML | Traffic Light Control | Circuit Simulation**
