///??????????

#include <Wire.h>
#include <Servo.h>

#define Gyro_gX0 0x28
#define Gyro_gX1 0x29
#define Gyro_gZ0 0x2C
#define Gyro_gZ1 0x2D

int Gyro = 0x69;

int gX0, gX1, gX_out;
int gZ0, gZ1, gZ_out;

float Xg, Zg;
float angleX, angleZ, angleXc, angleZc;
float dt = 0.015;

unsigned long start, finished, elapsed;

//PROGRMAÇÃO_SAMURAI
//DECLARANDO MOTORES
byte mfE = 5;
byte mtE = 4;
byte mfD = 7;
byte mtD = 6;

byte LEDV = 26;
byte LEDv = 24;
byte LEDA = 28;
byte LEDBE = 22;
byte LEDBD = 30;

//DECLARANDO SENSORES
int sensor_OB(A10);    //sensor de ojetos de cima
int sensor_O(A3);    //sensor de objetos
int sensor_OC(A1);    //sensor de objetos de baixo

void setup() {
  //CONFIGURAÇÃO MOTORES
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(26, OUTPUT);  //LEDV
  pinMode(24, OUTPUT);  //LEDv
  pinMode(28, OUTPUT);  //LEDA
  pinMode(22, OUTPUT);  // LEDBE
  pinMode(30, OUTPUT);  // LEDBD

  Serial.begin(9600);

  //CONFIGURAÇÃO SENSORES

  pinMode(sensor_O, INPUT);          //objeto
  pinMode(sensor_OB, INPUT);        //objeto de cima
  pinMode(sensor_OC, INPUT);       //objeto de baixo

  Serial.begin(9600);
  Wire.begin();
  delay(10);

  Wire.beginTransmission(Gyro);
  Wire.write(0x20);
  Wire.write(15);
  Wire.endTransmission();

  Wire.beginTransmission(Gyro);
  Wire.write(0x23);
  Wire.write(48);
  Wire.endTransmission();
  angleX = 0.01;
}

void loop() {
  // BLOCO DE LEITURA DE SENSORES

  // Esquerda: >= -90.00
  // Direita: <= 100.00

  sensor_OC = analogRead(A1);
  sensor_OB = analogRead(A10);
  sensor_O = analogRead(A3);

  Serial.print(sensor_OC); Serial.print(" "); Serial.println(sensor_OB);

  FRENTE();
  delay(500);

  CURVAESQUERDA();

  TRAS();
  delay(500);

  STOP();
  delay(500);

  ATUALIZARSENSOR();

  FRENTE();
  delay(2350);

  TRAS();
  delay(2100);

  STOP();
  delay(200);

  ATUALIZARSENSOR();

  CURVADIREITA();

  FRENTE();
  delay(1150);

  ATUALIZARSENSOR();

  CURVAESQUERDA();

  TRAS();
  delay(600);

  STOP();
  delay(500);

  ATUALIZARSENSOR();

  if (sensor_OB > sensor_OC + 100)
  {
    digitalWrite(26, HIGH);
    delay(1000);
    digitalWrite(26, LOW);

    FRENTE();
    delay(3000);

    STOP();
    delay(1000);

    TRAS();
    delay(1200);

    angleX = 0.01;
    while (angleX >= -60.00) {
      getAX();
      analogWrite(mfE, 0);
      analogWrite(mtE, 180);
      analogWrite(mfD, 180);
      analogWrite(mtD, 0);
    }

    TRAS();
    delay(1400);

    STOP();
    delay(500);

    FRENTE();
    delay(200);

    TRAS();
    delay(230);

    FRENTE();
    delay(200);

    TRAS();
    delay(230);

    STOP();
    delay(500);

    FRENTE();
    delay(150);

    CURVADIREITA();

    FRENTE();
    delay(1200);

    angleX = 0.01;
    while (angleX >= -35.00) {
      getAX();
      analogWrite(mfE, 0);
      analogWrite(mtE, 180);
      analogWrite(mfD, 180);
      analogWrite(mtD, 0);
    }

    FRENTE();
    delay(1900);

    CURVAESQUERDA();

    FRENTE();
    delay(100);

    angleX = 0.01;
    while (angleX >= -85.00) {
      getAX();
      analogWrite(mfE, 0);
      analogWrite(mtE, 180);
      analogWrite(mfD, 180);
      analogWrite(mtD, 0);
    }


    FRENTE();
    delay(2100);

    CURVAESQUERDA();

    CURVAESQUERDA();

    angleX = 0.01;
    while (angleX >= -45.00) {
      getAX();
      analogWrite(mfE, 0);
      analogWrite(mtE, 180);
      analogWrite(mfD, 180);
      analogWrite(mtD, 0);
    }

    TRAS();
    delay(1500);

    STOP();
    delay(500);

    FRENTE();
    delay(200);

    TRAS();
    delay(230);

    FRENTE();
    delay(200);

    TRAS();
    delay(230);

    FRENTE();
    delay(3000);

    TRAS();
    delay(3000);

    STOP();
    delay(5000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000);
  }

  else
  {
    analogWrite(mfE, 175);
    analogWrite(mtE, 0);
    analogWrite(mfD, 140);
    analogWrite(mtD, 0);
    while (sensor_O <= 630)
    {
      ATUALIZARSENSOR();
    }

    STOP();
    delay(200);

    TRAS();
    delay(200);

    CURVADIREITA();

    CURVADIREITA();

    angleX = 0.01;
    while (angleX <= 20.00) {
      getAX();
      analogWrite(mfE, 170);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 190);
    }
    angleX = 0;

    TRAS();
    delay(900);

    STOP();
    delay(500);

    ATUALIZARSENSOR();

  }
  if (sensor_OB > sensor_OC + 100)
  {
    digitalWrite(22, HIGH);
    delay(1000);
    digitalWrite(22, LOW);

    FRENTE();
    delay(2500);

    TRAS();
    delay(1200);

    angleX = 0.01;
    while (angleX >= -70.00) {
      getAX();
      analogWrite(mfE, 0);
      analogWrite(mtE, 180);
      analogWrite(mfD, 180);
      analogWrite(mtD, 0);
    }

    TRAS();
    delay(1200);

    STOP();
    delay(500);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    CURVAESQUERDA();

    FRENTE();
    delay(500);

    angleX = 0.01;
    while (angleX <= 45.00) {
      getAX();
      analogWrite(mfE, 170);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 190);
    }

    FRENTE();
    while (sensor_O <= 630)
    {
      ATUALIZARSENSOR();
    }

    STOP();
    delay(100);

    CURVADIREITA();

    TRAS();
    delay(500);

    FRENTE();
    delay(3100);

    STOP();
    delay(100);

    CURVADIREITA();

    TRAS();
    delay(500);

    FRENTE();
    delay(1500);

    CURVADIREITA();

    angleX = 0.01;
    while (angleX <= 70.00) {
      getAX();
      analogWrite(mfE, 170);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 190);
    }

    FRENTE();
    delay(1500);

    CURVAESQUERDA();

    FRENTE();
    delay(2000);

    CURVAESQUERDA();

    CURVAESQUERDA();

    TRAS();
    delay(800);

    STOP();
    delay(500);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    FRENTE();
    delay(3000);

    TRAS();
    delay(3000);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    STOP();
    delay(300000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000);
  }

  else
  {
    ATUALIZARSENSOR();

    digitalWrite(24, HIGH);
    delay(1000);
    digitalWrite(24, LOW);

    FRENTE();
    delay(2500);

    TRAS();
    delay(1200);

    angleX = 0.01;
    while (angleX <= 60.00) {
      getAX();
      analogWrite(mfE, 170);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 190);
    }

    TRAS();
    delay(1000);

    STOP();
    delay(500);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    CURVAESQUERDA();

    FRENTE();
    delay(700);

    angleX = 0.01;
    while (angleX <= 60.00) {
      getAX();
      analogWrite(mfE, 170);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 190);
    }

    FRENTE();
    delay(2000);

    CURVADIREITA();

    TRAS();
    delay(500);

    FRENTE();
    delay(700);

    angleX = 0.01;
    while (angleX <= 35.00) {
      getAX();
      analogWrite(mfE, 170);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 190);
    }

    FRENTE();
    delay(3000);

    angleX = 0.01;
    while (angleX <= 60.00) {
      getAX();
      analogWrite(mfE, 170);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 190);
    }

    FRENTE();
    delay(1000);

    CURVADIREITA();

    TRAS();
    delay(700);

    analogWrite(mfE, 230);
    analogWrite(mtE, 0);
    analogWrite(mfD, 150);
    analogWrite(mtD, 0);
    delay(2200);

    CURVADIREITA();

    angleX = 0.01;
    while (angleX <= 35.00) {
      getAX();
      analogWrite(mfE, 170);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 190);
    }

    TRAS();
    delay(1000);

    STOP();
    delay(500);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    FRENTE();
    delay(200);

    TRAS();
    delay(250);

    STOP();
    delay(400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000);
  }
}
















void getAX()  {
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gX0);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gX0 = Wire.read();
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gX1);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gX1 = Wire.read();
  gX1 = gX1 << 8;
  gX_out = gX0 + gX1;
  Xg = gX_out * 0.0511;
  angleXc = Xg * dt;
  angleX = angleX + angleXc;
  Serial.println(angleX);
}

void getAZ()  {
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gZ0);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gZ0 = Wire.read();
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gZ1);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gZ1 = Wire.read();
  gZ1 = gZ1 << 8;
  gZ_out = gZ0 + gZ1;
  Zg = gZ_out * 0.07;
  angleZc = Zg * dt;
  angleZ = angleZ + angleZc;
  Serial.println(angleZ);
}

void STOP() {
  analogWrite(mfE, 255);
  analogWrite(mtE, 255);
  analogWrite(mfD, 255);
  analogWrite(mtD, 255);
}

void FRENTE() {
  analogWrite(mfE, 195);
  analogWrite(mtE, 0);
  analogWrite(mfD, 150);
  analogWrite(mtD, 0);
}

void CURVADIREITA() {
  angleX = 0.01;
  while (angleX <= 115.00) {
    getAX();
    analogWrite(mfE, 170);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 190);
  }
  angleX = 0;
}

void CURVAESQUERDA() {
  angleX = 0.01;
  while (angleX >= -105.00) {
    getAX();
    analogWrite(mfE, 0);
    analogWrite(mtE, 180);
    analogWrite(mfD, 180);
    analogWrite(mtD, 0);
  }
  angleX = 0;
}

void TRAS() {
  analogWrite(mfE, 0);
  analogWrite(mtE, 220);
  analogWrite(mfD, 0);
  analogWrite(mtD, 205);
}

void ATUALIZARSENSOR() {
  sensor_OC = analogRead(A1);
  sensor_OB = analogRead(A10);
  sensor_O = analogRead(A3);
}

