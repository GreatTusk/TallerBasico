// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>


// inicializamos las variables
int vel_derecha = 200;
int vel_izquierda = 200;
int IR_der;
int IR_izq;
void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot();
  botonInicio();
}

void loop() {
  IR_der = leerSensorObstaculoDerecho();
  IR_izq = leerSensorObstaculoIzquierdo();

  // si cualquiera de los dos IR es activado
  if (IR_der == 1 || IR_izq == 1) {
    retroceder(vel_izquierda, vel_derecha);
    pausa(2000);
    girarIzquierda(vel_derecha);
    pausa(1500);
    
  } else { // sino, avanzamos
    avanzar(200);
  }
}
