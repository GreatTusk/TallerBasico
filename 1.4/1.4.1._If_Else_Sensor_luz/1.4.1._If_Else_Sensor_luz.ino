// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>

// inicializamos las variables
int vel = 150;
int sensor_luz = 0;
int umbral = 500; //Depende

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot(); //Atención a que se tiene que inicializar la pantalla
  botonInicio();
}

void loop() {
  //Estas variables guardarán los valores que reciban los sensores

  sensor_luz= leerSensorLineaCentral();

  //Se mostrará en la pantalla lo que lea el sensor de luz. Se borrará lo que haya antes en la pantalla primero.

  // Si es oscuro, avanza. Valores son ejemplos, hay que validarlos con un Iroh
  if (sensor_luz > umbral) {
    girarDerecha(vel)

  // Sino, si detecta blanco, gira a la derecha. Valores son ejemplos, hay que validarlos con un Iroh
  } else {
    girarIzquierda(vel)
  }
}
