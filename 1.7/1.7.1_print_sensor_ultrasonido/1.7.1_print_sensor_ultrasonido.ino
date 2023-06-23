#include<KnightRoboticsLibs_Iroh.h>
#include<LiquidCrystal_I2C.h>
#include<Servo.h>
#include<NewPing.h>
#include<Wire.h>

int ultraSonido = 0;

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot();
  botonInicio();
}

void loop() {

  ultraSonido = leerDistanciaSonar();

  borrarPantalla();
  escribirPantalla(0, 0, ultraSonido);
  pausa(200);
}
