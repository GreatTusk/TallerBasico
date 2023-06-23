#include<KnightRoboticsLibs_Iroh.h>
#include<LiquidCrystal_I2C.h>
#include<Servo.h>
#include<NewPing.h>
#include<Wire.h>

int IR_der;
int IR_izq;
int ultraSonido = 0;

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot();
  inicializarCabezaRobot();; // inicializamos los servos de la cabeza
  moverServoGolpe(0); // Le damos una posicion inicial al Servo Golpe
  moverServoPitch(10); // Le damos una posicion inicial a la cabeza
  moverServoYaw(90); // Le damos una posicion inicial a la cabeza
  botonInicio();
}

void loop() {
  IR_der = leerSensorObstaculoDerecho();
  IR_izq = leerSensorObstaculoIzquierdo();

  // Activamos el IR derecho
  if (IR_der == 1) {
    moverServoGolpe(1);
  } else if (IR_izq == 1) { // activamos el IR izquierdo
    moverServoGolpe(-1);
  }
}
