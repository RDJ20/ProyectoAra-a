#include <Servo.h>

Servo miServo[19];


void setup() {
  int servos[] = {22, 28, 34, 23, 46, 40, 24, 30, 36, 25, 39, 42, 26, 32, 38, 27, 48, 44};

  for (int i = 1; i <= 18; i++){
    miServo[i].attach(servos[i-1]);    
  } 
  // // Base Derecha
  // miServo[1].attach(22);
  // miServo[2].attach(28);
  // miServo[3].attach(34);
  // // Base Izquierda
  // miServo[4].attach(23);
  // miServo[5].attach(46);
  // miServo[6].attach(40);
  // // Medio Derecha
  // miServo[7].attach(24);
  // miServo[8].attach(30);
  // miServo[9].attach(36);
  // // Medio Izquierda
  // miServo[10].attach(25);
  // miServo[11].attach(39);
  // miServo[12].attach(42);
  // // Final Derecha
  // miServo[13].attach(26);
  // miServo[14].attach(32);
  // miServo[15].attach(38);
  // // Final Izquierda
  // miServo[16].attach(27);
  // miServo[17].attach(48);
  // miServo[18].attach(44);
}

void smoothMovement(int servo, int posicionFinal, int duracion) {
  int anguloInicial = miServo[servo].read();  // Ángulo inicial del servo
  int pasos = 100;                     // Número de pasos para la interpolación
  
  for (int i = 0; i <= pasos; i++) {
    float t = float(i) / float(pasos);  // Tiempo normalizado
    float anguloInterpolado = anguloInicial + (posicionFinal - anguloInicial) * (-0.5 * (cos(PI * t) - 1));  // Interpolación utilizando easeInOutSine
    miServo[servo].write(anguloInterpolado);  // Mover el servo al ángulo interpolado
    delay(duracion / pasos);  // Espera entre pasos
  }
}

int A = 15;
int velocidad = 1000;
int base = 90;
int medio = 120;
int medioIZ = 60;
int finalDER = 90; //0
int finalIZ = 90; //180
int levantar = 30;
int movTime = 2000;
void loop() {
//////////////////////primer movimiento
  upA();

  delay(velocidad);
  supportA();
 

  delay(velocidad);

  upB();
  
  delay(velocidad);

  supportB();
 
  delay(velocidad);

}

void upA() {
  //GRUPO A 
  // Fase movimiento
  smoothMovement(1, base+A, movTime);
  smoothMovement(5, base-A, movTime); //Inverso BASE
  smoothMovement(3, base+A, movTime);

  smoothMovement(7, medio+A+levantar, movTime);
  smoothMovement(11, medioIZ-A-levantar, movTime); //Inverso Medio
  smoothMovement(9, medio+A+levantar, movTime);

  smoothMovement(13, finalDER-A, movTime);
  smoothMovement(5, finalIZ+A, movTime);
  smoothMovement(15, finalDER-A, movTime);
}

void supportA() {
  //GRUPO A 
  // Fase apoyo
  smoothMovement(1, base, movTime);
  smoothMovement(5, base, movTime); //Inverso BASE
  smoothMovement(3, base, movTime);

  smoothMovement(7, medio, movTime);
  smoothMovement(11, medioIZ, movTime); //Inverso Medio
  smoothMovement(9, medio, movTime);

  smoothMovement(13, finalDER, movTime);
  smoothMovement(5, finalIZ, movTime);
  smoothMovement(15, finalDER, movTime);
}

void upB() {
 // GRUPO B 
  // Fase movimiento
  smoothMovement(4, base+A, movTime);
  smoothMovement(2, base-A, movTime); //Inverso BASE
  smoothMovement(6, base+A, movTime);

  smoothMovement(10, medioIZ-A-levantar, movTime);
  smoothMovement(8, medio+A+levantar, movTime); //Inverso Medio
  smoothMovement(12, medioIZ-A-levantar, movTime);

  smoothMovement(16, finalIZ-A, movTime);
  smoothMovement(14, finalDER+A, movTime);
  smoothMovement(18, finalIZ-A, movTime);
}

void supportB() {
  // GRUPO B
  //Fase apoyo
  smoothMovement(4, base, movTime);
  smoothMovement(2, base, movTime); //Inverso BASE
  smoothMovement(6, base, movTime);

  smoothMovement(10, medioIZ, movTime);
  smoothMovement(8, medio, movTime); //Inverso Medio
  smoothMovement(12, medioIZ, movTime);

  smoothMovement(16, finalIZ, movTime);
  smoothMovement(14, finalDER, movTime);
  smoothMovement(18, finalIZ, movTime);
}
