//Desarrollemos un programa donde el robot sigue una línea negra mientras muestra por pantalla
//qué sensor de proximidad IR se activó

// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>

// inicializamos las variables
int vel = 150;
int IR_der;
int IR_izq;
int sensor_luz = 0;
int umbral = 120; //Depende
const char* msj = "";

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

  borrarPantalla();
  escribirPantalla(0,0,msj);
  pausa(200);

  
  if (IR_der == 0 && IR_izq == 1) { // Lado 1 si se activa derecha
    msj = "Derecha";
  } else if (IR_der == 1 && IR_izq == 0) { // Lado 0 si se activa izquierda
    msj = "Izquierda";
  }

  if (sensor_luz>umbral){ // Negro
    avanzar(vel,0); // girarDerecha
  } else {
    avanzar(0,vel); // girarIzquierda
  }

}
