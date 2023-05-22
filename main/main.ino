
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

int A = 5;
int base = 90;
int medio = 120;
int medioIZ = 60;
int finalDER = 90; //0
int finalIZ = 90; //180
void loop() {

//////////////////////primer movimiento
  upA();
  supportB();

  delay(1000);

//////////////////////segundo movimiento

  supportA();

  
  delay(1000);

}


void upA() {
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
}

void supportA() {
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
}

void upB() {
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
}

void supportB() {
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
}

