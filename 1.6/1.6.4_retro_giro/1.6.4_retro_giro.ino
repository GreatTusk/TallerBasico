//Desarrollemos un programa en donde el robot inicialmente está detenido y si el sensor de
//proximidad IR derecho es activado, deberá retroceder 2 segundos, en cambio, si activa el sensor de
//proximidad IR izquierdo, el robot deberá girar en 180 grados y avanzar.

// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>

// inicializamos las variables
int vel = 200;
int IR_der;
int IR_izq;
int a = 0;
int tiempo_giro = 2000; //depende

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  botonInicio();
}

void loop() {
  //Estas variables guardarán los valores que reciban los sensores

  IR_der = leerSensorObstaculoDerecho();
  IR_izq = leerSensorObstaculoIzquierdo();
  
  if (IR_der == 0 && IR_izq == 1) { // a>0 si se activa derecha
    a = 1;
  } else if (IR_der == 1 && IR_izq == 0) { // a<0 si se activa izquierda
    a = -1;
  }

  // a positiva
  if (a>0) {

    retroceder(vel);
    pausa(2000); // 2 seg

  } else if (a<0) { // a negativa
  
    avanzar(vel,0); // girarDerecha
    pausa(tiempo_giro);
    avanzar(vel);
    pausa(3000);

  }
}
