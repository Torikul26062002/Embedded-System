const int carRed = 13;
const int carYellow = 12;
const int carGreen = 11;

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
}

void loop() {
  // 1. Red LED ON
  digitalWrite(carRed, HIGH);
  delay(1000);
  digitalWrite(carRed, LOW);

  // 2. Yellow LED ON
  digitalWrite(carYellow, HIGH);
  delay(1000);
  digitalWrite(carYellow, LOW);

  // 3. Green LED ON
  digitalWrite(carGreen, HIGH);
  delay(1000);
  digitalWrite(carGreen, LOW);
}
