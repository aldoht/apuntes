int MOTOR_PIN_1 = 2;
int MOTOR_PIN_2 = 4;
int ENABLE_PIN_1 = 10;

void setup(){
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(ENABLE_PIN_1, OUTPUT);
  
  turnOffPins();
  Serial.begin(9600);
}

void loop(){
  for (int i = 25; i <= 100; i += 25) {
    Serial.print("El motor esta girando a ");
    Serial.print(i);
    Serial.println("%");
    turnControlSpeed(MOTOR_PIN_1, MOTOR_PIN_2, i/100.0);
  }
}

void girar(int pin1, int pin2) {
  turnOffMotorPins();
  digitalWrite(pin1, HIGH);
}

void turnControlSpeed(int pin1, int pin2, float speed) {
  analogWrite(ENABLE_PIN_1, speed*255);
  girar(pin1, pin2);
  delay(5000);
  girar(pin2, pin1);
  delay(5000);
}

void turnOffMotorPins() {
  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, LOW);
}

void turnOffPins() {
  turnOffMotorPins();
  analogWrite(ENABLE_PIN_1, 0);
}
