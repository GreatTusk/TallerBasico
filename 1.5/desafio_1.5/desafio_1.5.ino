// Incluimos las librerias
#include <KnightRoboticsLibs_Iroh.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>

// inicializamos las variables
int vel = 200;
int sensor_luz = 0;
int umbral = 72; //Depende
int IR_DER;
int IR_IZD;
int lado;
int pause = 200;
const char* msj = "Hola";

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot(); //Atención a que se tiene que inicializar la pantalla
  botonInicio();
}

void loop() {
  //Estas variables guardarán los valores que reciban los sensores

  sensor_luz= leerSensorLineaCentral();
  IR_DER = leerSensorObstaculoDerecho();
  IR_IZD = leerSensorObstaculoIzquierdo();

  borrarPantalla();

  if (IR_IZD == 0 && IR_DER == 1){
    lado = 0;
    escribirPantalla(0,0, "IR_IZD activado");
    pausa(pause);
  } else if (IR_IZD = 1 && IR_DER == 0){
    lado = 1;
    escribirPantalla(0,0, "IR_DER activado");
    pausa(pause);
  } 
  
  
  if (lado == 0){
    if (sensor_luz>umbral){
      avanzar(vel,0);
    }
    else{
      avanzar(0,vel);
    }
  } else if (lado == 1){
    if (sensor_luz>umbral){
      avanzar(0,vel);
    }
    else{
      avanzar(vel,0);
    }
  } else {
    escribirPantalla(0,0,"Intentar de nuevo");
    pausa(pause);
  }
}