# Arduino Traffic Light System with Pedestrian Crossing

## Project Overview

This project implements a traffic light control system with a pedestrian crossing feature using an **Arduino Uno**.

The system simulates a real-world traffic intersection where vehicles follow a traffic light sequence and pedestrians can request permission to cross by pressing a push button.

The program uses a **finite state machine (FSM)** and the Arduino `millis()` function to manage the traffic light sequence without relying on blocking delays.

## Hardware Components

- Arduino Uno
- Breadboard
- 3 LEDs for vehicle traffic (Red, Yellow, Green)
- 2 LEDs for pedestrian traffic (Red, Green)
- Push button
- Current-limiting resistors for the LEDs (e.g., 220 Ω)
- Jumper wires
- USB cable for programming the Arduino

## Pin Configuration

| Component | Arduino Pin |
|---|---|
| Vehicle Red LED | 13 |
| Vehicle Yellow LED | 12 |
| Vehicle Green LED | 11 |
| Pedestrian Red LED | 10 |
| Pedestrian Green LED | 9 |
| Pedestrian Push Button | 2 |

The push button uses Arduino's internal pull-up resistor (`INPUT_PULLUP`). The button is connected between digital pin 2 and GND.

## Working Principle

### 1. Normal Traffic Operation

- The vehicle green light is ON.
- The pedestrian red light is ON.
- Vehicles are allowed to move while pedestrians must wait.

### 2. Pedestrian Request

- A pedestrian presses the push button.
- The Arduino detects the button press.
- The request is stored in a Boolean variable.
- Software debouncing helps prevent false button detections.

### 3. Vehicle Yellow Phase

- The vehicle green light turns OFF.
- The vehicle yellow light turns ON.
- Drivers are warned to prepare to stop.

### 4. Vehicle Red Phase

- The vehicle yellow light turns OFF.
- The vehicle red light turns ON.
- Vehicles must stop before pedestrians are allowed to cross.

### 5. Pedestrian Crossing

- The pedestrian red light turns OFF.
- The pedestrian green light turns ON.
- Pedestrians are allowed to cross while vehicles remain stopped.

### 6. Return to Normal Operation

- The pedestrian green light turns OFF.
- The pedestrian red light turns ON.
- The vehicle green light turns ON.
- The system returns to its initial state and waits for another pedestrian request.

## Software Design

The project uses a finite state machine with four states:

```cpp
enum TrafficState {
  CAR_GREEN_WAIT,
  CAR_YELLOW_PHASE,
  CAR_RED_PHASE,
  PEDESTRIAN_CROSSING
};
```

Each state represents a specific operating phase of the traffic light system.

### Non-Blocking Timing

The program uses `millis()` to measure elapsed time instead of using `delay()`.

This allows the Arduino to continue checking the push button while managing the traffic light sequence.

### Button Debouncing

A debounce interval of 30 milliseconds is used to filter mechanical button bouncing.

### Pedestrian Request Handling

A Boolean variable stores the pedestrian request so the program can process it through the traffic light sequence.

## Project Files

| File | Description |
|---|---|
| `traffic_light.ino` | Arduino source code |
| `Traffic_light_pedestrian_class_diagram.png` | Project class diagram |
| `A fraffic light system with padestrian light.png` | Traffic light system illustration |

## How to Run the Project

1. Install the Arduino IDE.
2. Connect the Arduino Uno to your computer using a USB cable.
3. Connect the LEDs, resistors, and push button to the breadboard according to the pin configuration.
4. Open `traffic_light.ino` in Arduino IDE.
5. Select **Arduino Uno** under Tools → Board.
6. Select the correct port under Tools → Port.
7. Click **Verify** to compile the program.
8. Click **Upload** to transfer the program to the Arduino.
9. Press the pedestrian push button to test the traffic light sequence.

## Learning Outcomes

This project demonstrates:

- Arduino digital input and output
- LED control
- Push-button input handling
- Internal pull-up resistors
- Software button debouncing
- Finite state machine programming
- Non-blocking timing using `millis()`
- Basic embedded-system control logic

## Safety Note

This project is an educational traffic light simulation and is not intended for use in real road traffic control systems.

## Development Environment

- **Microcontroller:** Arduino Uno
- **Programming Language:** Arduino C/C++
- **Development Software:** Arduino IDE
- **Version Control:** Git and GitHub
