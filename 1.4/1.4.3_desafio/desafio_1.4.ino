// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>

// inicializamos las variables
int giro = 150;
int tiempo_giro = 1000;
int IR_der;
int IR_izq;
int sensor_luz = 0;
int umbral = 120; //Depende
const char* msj = "hola a todos";

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

  //Se mostrará en la pantalla lo que lea el sensor de luz. Se borrará lo que haya antes en la pantalla primero.

  borrarPantalla();
  escribirPantalla(3, 0, msj);
  pausa(200);


  // Si es oscuro
  if (sensor_luz > umbral) {
    girarDerecha(giro);

    // Sino, si detecta blanco
  } else {
    girarIzquierda(giro);
  }

  if (IR_der == 0 || IR_izq == 1) {
    girarIzquierda(giro);
    pausa(tiempo_giro);
  } else if (IR_der == 1 || IR_izq == 0) {
    girarDerecha(giro);
    pausa(tiempo_giro);
  } else if (IR_der == 1 || IR_izq == 1) {
    msj = "chao";
  }
}
