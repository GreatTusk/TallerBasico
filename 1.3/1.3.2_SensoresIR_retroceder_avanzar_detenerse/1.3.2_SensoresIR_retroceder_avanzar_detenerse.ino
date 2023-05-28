// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>

// inicializamos las variables
int vel_der = 200;
int vel_izq = 200;
int IR_der;
int IR_izq;
int sensor_luz;

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
  sensor_luz = leerSensorLuz();

  //Se mostrará en la pantalla lo que lea el sensor de luz. Se borrará lo que haya antes en la pantalla primero.

  borrarPantalla();
  escribirPantalla(0,0,sensor_luz);
  pausa(500);


  // Si es oscuro, avanza. Valores son ejemplos, hay que validarlos con un Iroh
  if (sensor_luz <= 1023 && sensor_luz >=800) {
    avanzar(vel_izq, vel_der);

  // Sino, si detecta blanco, gira a la derecha. Valores son ejemplos, hay que validarlos con un Iroh
  } else if (sensor_luz <= 100 && sensor_luz >= 80) {
    girarIzquierda(vel_izq);
}
