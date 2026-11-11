
const int carRed = 13;
const int carYellow = 12;
const int carGreen = 11;

// State durations
const unsigned long redTime = 5000;
const unsigned long redYellowTime = 1000;
const unsigned long greenTime = 5000;
const unsigned long yellowTime = 3000;

// Traffic light states
enum TrafficState {
  RED,
  RED_YELLOW,
  GREEN,
  YELLOW
};

TrafficState currentState = RED;
unsigned long previousMillis = 0;

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);

  digitalWrite(carRed, HIGH);
  digitalWrite(carYellow, LOW);
  digitalWrite(carGreen, LOW);

  previousMillis = millis();
}

void loop() {
  unsigned long currentMillis = millis();

  switch (currentState) {

    case RED:
      digitalWrite(carRed, HIGH);
      digitalWrite(carYellow, LOW);
      digitalWrite(carGreen, LOW);

      if (currentMillis - previousMillis >= redTime) {
        previousMillis = currentMillis;
        currentState = RED_YELLOW;
      }
      break;

    case RED_YELLOW:
      digitalWrite(carRed, HIGH);
      digitalWrite(carYellow, HIGH);
      digitalWrite(carGreen, LOW);

      if (currentMillis - previousMillis >= redYellowTime) {
        previousMillis = currentMillis;
        currentState = GREEN;
      }
      break;

    case GREEN:
      digitalWrite(carRed, LOW);
      digitalWrite(carYellow, LOW);
      digitalWrite(carGreen, HIGH);

      if (currentMillis - previousMillis >= greenTime) {
        previousMillis = currentMillis;
        currentState = YELLOW;
      }
      break;

    case YELLOW:
      digitalWrite(carRed, LOW);
      digitalWrite(carYellow, HIGH);
      digitalWrite(carGreen, LOW);

      if (currentMillis - previousMillis >= yellowTime) {
        previousMillis = currentMillis;
        currentState = RED;
      }
      break;
  }
}
