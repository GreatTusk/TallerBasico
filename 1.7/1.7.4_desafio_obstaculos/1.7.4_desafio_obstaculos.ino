//Incluimos las librerias
#include<KnightRoboticsLibs_Iroh.h>
#include<LiquidCrystal_I2C.h>
#include<Servo.h>
#include<NewPing.h>
#include<Wire.h>

// inicializamos las variables
int IR_der;
int IR_izq;
int tiempo_giro_180 = 2000; // depende del robot
int luzCentro;
int umbral = 500;

int ultraSonido = 0;

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot();
  inicializarCabezaRobot();; // inicializamos los servos de la cabeza
  moverServoGolpe(0); // Le damos una posicion inicial al Servo Golpe
  moverServoPitch(10); // Le damos una posicion inicial a la cabeza
  moverServoYaw(90); // Le damos una posicion inicial a la cabeza
  botonInicio();
}

void loop() {

  ultraSonido = leerDistanciaSonar();
  luzCentro = leerSensorLineaCentral();
  IR_der = leerSensorObstaculoDerecho();
  IR_izq = leerSensorObstaculoIzquierdo();

  //Seguidor de linea:

  // Si detecta negro
  if (luzCentro > umbral) {
    girarDerecha(150);

  } else { // Blanco
    girarIzquierda(150);
  }

  // Obstaculos:

  if (ultraSonido > 0 && ultraSonido < 10) {
    // Mostramos mensaje
    borrarPantalla(); //Antes de escribir, siempre se debe borrar.
    escribirPantalla(0,0, "Obstaculo");
    pausa(200); //Pequeña pausa para leer datos.

    // Golpeamos
    moverServoGolpe(1);
    moverServoGolpe(-1);
  }

  // IRs:

  // Si ambos se activan
  if (IR_izq == 1 && IR_der == 1) {
    girarDerecha(200);
    pausa(tiempo_giro_180);
  }

}
