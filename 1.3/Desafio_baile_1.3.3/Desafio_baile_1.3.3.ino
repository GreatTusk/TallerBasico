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
int contadorBailes = 0;

// funcion de baile1
void baile1() {
  retroceder(100);
  pausa(2000);
  girarDerecha(200);
  pausa(2000);
  girarIzquierda(200);
  pausa(2000);
}

// funcion de baile2
void baile2() {
  girarDerecha(200);
  pausa(4000);
  girarIzquierda(200);
  pausa(4000);
}

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot();
  botonInicio();
}

void loop() {
  IR_der = leerSensorObstaculoDerecho();
  IR_izq = leerSensorObstaculoIzquierdo();

  // Si se activa SOLO el izquierdo
  if (IR_izq == 1 && IR_der == 0) {
    avanzar(vel_derecha,vel_izquierda);
    pausa(3000);
    girarDerecha(100);
    pausa(1500);
    detenerse();
    // Sino, si se activa SOLO el derecho
  } else if (IR_izq == 0 && IR_der == 1) {
    retroceder(vel_derecha,vel_izquierda);
    pausa(5000);
    detenerse();
    girarDerecha(100);
    pausa(1500);
    detenerse();
  } else if (IR_izq == 1 && IR_der == 1) {
    retroceder(vel_derecha,vel_izquierda);
    pausa(2000);
    detenerse();
  }
}