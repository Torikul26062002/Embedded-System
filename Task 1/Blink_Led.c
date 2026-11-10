const int carRed = 13;
const int carYellow = 12;
const int carGreen = 11;

const int pedRed = 10;
const int pedGreen = 9;

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);

  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
}

void loop() {
  // 1. Car Red
  digitalWrite(carRed, HIGH);
  delay(1000);
  digitalWrite(carRed, LOW);

  // 2. Car Yellow
  digitalWrite(carYellow, HIGH);
  delay(1000);
  digitalWrite(carYellow, LOW);

  // 3. Car Green
  digitalWrite(carGreen, HIGH);
  delay(1000);
  digitalWrite(carGreen, LOW);

  // 4. Pedestrian Red
  digitalWrite(pedRed, HIGH);
  delay(1000);
  digitalWrite(pedRed, LOW);

  // 5. Pedestrian Green
  digitalWrite(pedGreen, HIGH);
  delay(1000);
  digitalWrite(pedGreen, LOW);
}
