const int trigPin = 5;
const int echoPin = 18;
const int redPin = 4;
const int greenPin = 16;
const int bluePin = 17;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pin
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;  // Convert to cm

  // Control RGB LED based on distance
  if (distance <= 10) {
    setColor(255,0, 0);  // Red
  } else if (distance > 10 && distance <= 30) {
    setColor(255, 255, 0);  // Yellow
  } else if (distance > 30 && distance <= 100) {
    setColor(0, 255, 0);  // Green
  } else {
    setColor(0, 0, 255);  // Blue
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);
}


void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
