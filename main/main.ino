
#include <Servo.h>

Servo miServo[19];
int A = 90;

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

void loop() {
 BaseDerecha(90);
 BaseIzquierda(90);
 MedioDerecha(120);//180
 MedioIzquierda(60);//0
 FinalDerecha(90);//0
 FinalIzquierda(90);// 180
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