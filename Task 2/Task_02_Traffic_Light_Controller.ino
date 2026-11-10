
const int carRed = 13;
const int carYellow = 12;
const int carGreen = 11;

const int pedRed = 10;
const int pedGreen = 9;

const int pedButton = 2;

// Timing in milliseconds
const unsigned long greenTime = 10000;
const unsigned long yellowTime = 3000;
const unsigned long redTime = 5000;
const unsigned long crossingTime = 5000;

// Traffic states
enum TrafficState {
  CAR_GREEN_WAIT,
  CAR_YELLOW_PHASE,
  CAR_RED_PHASE,
  PEDESTRIAN_CROSSING
};

TrafficState currentState = CAR_GREEN_WAIT;

unsigned long previousMillis = 0;
bool pedestrianRequested = false;

// Button debounce
bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 30;

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);

  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);

  pinMode(pedButton, INPUT_PULLUP);

  // Initial state: Cars green, pedestrians red
  digitalWrite(carRed, LOW);
  digitalWrite(carYellow, LOW);
  digitalWrite(carGreen, HIGH);

  digitalWrite(pedRed, HIGH);
  digitalWrite(pedGreen, LOW);

  previousMillis = millis();
}

void loop() {
  unsigned long currentMillis = millis();

  // Detect button press with debounce
  bool reading = digitalRead(pedButton);

  if (reading != lastButtonReading) {
    lastDebounceTime = currentMillis;
  }

  if (currentMillis - lastDebounceTime >= debounceDelay) {
    if (reading != stableButtonState) {
      stableButtonState = reading;

      if (stableButtonState == LOW &&
          currentState != PEDESTRIAN_CROSSING) {
        pedestrianRequested = true;
      }
    }
  }

  lastButtonReading = reading;

  switch (currentState) {

    // State 0: Cars green for at least 10 seconds
    case CAR_GREEN_WAIT:
      digitalWrite(carRed, LOW);
      digitalWrite(carYellow, LOW);
      digitalWrite(carGreen, HIGH);

      digitalWrite(pedRed, HIGH);
      digitalWrite(pedGreen, LOW);

      if (currentMillis - previousMillis >= greenTime) {
        previousMillis = currentMillis;
        currentState = CAR_YELLOW_PHASE;
      }
      break;

    // State 1: Cars yellow for 3 seconds
    case CAR_YELLOW_PHASE:
      digitalWrite(carRed, LOW);
      digitalWrite(carYellow, HIGH);
      digitalWrite(carGreen, LOW);

      digitalWrite(pedRed, HIGH);
      digitalWrite(pedGreen, LOW);

      if (currentMillis - previousMillis >= yellowTime) {
        previousMillis = currentMillis;
        currentState = CAR_RED_PHASE;
      }
      break;

    // State 2: Cars red, pedestrians red
    case CAR_RED_PHASE:
      digitalWrite(carRed, HIGH);
      digitalWrite(carYellow, LOW);
      digitalWrite(carGreen, LOW);

      digitalWrite(pedRed, HIGH);
      digitalWrite(pedGreen, LOW);

      if (currentMillis - previousMillis >= redTime) {
        previousMillis = currentMillis;

        if (pedestrianRequested) {
          pedestrianRequested = false;
          currentState = PEDESTRIAN_CROSSING;
        } else {
          currentState = CAR_GREEN_WAIT;
        }
      }
      break;

    // State 3: Pedestrians green for 5 seconds
    case PEDESTRIAN_CROSSING:
      digitalWrite(carRed, HIGH);
      digitalWrite(carYellow, LOW);
      digitalWrite(carGreen, LOW);

      digitalWrite(pedRed, LOW);
      digitalWrite(pedGreen, HIGH);

      if (currentMillis - previousMillis >= crossingTime) {
        previousMillis = currentMillis;
        currentState = CAR_GREEN_WAIT;
      }
      break;
  }
}
