//Programaremos el robot: Desarrollemos un programa donde: Si el IR derecho es activado, la variable a es positiva,
//y el robot deberá girar a la izquierda, después avanzar 2 segundos.
//Por otro lado, si el IR izquierdo es activado, la variable a es negativa
//y deberá retroceder 1 segundo y girar sobre su eje una vez.

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
    avanzar(0,vel); // girarIzquierda
    pausa(1000); // 1 seg
    avanzar(vel);
    pausa(2000); // 2 seg

  } else if (a<0) { // a negativa
    retroceder(vel);
    pausa(1000);
    avanzar(vel,0);
    pausa(2000);

  }
}
