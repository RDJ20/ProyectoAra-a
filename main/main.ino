#include <Servo.h>

Servo miServo[19];

void setup() {
  int servos[] = {22, 28, 34, 23, 46, 40, 24, 30, 36, 25, 39, 42, 26, 32, 38, 27, 48, 44};

  for (int i = 1; i <= 18; i++) {
    miServo[i].attach(servos[i-1]);
  }
}

void smoothMovement(
  int servo1, int servo2, int servo3,
  int servo4, int servo5, int servo6,
  int servo7, int servo8, int servo9,
  int posicionFinal1, int posicionFinal2, int posicionFinal3, 
  int posicionFinal4, int posicionFinal5, int posicionFinal6, 
  int posicionFinal7, int posicionFinal8, int posicionFinal9,
  int duracion
) {
  int anguloInicial1 = miServo[servo1].read(); 
  int anguloInicial2 = miServo[servo2].read(); // 90
  int anguloInicial3 = miServo[servo3].read(); 
  
  int anguloInicial4 = miServo[servo4].read(); 
  int anguloInicial5 = miServo[servo5].read(); // 90
  int anguloInicial6 = miServo[servo6].read();
  
  int anguloInicial7 = miServo[servo7].read(); 
  int anguloInicial8 = miServo[servo8].read(); // 90
  int anguloInicial9 = miServo[servo9].read(); // Ángulo inicial del servo
  int pasos = 100;  // Número de pasos para la interpolación
  
  for (int i = 0; i <= pasos; i++) {
    float t = float(i) / float(pasos);  // Tiempo normalizado
    float anguloInterpolado1 = anguloInicial1 + (posicionFinal1 - anguloInicial1) * (-0.5 * (cos(PI * t) - 1));
    float anguloInterpolado2 = anguloInicial2 + (posicionFinal2 - anguloInicial2) * (-0.5 * (cos(PI * t) - 1));
    float anguloInterpolado3 = anguloInicial3 + (posicionFinal3 - anguloInicial3) * (-0.5 * (cos(PI * t) - 1));

    float anguloInterpolado4 = anguloInicial4 + (posicionFinal4 - anguloInicial4) * (-0.5 * (cos(PI * t) - 1));
    float anguloInterpolado5 = anguloInicial5 + (posicionFinal5 - anguloInicial5) * (-0.5 * (cos(PI * t) - 1));
    float anguloInterpolado6 = anguloInicial6 + (posicionFinal6 - anguloInicial6) * (-0.5 * (cos(PI * t) - 1));
    
    float anguloInterpolado7 = anguloInicial7 + (posicionFinal7 - anguloInicial7) * (-0.5 * (cos(PI * t) - 1));
    float anguloInterpolado8 = anguloInicial8 + (posicionFinal8 - anguloInicial8) * (-0.5 * (cos(PI * t) - 1));
    float anguloInterpolado9 = anguloInicial9 + (posicionFinal9 - anguloInicial9) * (-0.5 * (cos(PI * t) - 1));  // Interpolación utilizando easeInOutSine
    
    miServo[servo1].write(anguloInterpolado1); 
    miServo[servo2].write(anguloInterpolado2); 
    miServo[servo3].write(anguloInterpolado3); 

    miServo[servo4].write(anguloInterpolado4); 
    miServo[servo5].write(anguloInterpolado5); 
    miServo[servo6].write(anguloInterpolado6);

    miServo[servo7].write(anguloInterpolado7); 
    miServo[servo8].write(anguloInterpolado8); 
    miServo[servo9].write(anguloInterpolado9);
    
    // Mover el servo al ángulo interpolado
    delay(duracion / pasos);  // Espera entre pasos
  }
}

<<<<<<< HEAD
=======
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

>>>>>>> cf24e1f42afb08622b241008a69e7dedb17a3c28
int A = 15;
int velocidad = 1000;
int base = 90;
int medio = 120;
int medioIZ = 60;
<<<<<<< HEAD
int finalDER = 90; // 0
int finalIZ = 90; // 180
int levantar = 30;
int movTime = 1000;

void loop() {
  BaseDerecha(90);
  BaseIzquierda(90);
  MedioDerecha(90); // 180
  MedioIzquierda(90); // 0
  FinalDerecha(0); // 0
  FinalIzquierda(180); // 180
  delay(1000);
}

void moveUpGroupA() {
  smoothMovement(
    1, 5, 3,
    7, 11, 9,
    13, 17, 15,
    base + A, base - A, base + A,
    medio + A + levantar, medioIZ - A - levantar, medio + A + levantar,
    finalDER - A, finalIZ + A, finalDER - A,
    movTime
  );
}

void moveDownGroupA() {
  // GRUPO A
  // Fase apoyo
  smoothMovement(
    1, 5, 3,
    7, 11, 9,
    13, 17, 15,
    base, base, base,
    medio, medioIZ, medio,
    finalDER, finalIZ, finalDER,
    movTime
  );
=======
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

>>>>>>> cf24e1f42afb08622b241008a69e7dedb17a3c28
}

void moveUpGroupB() {
  // GRUPO B
  // Fase movimiento
<<<<<<< HEAD
  smoothMovement(
    4, 2, 6,
    10, 8, 12,
    16, 14, 18,
    base - A, base + A, base - A,
    medioIZ - A - levantar, medio + A + levantar, medioIZ - A - levantar,
    finalIZ - A, finalDER + A, finalIZ - A,
    movTime
  );
=======
  smoothMovement(1, base+A, movTime);
  smoothMovement(5, base-A, movTime); //Inverso BASE
  smoothMovement(3, base+A, movTime);

  smoothMovement(7, medio+A+levantar, movTime);
  smoothMovement(11, medioIZ-A-levantar, movTime); //Inverso Medio
  smoothMovement(9, medio+A+levantar, movTime);

  smoothMovement(13, finalDER-A, movTime);
  smoothMovement(5, finalIZ+A, movTime);
  smoothMovement(15, finalDER-A, movTime);
>>>>>>> cf24e1f42afb08622b241008a69e7dedb17a3c28
}

void moveDownGroupB() {
  // GRUPO B
  // Fase apoyo
<<<<<<< HEAD
  smoothMovement(
    4, 2, 6,
    10, 8, 12,
    16, 14, 18,
    base, base, base,
    medioIZ, medio, medioIZ,
    finalIZ, finalDER, finalIZ,
    movTime
  );
}

void BaseDerecha(int inclinacion) {
  miServo[1].write(inclinacion);
  miServo[2].write(inclinacion);
  miServo[3].write(inclinacion);
}

void BaseIzquierda(int inclinacion) {
  miServo[4].write(inclinacion);
  miServo[5].write(inclinacion);
  miServo[6].write(inclinacion);
}

void MedioDerecha(int inclinacion) {
  miServo[7].write(inclinacion);
  miServo[8].write(inclinacion);
  miServo[9].write(inclinacion);
}

void MedioIzquierda(int inclinacion) {
  miServo[10].write(inclinacion);
  miServo[11].write(inclinacion);
  miServo[12].write(inclinacion);
}

void FinalDerecha(int inclinacion) {
  miServo[13].write(inclinacion);
  miServo[14].write(inclinacion);
  miServo[15].write(inclinacion);
}

void FinalIzquierda(int inclinacion) {
  miServo[16].write(inclinacion);
  miServo[17].write(inclinacion);
  miServo[18].write(inclinacion);
}
=======
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
>>>>>>> cf24e1f42afb08622b241008a69e7dedb17a3c28
