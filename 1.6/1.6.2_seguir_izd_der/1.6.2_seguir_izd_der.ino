//Programaremos el robot: Si el IR izquierdo fue activado, siga la línea por la izquierda.
//Si el IRderecho fue activado, siga la línea por la derecha

// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>

// inicializamos las variables
int vel = 150;
int lado;
int IR_der;
int IR_izq;
int sensor_luz = 0;
int umbral = 120; //Depende

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot(); //Atención a que se tiene que inicializar la pantalla
  botonInicio();
}

void loop() {
  //Estas variables guardarán los valores que reciban los sensores

  IR_der = leerSensorObstaculoDerecho();
  IR_izq = leerSensorObstaculoIzquierdo();
  sensor_luz = leerSensorLineaCentral();

  
  if (IR_der == 0 && IR_izq == 1) { // Lado 1 si se activa derecha
    lado = 1;
  } else if (IR_der == 1 && IR_izq == 0) { // Lado 0 si se activa izquierda
    lado = 0;
  }

  // Hacia la derecha
  if (lado == 1) {

    if (sensor_luz>umbral){ // Negro
      avanzar(vel,0); // girarDerecha
    } else {
      avanzar(0,vel); // girarIzquierda
    }

  } else if (lado == 0) {

    if (sensor_luz>umbral){ // Negro
      avanzar(0,vel); // girarIzquierda
    } else {
      avanzar(vel,0); // girarDerecha
    }

  }
}
