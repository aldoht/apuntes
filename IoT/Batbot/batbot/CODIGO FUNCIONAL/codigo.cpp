#include <PID_v1.h>

// Pines sensores ultrasónicos
#define L_ECHO_PIN 5
#define L_TRIGGER_PIN 4
#define R_ECHO_PIN 6
#define R_TRIGGER_PIN 7
#define C_ECHO_PIN 3
#define C_TRIGGER_PIN 2

// Pines motores
#define ENABLEA_PIN 10
#define ENABLEB_PIN 11
const int MOTORA_PINS[2] = {13, 8}; // Motor izquierdo
const int MOTORB_PINS[2] = {9, 12}; // Motor derecho

#define MAX_ANALOG 255
#define START_VELO (MAX_ANALOG / 2)
#define STOP_DISTANCE_CM 3
#define GIRO_TIME 500   // ms para giro
#define RETRO_TIME 400  // ms para retroceso

// PID
double input, output, setpoint=0;
double Kp=5.0, Ki=0.1, Kd=2.0;
PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

// --- Funciones sensores ---
long medirDistancia(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duracion = pulseIn(echoPin, HIGH, 30000);
  long distancia = duracion*0.034/2;
  if (distancia==0) distancia=999;
  return distancia;
}

// --- Control motores ---
void motorControl(int leftSpeed, int rightSpeed){
  // Izquierda
  if(leftSpeed>=0){
    digitalWrite(MOTORA_PINS[0], HIGH);
    digitalWrite(MOTORA_PINS[1], LOW);
  } else{
    digitalWrite(MOTORA_PINS[0], LOW);
    digitalWrite(MOTORA_PINS[1], HIGH);
    leftSpeed=-leftSpeed;
  }
  // Derecha
  if(rightSpeed>=0){
    digitalWrite(MOTORB_PINS[0], HIGH);
    digitalWrite(MOTORB_PINS[1], LOW);
  } else{
    digitalWrite(MOTORB_PINS[0], LOW);
    digitalWrite(MOTORB_PINS[1], HIGH);
    rightSpeed=-rightSpeed;
  }
  analogWrite(ENABLEA_PIN, constrain(leftSpeed,0,255));
  analogWrite(ENABLEB_PIN, constrain(rightSpeed,0,255));
}

// --- Movimientos especiales ---
void giroIzquierda(){ motorControl(-START_VELO, START_VELO); delay(GIRO_TIME);}
void giroDerecha(){ motorControl(START_VELO, -START_VELO); delay(GIRO_TIME);}
void retroceder(){ motorControl(-START_VELO, -START_VELO); delay(RETRO_TIME);}

// Avanzar manteniendo el centro del pasillo con PID
void avanzarConPID(long distL, long distR){
  input = distR - distL; // corregir para alejarse de objetos
  pid.Compute();
  int leftSpeed = START_VELO - output;
  int rightSpeed = START_VELO + output;
  motorControl(leftSpeed, rightSpeed);
}

// --- Setup ---
void setup(){
  Serial.begin(9600);
  pinMode(L_TRIGGER_PIN, OUTPUT); pinMode(L_ECHO_PIN, INPUT);
  pinMode(R_TRIGGER_PIN, OUTPUT); pinMode(R_ECHO_PIN, INPUT);
  pinMode(C_TRIGGER_PIN, OUTPUT); pinMode(C_ECHO_PIN, INPUT);
  pinMode(MOTORA_PINS[0], OUTPUT); pinMode(MOTORA_PINS[1], OUTPUT);
  pinMode(MOTORB_PINS[0], OUTPUT); pinMode(MOTORB_PINS[1], OUTPUT);
  pinMode(ENABLEA_PIN, OUTPUT); pinMode(ENABLEB_PIN, OUTPUT);
  pid.SetOutputLimits(-50, 50);
  pid.SetSampleTime(100);
  pid.SetMode(AUTOMATIC);
  Serial.println("🤖 Robot listo para laberinto");
}

// --- Loop principal ---
void loop(){
  long distL = medirDistancia(L_TRIGGER_PIN, L_ECHO_PIN);
  long distR = medirDistancia(R_TRIGGER_PIN, R_ECHO_PIN);
  long distC = medirDistancia(C_TRIGGER_PIN, C_ECHO_PIN);
  Serial.print("L:");Serial.print(distL); Serial.print(" C:");Serial.print(distC); Serial.print(" R:");Serial.println(distR);

  if(distC>STOP_DISTANCE_CM){
    avanzarConPID(distL,distR);
  } else {
    // Centro bloqueado
    if(distR>STOP_DISTANCE_CM && distL<=STOP_DISTANCE_CM){
      giroDerecha();
    } else if(distL>STOP_DISTANCE_CM && distR<=STOP_DISTANCE_CM){
      giroIzquierda();
    } else if(distL>STOP_DISTANCE_CM && distR>STOP_DISTANCE_CM){
      // Ambos lados libres, elegir aleatoriamente
      if(random(0,2)==0) giroIzquierda(); else giroDerecha();
    } else {
      // Callejón sin salida
      retroceder();
    }
  }
}
