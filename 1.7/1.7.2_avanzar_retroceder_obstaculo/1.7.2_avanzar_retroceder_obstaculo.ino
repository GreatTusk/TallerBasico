#include<KnightRoboticsLibs_Iroh.h>
#include<LiquidCrystal_I2C.h>
#include<Servo.h>
#include<NewPing.h>
#include<Wire.h>

int vel_izq = 200;
int vel_der = 200;
int ultraSonido = 0;

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot();
  botonInicio();
}

void loop() {
  ultraSonido = leerDistanciaSonar();

  if (ultraSonido > 0 && ultraSonido < 10) {
    retroceder(vel_izq);
    pausa(1000);
    girarDerecha(200);
    pausa(1000);
  } else {
    avanzar(vel_izq, vel_der);
  }
}
