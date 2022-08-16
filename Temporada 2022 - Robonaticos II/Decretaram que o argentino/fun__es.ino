///??????????

#include <Wire.h>

#define Gyro_gY0    0x2A
#define Gyro_gY1    0x2B
#define Gyro_gZ0    0x2C
#define Gyro_gZ1    0x2D

int Gyro = 0x69;

int gY0, gY1, gY_out;
int gZ0, gZ1, gZ_out;

float Yg, Zg;
float angleY, angleZ, angleYc, angleZc;
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



//VARIAVEIS GLOBAIS
byte curvaD = 0;
byte curvaE = 0;
int verde = 50;
int verdeD = 0;
int verdeE = 0;



//DECLARANDO SENSORES
int sensor_VE(A15);  //sensor verde esquerdo
int sensor_VD(A7);   //sensor verde direito
int sensor_EE(52);   //sensor extrema esquerda
int sensor_C(50);    //sensor central
int sensor_A(38);    //sensor avançado
int sensor_ED(42);   //sensor extrema direita
int sensor_PE(44);   //sensor ponta esquerda
int sensor_PD(27);   //sensor ponta direita
int sensor_O(A3);    //sensor de objetos
int sensor_T(53);   //sensor de redutor

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
  pinMode(sensor_VD, INPUT_PULLUP);  //VerdeDireito
  pinMode(sensor_VE, INPUT_PULLUP);  //VerdeEsquerdo
  pinMode(sensor_EE, INPUT_PULLUP);         //ExtremoEsquerdo
  pinMode(sensor_C, INPUT_PULLUP);          //Central
  pinMode(sensor_A, INPUT_PULLUP);          //Avançado
  pinMode(sensor_ED, INPUT_PULLUP);         //ExtremoDireito
  pinMode(sensor_PE, INPUT_PULLUP);  //PontaEsquerda
  pinMode(sensor_PD, INPUT_PULLUP);  //PontaDireita
  pinMode(sensor_O, INPUT);          //objeto
  
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
}

void loop() {
  // BLOCO DE LEITURA DE SENSORES
  digitalWrite(26, LOW);
  digitalWrite(24, LOW);
  digitalWrite(30, LOW);
  digitalWrite(22, LOW);
  digitalWrite(28, LOW);
  sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);
  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(27);
  sensor_O = analogRead(A3);
  sensor_T = digitalRead(53);

  //SEGUE LINHA GAP
  if ((sensor_PE == 0) && (sensor_PD == 0))
  {
    FRENTE();
  }
  //SEGUE LINHA AJUSTE
  if ((sensor_PE == 0) && (sensor_PD == 1))
  {
    digitalWrite(26, HIGH);
    CURVADIREITA();
  }
  if ((sensor_PE == 1) && (sensor_PD == 0))
  {
    digitalWrite(22, HIGH);
    CURVAESQUERDA();
  }

  //OBJETOS

  if (sensor_O >= 630)
  {
    STOP();
    delay(500);

    TRAS();
    delay(100);

    CURVADIREITA();
    delay(1000);

    FRENTE();
    delay(850);

    CURVAESQUERDA();
    delay(800);

    FRENTE();
    delay(2000);

    CURVAESQUERDA();
    delay(900);

    FRENTE();
    delay(490);

    if (sensor_ED == 0)
    {
      sensor_ED = digitalRead(42);
      while (sensor_ED == 0)
      {
        sensor_ED = digitalRead(42);
        FRENTE();
      }

      CURVADIREITA();
      delay(950);
    }

    if ((sensor_A == 0) && (curvaE == 1))
    {
      Serial.println(sensor_C);
      sensor_C = digitalRead(50);
      while (sensor_C == 0)
      {
        sensor_C = digitalRead(50);
        curvaE = 0;
        sensor_C = digitalRead(50);
        CURVAESQUERDA();
      }
    }
  }
  //IFzão

  if (((sensor_EE == 1) && (sensor_A == 1) && (sensor_PE == 1)) || ((sensor_ED == 1) && (sensor_PD == 1) && (sensor_A == 1)))
  { //chave 1
    STOP();
    delay(500);

    ATUALIZARSENSOR();

    if (((sensor_EE == 1) && (sensor_A == 1) && (sensor_PE == 1)) || ((sensor_ED == 1) && (sensor_PD == 1) && (sensor_A == 1)))
    { //chave 2
      pinMode(22, OUTPUT);  // LEDBE
      digitalWrite(LEDBE, HIGH);
      pinMode(24, OUTPUT);  //LEDv
      digitalWrite(LEDv, HIGH);
      pinMode(30, OUTPUT);  // LEDBD
      digitalWrite(LEDBD, HIGH);

      STOP();
      delay(500);

      //ENCRUZILHADA meia volta

      if ((sensor_EE == 1) && (sensor_ED == 1))
      {
        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++)
        {
          ATUALIZARSENSOR();
          davigay += sensor_VE;
          daviviado += sensor_VD;
        }
        ATUALIZARSENSOR();

        if ((daviviado >= 1490) && (daviviado <= 2000) && (davigay >= 1370) && (davigay <= 2000))
        {
          curvaD = 1;
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);

          CURVADIREITA();
          delay(2200);

          //          if ((sensor_EE == 0) && (curvaD = 1)) sensor_C = digitalRead(50);
          sensor_C = digitalRead(50);
          while (sensor_C == 0)
          {
            curvaD = 0;
            sensor_C = digitalRead(50);
            CURVADIREITA();
          }
        }
        FRENTE();
        delay(70);
        return;
      }
      //ENCRUZILHADA curva para direita

      if ((sensor_EE == 1) && (sensor_ED == 1))
      {
        pinMode(30, OUTPUT);  // LEDBD
        digitalWrite(LEDBD, HIGH);
        pinMode(24, OUTPUT);  //LEDv
        digitalWrite(LEDv, HIGH);

        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++)
        {
          ATUALIZARSENSOR();
          davigay += sensor_VE;
          daviviado += sensor_VD;
        }

        Serial.print(sensor_VE);
        Serial.print(" | ");
        Serial.println(sensor_VD);
        if ((daviviado >= 1490) && (daviviado <= 2000))
        {
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);

          FRENTE();
          delay(200);

          CURVADIREITA();
          delay(700);

          sensor_A = digitalRead(38);
          while (sensor_A == 0)
          {
            sensor_A = digitalRead(38);
            CURVADIREITA();
          }
          FRENTE();
          delay(100);
          return;
        }
      }

      //ENCRUZILHADA curva para esquerda
      if ((sensor_EE == 1) && (sensor_ED == 1))
      {
        pinMode(22, OUTPUT);  // LEDBE
        digitalWrite(LEDBE, HIGH);
        pinMode(24, OUTPUT);  //LEDv
        digitalWrite(LEDv, HIGH);

        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++)
        {
          ATUALIZARSENSOR();
          davigay += sensor_VE;
          daviviado += sensor_VD;
        }

        if ((davigay >= 1370) && (davigay <= 2000))
        {
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);

          FRENTE();
          delay(190);

          CURVAESQUERDA();
          delay(550);
          sensor_A = digitalRead(38);
          while (sensor_A == 0)
          {
            sensor_A = digitalRead(38);
            CURVAESQUERDA();
          }
        }
        FRENTE();
        delay(100);
        return;
      }

      //T para esquerda
      //      if ((sensor_EE == 1) && (sensor_ED == 0))
      //      {
      //        digitalWrite(mfE, 255);
      //        digitalWrite(mtD, 255);
      //        digitalWrite(mfE, 255);
      //        digitalWrite(mtD, 255);
      //        delay(1000);
      //
      //        sensor_EE = digitalRead(52);
      //        sensor_C = digitalRead(50);
      //        sensor_A = digitalRead(38);
      //        sensor_ED = digitalRead(42);
      //        sensor_PE = digitalRead(44);
      //        sensor_PD = digitalRead(27);

      if ((sensor_EE == 1) && (sensor_ED == 0))
      {
        STOP();
        delay(1000);

        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++)
        {
          ATUALIZARSENSOR();
          davigay += sensor_VE;
          daviviado += sensor_VD;
        }

        if ((davigay >= 1370) && (davigay <= 2000))
        {
          curvaE = 1;
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);
          pinMode(22, OUTPUT);  // LEDBE
          digitalWrite(LEDBE, HIGH);
          pinMode(28, OUTPUT);  //LEDA
          digitalWrite(LEDA, HIGH);

          CURVAESQUERDA();
          delay(400);

          if ((sensor_A == 0) && (curvaE == 1))
          {
            Serial.println(sensor_A);
            sensor_PD = digitalRead(27);
            while (sensor_PD == 0)
            {
              sensor_PD = digitalRead(27);
              curvaE = 0;
              sensor_PD = digitalRead(27);
              CURVAESQUERDA();
            }
          }

          ATUALIZARSENSOR();
        }

        FRENTE();
        delay(100);
        return;
      }

      //      }
      ATUALIZARSENSOR();


      //      //T para direita
      if ((sensor_EE == 0) && (sensor_ED == 1))
      {
        curvaD = 1;
        STOP();
        delay(1000);

        ATUALIZARSENSOR();

        //        if ((sensor_EE == 0) && (sensor_ED == 1))
        //        {
        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++)
        {
          ATUALIZARSENSOR();
          davigay += sensor_VE;
          daviviado += sensor_VD;
        }

        if ((daviviado >= 1490) && (daviviado <= 2000)) {
          pinMode(30, OUTPUT);  // LEDBD
          digitalWrite(LEDBD, HIGH);
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);
          pinMode(28, OUTPUT);  //LEDA
          digitalWrite(LEDA, HIGH);

          FRENTE();
          delay(150);

          CURVADIREITA();
          delay(600);

          ATUALIZARSENSOR();

          if ((sensor_A == 0) && (curvaD = 1)) {
            while (sensor_C == 0) {
              sensor_C = digitalRead(50);
              curvaD = 0;
              CURVADIREITA();
            }
          }
          FRENTE();
          delay(100);
        }
        FRENTE();
        delay(50);
        return;
      }
    }  //chave 2
  }    //chave 1

  // 90° DIREITA
  if ((sensor_EE == 0) && (sensor_A == 0) && (sensor_C == 1) && (sensor_PD == 1) && (sensor_ED == 1)) {
    curvaD = 1;
    STOP();
    delay(500);

    pinMode(30, OUTPUT);  // LEDBD
    digitalWrite(LEDBD, HIGH);

    FRENTE();
    delay(140);

    ATUALIZARSENSOR();
    if ((sensor_A == 0) && (curvaD == 1)) {
      sensor_PE = digitalRead(44);
      while (sensor_PE == 0) {
        sensor_PE = digitalRead(44);
        curvaD = 0;
        sensor_PE = digitalRead(44);
        CURVADIREITA();
      }
    }
    STOP();
    delay(500);

    TRAS();
    delay(160);
    return;
  }

  ATUALIZARSENSOR();
  //90° ESQUERDA
  if ((sensor_ED == 0) && (sensor_A == 0) && (sensor_PE == 1) && (sensor_C == 1) && (sensor_EE == 1))
  {
    curvaE = 1;

    STOP();
    delay(500);

    pinMode(22, OUTPUT);  // LEDBE
    digitalWrite(LEDBE, HIGH);

    FRENTE();
    delay(140);

    ATUALIZARSENSOR();
    if ((sensor_A == 0) && (curvaE == 1))
    {
      sensor_PD = digitalRead(27);
      while (sensor_PD == 0)
      {
        sensor_PD = digitalRead(27);
        curvaE = 0;
        sensor_PD = digitalRead(27);
        CURVAESQUERDA();
      }
    }

    STOP();
    delay(500);

    TRAS();
    delay(160);
    return;
  }

}

void getAY()  {
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gY0);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gY0 = Wire.read();
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gY1);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gY1 = Wire.read();
  gY1 = gY1 << 8;
  gY_out = gY0 + gY1;
  Yg = gY_out * 0.07;
  angleYc = Yg * dt;
  angleY = angleY + angleYc;
  Serial.println(angleY);
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
  Zg = gZ_out * 0.044;
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
  analogWrite(mfE, 130);
  analogWrite(mtE, 0);
  analogWrite(mfD, 130);
  analogWrite(mtD, 0);
}

void CURVADIREITA() {
  analogWrite(mfE, 170);
  analogWrite(mtE, 0);
  analogWrite(mfD, 0);
  analogWrite(mtD, 190);
}

void CURVAESQUERDA() {
  analogWrite(mfE, 0);
  analogWrite(mtE, 150);
  analogWrite(mfD, 180);
  analogWrite(mtD, 0);
}

void TRAS() {
  analogWrite(mfE, 0);
  analogWrite(mtE, 120);
  analogWrite(mfD, 0);
  analogWrite(mtD, 140);
}

void ATUALIZARSENSOR() {
  sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);
  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(27);
  sensor_O = analogRead(A3);
  sensor_T = digitalRead(53);
}
