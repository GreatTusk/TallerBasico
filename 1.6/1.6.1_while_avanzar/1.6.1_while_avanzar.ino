// Programaremos el Iroh: Mientras el sensor IR izquierdo esté activado, 
//éste deberá avanzar. En caso contrario, tendrá que quedarse quieto.

// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>

// inicializamos las variables

int IR_der;
int IR_izq;
int vel = 200;

void setup() {

  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  botonInicio();
  
}

void loop() {
  //Estas variables guardarán los valores que reciban los sensores

  IR_der = leerSensorObstaculoDerecho();
  IR_izq = leerSensorObstaculoIzquierdo();

  // Mientras el IR izquierdo esté activado
  
  while (IR_izq == 0){ // 0 = activado
    avanzar(vel);
  }
}

