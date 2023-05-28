// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>

// inicializamos las variables

int sensor_luz;


void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot(); //Atención a que se tiene que inicializar la pantalla
  botonInicio();
}

void loop() {
  borrarPantalla();
  sensor_luz= leerSensorLineaCentral(); //Esta variable guardará los valores que reciba el sensor
  escribirPantalla(0,0,sensor_luz);
  pausa(200);
}

