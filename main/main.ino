
#include <Servo.h>

Servo miServo[19];


void setup() {
  // Base Derecha
  miServo[1].attach(22);
  miServo[2].attach(28);
  miServo[3].attach(34);
  // Base Izquierda
  miServo[4].attach(23);
  miServo[5].attach(46);
  miServo[6].attach(40);
  // Medio Derecha
  miServo[7].attach(24);
  miServo[8].attach(30);
  miServo[9].attach(36);
  // Medio Izquierda
  miServo[10].attach(25);
  miServo[11].attach(39);
  miServo[12].attach(42);
  // Final Derecha
  miServo[13].attach(26);
  miServo[14].attach(32);
  miServo[15].attach(38);
  // Final Izquierda
  miServo[16].attach(27);
  miServo[17].attach(48);
  miServo[18].attach(44);
}

int A = 5;
int base = 90;
int medio = 120;
int medioIZ = 60;
int finalDER = 90; //0
int finalIZ = 90; //180
void loop() {
//////////////////////primer movimiento
  //GRUPO A 
  // Fase movimiento
  miServo[1].write(base+A);
  miServo[5].write(base-A); //Inverso BASE
  miServo[3].write(base+A);

  miServo[7].write(medio+A);
  miServo[11].write(medioIZ-A); //Inverso Medio
  miServo[9].write(medio+A);

  miServo[13].write(finalDER-A);
  miServo[5].write(finalIZ+A);
  miServo[15].write(finalDER-A);

  // GRUPO B
  // Fase apoyo
  miServo[4].write(base-A);
  miServo[2].write(base+A); //Inverso BASE
  miServo[6].write(base-A);

  miServo[10].write(medioIZ-A);
  miServo[8].write(medio+A); //Inverso Medio
  miServo[12].write(medioIZ-A);

  miServo[16].write(finalIZ+A);
  miServo[14].write(finalDER-A);
  miServo[18].write(finalIZ+A);

  delay(1000);

//////////////////////segundo movimiento

  //GRUPO A 
  // Fase apoyo
  miServo[1].write(base-A);
  miServo[5].write(base+A); //Inverso BASE
  miServo[3].write(base-A);

  miServo[7].write(medio-A);
  miServo[11].write(medioIZ+A); //Inverso Medio
  miServo[9].write(medio-A);

  miServo[13].write(finalDER+A);
  miServo[5].write(finalIZ-A);
  miServo[15].write(finalDER+A);
 
  //GRUPO B 
  // Fase movimiento
  miServo[4].write(base+A);
  miServo[2].write(base-A); //Inverso BASE
  miServo[6].write(base+A);

  miServo[10].write(medioIZ+A);
  miServo[8].write(medio-A); //Inverso Medio
  miServo[12].write(medioIZ+A);

  miServo[16].write(finalIZ-A);
  miServo[14].write(finalDER+A);
  miServo[18].write(finalIZ-A);
  
  delay(1000);

}


void BaseDerecha(int inclinacion) {
  miServo[1].write(inclinacion);
  miServo[2].write(inclinacion);
  miServo[3].write(inclinacion);
}

void BaseIzquierda(int inclinacion)
{
  miServo[4].write(inclinacion);
  miServo[5].write(inclinacion);
  miServo[6].write(inclinacion);
}

void MedioDerecha(int inclinacion)
{
  miServo[7].write(inclinacion);
  miServo[8].write(inclinacion);
  miServo[9].write(inclinacion);
}

void MedioIzquierda(int inclinacion)
{
  miServo[10].write(inclinacion);
  miServo[11].write(inclinacion);
  miServo[12].write(inclinacion);
}

void FinalDerecha(int inclinacion)
{
  miServo[13].write(inclinacion);
  miServo[14].write(inclinacion);
  miServo[15].write(inclinacion);
}

void FinalIzquierda(int inclinacion)
{
  miServo[16].write(inclinacion);
  miServo[17].write(inclinacion);
  miServo[18].write(inclinacion);
}