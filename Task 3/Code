
const int carRed = 13;
const int carYellow = 12;
const int carGreen = 11;

const int pedRed = 10;
const int pedGreen = 9;

const int pedButton = 2;

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

  previousMillis = millis();
}

void loop() {
  unsigned long currentMillis = millis();

  // Detect a new button press
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

    case CAR_GREEN_WAIT:
      digitalWrite(carGreen, HIGH);
      digitalWrite(carYellow, LOW);
      digitalWrite(carRed, LOW);
      digitalWrite(pedGreen, LOW);
      digitalWrite(pedRed, HIGH);

      if (currentMillis - previousMillis >= 5000) {
        previousMillis = currentMillis;
        currentState = CAR_YELLOW_PHASE;
      }
      break;

    case CAR_YELLOW_PHASE:
      digitalWrite(carGreen, LOW);
      digitalWrite(carYellow, HIGH);
      digitalWrite(carRed, LOW);
      digitalWrite(pedGreen, LOW);
      digitalWrite(pedRed, HIGH);

      if (currentMillis - previousMillis >= 2000) {
        previousMillis = currentMillis;
        currentState = CAR_RED_PHASE;
      }
      break;

    case CAR_RED_PHASE:
      digitalWrite(carGreen, LOW);
      digitalWrite(carYellow, LOW);
      digitalWrite(carRed, HIGH);
      digitalWrite(pedGreen, LOW);
      digitalWrite(pedRed, HIGH);

      if (currentMillis - previousMillis >= 3000) {
        previousMillis = currentMillis;

        if (pedestrianRequested) {
          pedestrianRequested = false;
          currentState = PEDESTRIAN_CROSSING;
        } else {
          currentState = CAR_GREEN_WAIT;
        }
      }
      break;

    case PEDESTRIAN_CROSSING:
      digitalWrite(carGreen, LOW);
      digitalWrite(carYellow, LOW);
      digitalWrite(carRed, HIGH);
      digitalWrite(pedGreen, HIGH);
      digitalWrite(pedRed, LOW);

      if (currentMillis - previousMillis >= 5000) {
        previousMillis = currentMillis;
        currentState = CAR_GREEN_WAIT;
      }
      break;
  }
}

