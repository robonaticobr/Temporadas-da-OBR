//??????????

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
int sensor_PD(46);   //sensor ponta direita
int sensor_O(A3);    //sensor de objetos

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
  pinMode(sensor_EE, INPUT);         //ExtremoEsquerdo
  pinMode(sensor_C, INPUT);          //Central
  pinMode(sensor_A, INPUT);          //Avançado
  pinMode(sensor_ED, INPUT);         //ExtremoDireito
  pinMode(sensor_PE, INPUT_PULLUP);  //PontaEsquerda
  pinMode(sensor_PD, INPUT_PULLUP);  //PontaDireita
  pinMode(sensor_O, INPUT);          //objeto
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
  sensor_PD = digitalRead(46);
  sensor_O = analogRead(A3);

  //SEGUE LINHA GAP
  if ((sensor_PE == 0) && (sensor_PD == 0)) {
    analogWrite(mfE, 160);
    analogWrite(mtE, 0);
    analogWrite(mfD, 140);
    analogWrite(mtD, 0);
  }
  //SEGUE LINHA AJUSTE
  if ((sensor_PE == 0) && (sensor_PD == 1)) {
    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 190);
  }
  if ((sensor_PE == 1) && (sensor_PD == 0)) {
    analogWrite(mfE, 0);
    analogWrite(mtE, 180);
    analogWrite(mfD, 190);
    analogWrite(mtD, 0);
  }

  if (sensor_O >= 630) {
    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

    analogWrite(mfE, 0);
    analogWrite(mtE, 160);
    analogWrite(mfD, 0);
    analogWrite(mtD, 160);
    delay(100);

    analogWrite(mfE, 200);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 170);
    delay(950);

    analogWrite(mfE, 200);
    analogWrite(mtE, 0);
    analogWrite(mfD, 180);
    analogWrite(mtD, 0);
    delay(1000);

    analogWrite(mfE, 0);
    analogWrite(mtE, 210);
    analogWrite(mfD, 200);
    analogWrite(mtD, 0);
    delay(950);

    analogWrite(mfE, 200);
    analogWrite(mtE, 0);
    analogWrite(mfD, 180);
    analogWrite(mtD, 0);
    delay(1850);

    analogWrite(mfE, 0);
    analogWrite(mtE, 210);
    analogWrite(mfD, 200);
    analogWrite(mtD, 0);
    delay(900);

    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 160);
    analogWrite(mtD, 0);
    delay(800);

    if (sensor_ED == 0) {
      analogWrite(mfE, 180);
      analogWrite(mtE, 0);
      analogWrite(mfD, 160);
      analogWrite(mtD, 0);

      sensor_ED = digitalRead(42);
      while (sensor_ED == 0) {
        sensor_ED = digitalRead(42);
        analogWrite(mfE, 180);
        analogWrite(mtE, 0);
        analogWrite(mfD, 200);
        analogWrite(mtD, 0);
      }

      analogWrite(mfE, 180);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 180);
      delay(950);
    }

    if ((sensor_A == 0) && (curvaE == 1)) {
      Serial.println(sensor_C);
      sensor_C = digitalRead(50);
      while (sensor_C == 0) {
        sensor_C = digitalRead(50);
        curvaE = 0;
        sensor_C = digitalRead(50);
        analogWrite(mfE, 0);
        analogWrite(mtE, 210);
        analogWrite(mfD, 200);
        analogWrite(mtD, 0);
      }
    }
  }

  //IFzão

  if (((sensor_EE == 1) && (sensor_A == 1) && (sensor_PE == 1)) || ((sensor_ED == 1) && (sensor_PD == 1) && (sensor_A == 1))) {  //chave 1
    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(1100);

    sensor_EE = digitalRead(52);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(46);

    if (((sensor_EE == 1) && (sensor_A == 1) && (sensor_PE == 1)) || ((sensor_ED == 1) && (sensor_PD == 1) && (sensor_A == 1))) {  //chave 2
      pinMode(22, OUTPUT);                                                                                                         // LEDBE
      digitalWrite(LEDBE, HIGH);
      pinMode(24, OUTPUT);  //LEDv
      digitalWrite(LEDv, HIGH);
      pinMode(30, OUTPUT);  // LEDBD
      digitalWrite(LEDBD, HIGH);

      analogWrite(mfE, 255);
      analogWrite(mtE, 255);
      analogWrite(mfD, 255);
      analogWrite(mtD, 255);
      delay(1100);

      int davigay = 0;
      int daviviado = 0;
      for (int i = 0; i < 30; i++) {
        sensor_VD = analogRead(A7);
        sensor_VE = analogRead(A15);
        davigay += sensor_VE;
        daviviado += sensor_VD;
      }

      //      Serial.print("VE"); Serial.print(" | "); Serial.print(davigay); Serial.print(" VD | "); Serial.println(daviviado);
      //      analogWrite(mfE, 0);
      //      analogWrite(mtE, 0);
      //      analogWrite(mfD, 0);
      //      analogWrite(mtD, 0);
      //      delay(500);

      //ENCRUZILHADA meia volta

      if ((sensor_EE == 1) && (sensor_ED == 1)) {
        sensor_VD = analogRead(A7);
        sensor_VE = analogRead(A15);

        if ((daviviado >= 1582) && (daviviado <= 1700) && (davigay >= 1510) && (davigay <= 1600)) {
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);

          analogWrite(mfE, 180);
          analogWrite(mtE, 0);
          analogWrite(mfD, 0);
          analogWrite(mtD, 200);
          delay(1600);

          if (sensor_A == 0) curvaD = 1;
          sensor_A = digitalRead(38);
          while (sensor_A == 0) {
            curvaD = 0;
            sensor_A = digitalRead(38);
            analogWrite(mfE, 180);
            analogWrite(mtE, 0);
            analogWrite(mfD, 0);
            analogWrite(mtD, 200);
          }
        }
      }
      //ENCRUZILHADA curva para direita

      if ((sensor_EE == 1) && (sensor_ED == 1)) {
        pinMode(30, OUTPUT);  // LEDBD
        digitalWrite(LEDBD, HIGH);
        pinMode(24, OUTPUT);  //LEDv
        digitalWrite(LEDv, HIGH);

        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++) {
          sensor_VD = analogRead(A7);
          sensor_VE = analogRead(A15);
          davigay += sensor_VE;
          daviviado += sensor_VD;
        }
        //        Serial.print("VE"); Serial.print(" | "); Serial.print(davigay); Serial.print(" VD | "); Serial.println(daviviado);
        //        delay(12345678);
        //      {
        //        analogWrite(mfE, 0);
        //        analogWrite(mtE, 0);
        //        analogWrite(mfD, 0);
        //        analogWrite(mtD, 0);
        //        sensor_VE = analogRead(A15);
        //        sensor_VD = analogRead(A7);
        //
        //        Serial.print(sensor_VE); Serial.print(" | "); Serial.println(sensor_VD);
        //      }

        Serial.print(sensor_VE);
        Serial.print(" | ");
        Serial.println(sensor_VD);
        if ((daviviado >= 1582) && (daviviado <= 1700)) {
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);

          analogWrite(mfE, 180);
          analogWrite(mtE, 0);
          analogWrite(mfD, 180);
          analogWrite(mtD, 0);
          delay(180);

          analogWrite(mfE, 180);
          analogWrite(mtE, 0);
          analogWrite(mfD, 0);
          analogWrite(mtD, 200);
          delay(800);

          sensor_A = digitalRead(38);
          while (sensor_A == 0) {
            sensor_A = digitalRead(38);
            analogWrite(mfE, 170);
            analogWrite(mtE, 0);
            analogWrite(mfD, 0);
            analogWrite(mtD, 200);
          }
          digitalWrite(mfE, 0);
          digitalWrite(mtD, 0);
          digitalWrite(mfE, 0);
          digitalWrite(mtD, 0);
          delay(500);
          return;
        }
      }

      //ENCRUZILHADA curva para esquerda
      if ((sensor_EE == 1) && (sensor_ED == 1)) {
        pinMode(22, OUTPUT);  // LEDBE
        digitalWrite(LEDBE, HIGH);
        pinMode(24, OUTPUT);  //LEDv
        digitalWrite(LEDv, HIGH);

        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++) {
          sensor_VD = analogRead(A7);
          sensor_VE = analogRead(A15);
          davigay += sensor_VE;
          daviviado += sensor_VD;
        }
        //        Serial.print("VE"); Serial.print(" | "); Serial.print(davigay); Serial.print(" VD | "); Serial.println(daviviado);
        //        analogWrite(mfE, 0);
        //        analogWrite(mtE, 0);
        //        analogWrite(mfD, 0);
        //        analogWrite(mtD, 0);
        //        delay(12345678);
        //      {
        //          analogWrite(mfE, 0);
        //          analogWrite(mtE, 0);
        //          analogWrite(mfD, 0);
        //          analogWrite(mtD, 0);
        //          sensor_VE = analogRead(A15);
        //          sensor_VD = analogRead(A7);
        //
        //          Serial.print(sensor_VE); Serial.print(" | "); Serial.println(sensor_VD);
        //        }
        //
        //        Serial.print(sensor_VE); Serial.print(" | "); Serial.println(sensor_VD);

        if ((davigay >= 1500) && (davigay <= 1700)) {
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);

          analogWrite(mfE, 160);
          analogWrite(mtE, 0);
          analogWrite(mfD, 160);
          analogWrite(mtD, 0);
          delay(190);

          analogWrite(mfE, 0);
          analogWrite(mtE, 200);
          analogWrite(mfD, 170);
          analogWrite(mtD, 0);
          delay(800);
          sensor_A = digitalRead(38);
          while (sensor_A == 0) {
            sensor_A = digitalRead(38);
            analogWrite(mfE, 0);
            analogWrite(mtE, 190);
            analogWrite(mfD, 160);
            analogWrite(mtD, 0);
          }
          digitalWrite(mfE, 0);
          digitalWrite(mtD, 0);
          digitalWrite(mfE, 0);
          digitalWrite(mtD, 0);
          delay(500);
          return;
        }
      }
      //T para esquerda
      if ((sensor_EE == 1) && (sensor_ED == 0)) {
        digitalWrite(mfE, 255);
        digitalWrite(mtD, 255);
        digitalWrite(mfE, 255);
        digitalWrite(mtD, 255);
        delay(1000);

        sensor_EE = digitalRead(52);
        sensor_C = digitalRead(50);
        sensor_A = digitalRead(38);
        sensor_ED = digitalRead(42);
        sensor_PE = digitalRead(44);
        sensor_PD = digitalRead(46);

        if ((sensor_EE == 1) && (sensor_ED == 0)) {
          int davigay = 0;
          int daviviado = 0;
          for (int i = 0; i < 30; i++) {
            sensor_VD = analogRead(A7);
            sensor_VE = analogRead(A15);
            davigay += sensor_VE;
            daviviado += sensor_VD;
          }
          //                            Serial.print("VE"); Serial.print(" | "); Serial.print(davigay); Serial.print(" VD | "); Serial.println(daviviado);
          //                            analogWrite(mfE, 0);
          //                            analogWrite(mtE, 0);
          //                            analogWrite(mfD, 0);
          //                            analogWrite(mtD, 0);
          //                            delay(12345678);
          //                          {
          //                            sensor_VD = analogRead(A7);
          //                            sensor_VE = analogRead(A15);
          //                            analogWrite(mfE, 0);
          //                            analogWrite(mtE, 0);
          //                            analogWrite(mfD, 0);
          //                            analogWrite(mtD, 0);
          //                            sensor_VE = analogRead(A15);
          //                            sensor_VD = analogRead(A7);
          //
          //                            Serial.print(sensor_VE); Serial.print(" | "); Serial.println(sensor_VD);
          //                          }

          if ((davigay >= 1405) && (davigay <= 1700)) {
            curvaE = 1;
            pinMode(26, OUTPUT);  // LEDV
            digitalWrite(LEDV, HIGH);
            pinMode(22, OUTPUT);  // LEDBE
            digitalWrite(LEDBE, HIGH);
            pinMode(28, OUTPUT);  //LEDA
            digitalWrite(LEDA, HIGH);

            analogWrite(mfE, 180);
            analogWrite(mtE, 0);
            analogWrite(mfD, 180);
            analogWrite(mtD, 0);
            delay(150);


            analogWrite(mfE, 0);
            analogWrite(mtE, 210);
            analogWrite(mfD, 200);
            analogWrite(mtD, 0);
            delay(700);

            sensor_EE = digitalRead(52);
            sensor_C = digitalRead(50);
            sensor_A = digitalRead(38);
            sensor_ED = digitalRead(42);
            sensor_PE = digitalRead(44);
            sensor_PD = digitalRead(46);

            //            { sensor_C = digitalRead(50);
            //              while (sensor_C == 0)
            //              { sensor_C = digitalRead(50);
            //                curvaE = 0;
            //                analogWrite(mfE, 0);
            //                analogWrite(mtE, 200);
            //                analogWrite(mfD, 170);
            //                analogWrite(mtD, 0);
            //                Serial.print(sensor_C);
            //              }
            //            }
            //            { sensor_PD = digitalRead(46);
            //              while (sensor_PD == 0)
            //              { sensor_PD = digitalRead(46);
            //                curvaE = 0;
            //                analogWrite(mfE, 0);
            //                analogWrite(mtE, 200);
            //                analogWrite(mfD, 170);
            //                analogWrite(mtD, 0);
            //                Serial.print(sensor_PD);
            //              }
            //            }

            digitalWrite(mfE, 0);
            digitalWrite(mtD, 0);
            digitalWrite(mfE, 0);
            digitalWrite(mtD, 0);
            delay(500);
            return;
          }
        }
      }
      sensor_EE = digitalRead(52);
      sensor_C = digitalRead(50);
      sensor_A = digitalRead(38);
      sensor_ED = digitalRead(42);
      sensor_PE = digitalRead(44);
      sensor_PD = digitalRead(46);


      //      //T para direita
      if ((sensor_EE == 0) && (sensor_ED == 1)) {
        curvaD = 1;
        digitalWrite(mfE, 255);
        digitalWrite(mtD, 255);
        digitalWrite(mfE, 255);
        digitalWrite(mtD, 255);
        delay(1000);

        sensor_EE = digitalRead(52);
        sensor_C = digitalRead(50);
        sensor_A = digitalRead(38);
        sensor_ED = digitalRead(42);
        sensor_PE = digitalRead(44);
        sensor_PD = digitalRead(46);

        if ((sensor_EE == 0) && (sensor_ED == 1)) {
          int davigay = 0;
          int daviviado = 0;
          for (int i = 0; i < 30; i++) {
            sensor_VD = analogRead(A7);
            sensor_VE = analogRead(A15);
            davigay += sensor_VE;
            daviviado += sensor_VD;
          }
          //          //        Serial.print("VE"); Serial.print(" | "); Serial.print(davigay); Serial.print(" VD | "); Serial.println(daviviado);
          //          //        analogWrite(mfE, 0);
          //          //        analogWrite(mtE, 0);
          //          //        analogWrite(mfD, 0);
          //          //        analogWrite(mtD, 0);
          //          //        delay(12345678);
          //          //      {
          //          //        sensor_VD = analogRead(A7);
          //          //        sensor_VE = analogRead(A15);
          //          //
          //          //        analogWrite(mfE, 0);
          //          //        analogWrite(mtE, 0);
          //          //        analogWrite(mfD, 0);
          //          //        analogWrite(mtD, 0);
          //          //        sensor_VE = analogRead(A15);
          //          //        sensor_VD = analogRead(A7);
          //          //
          //          //        Serial.print(sensor_VE); Serial.print(" | "); Serial.println(sensor_VD);
          //          //      }
          //          //
          //          //      Serial.print(sensor_VE); Serial.print(" | "); Serial.println(sensor_VD);
          if ((daviviado >= 1582) && (daviviado <= 1700)) {
            pinMode(30, OUTPUT);  // LEDBD
            digitalWrite(LEDBD, HIGH);
            pinMode(26, OUTPUT);  // LEDV
            digitalWrite(LEDV, HIGH);
            pinMode(28, OUTPUT);  //LEDA
            digitalWrite(LEDA, HIGH);

            analogWrite(mfE, 180);
            analogWrite(mtE, 0);
            analogWrite(mfD, 180);
            analogWrite(mtD, 0);
            delay(150);

            analogWrite(mfE, 180);
            analogWrite(mtE, 0);
            analogWrite(mfD, 0);
            analogWrite(mtD, 180);
            delay(700);

            sensor_EE = digitalRead(52);
            sensor_C = digitalRead(50);
            sensor_A = digitalRead(38);
            sensor_ED = digitalRead(42);
            sensor_PE = digitalRead(44);
            sensor_PD = digitalRead(46);

            {
              while (sensor_A == 0) {
                sensor_A = digitalRead(38);
                curvaD = 0;
                analogWrite(mfE, 210);
                analogWrite(mtE, 0);
                analogWrite(mfD, 0);
                analogWrite(mtD, 200);
              }
            }
            analogWrite(mfE, 0);
            analogWrite(mtE, 0);
            analogWrite(mfD, 0);
            analogWrite(mtD, 0);
            delay(500);
            return;
          }
        }
      }
    }  //chave 2
  }    //chave 1
  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(46);

  //

  // 90° DIREITA
  if ((sensor_EE == 0) && (sensor_A == 0) && (sensor_C == 1) && (sensor_PD == 1) && (sensor_ED == 1)) {
    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);
    curvaD = 1;
    pinMode(30, OUTPUT);  // LEDBD
    digitalWrite(LEDBD, HIGH);
    analogWrite(mfE, 190);
    analogWrite(mtE, 0);
    analogWrite(mfD, 190);
    analogWrite(mtD, 0);
    delay(160);

    digitalWrite(LEDBD, HIGH);
    sensor_EE = digitalRead(52);
    sensor_C = digitalRead(50);
    sensor_A = digitalRead(38);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(46);
    if ((sensor_A == 0) && (curvaD == 1)) {
      digitalWrite(LEDBD, HIGH);
      while (sensor_A == 0) {
        sensor_A = digitalRead(38);
        curvaD = 0;
        analogWrite(mfE, 210);
        analogWrite(mtE, 0);
        analogWrite(mfD, 0);
        analogWrite(mtD, 200);
      }
    }
    analogWrite(mfE, 0);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 0);
    delay(500);

    //    analogWrite(mfE, 0);
    //    analogWrite(mtE, 120);
    //    analogWrite(mfD, 0);
    //    analogWrite(mtD, 140);
    //    delay(80);
    sensor_EE = digitalRead(52);
    sensor_C = digitalRead(50);
    sensor_A = digitalRead(38);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(46);
    return;


    //90° ESQUERDA
    if ((sensor_ED == 0) && (sensor_A == 0) && (sensor_C == 1) && (sensor_PE == 1) && (sensor_EE == 1)) {
      analogWrite(mfE, 255);
      analogWrite(mtE, 255);
      analogWrite(mfD, 255);
      analogWrite(mtD, 255);
      delay(500);
      curvaE = 1;
      pinMode(22, OUTPUT);  // LEDBE
      digitalWrite(LEDBE, HIGH);

      analogWrite(mfE, 190);
      analogWrite(mtE, 0);
      analogWrite(mfD, 190);
      analogWrite(mtD, 0);
      delay(155);

      sensor_EE = digitalRead(52);
      sensor_C = digitalRead(50);
      sensor_A = digitalRead(38);
      sensor_ED = digitalRead(42);
      sensor_PE = digitalRead(44);
      sensor_PD = digitalRead(46);
      if ((sensor_A == 0) && (curvaE == 1)) {
        Serial.println(sensor_C);
        sensor_C = digitalRead(50);
        while (sensor_C == 0) {
          sensor_C = digitalRead(50);
          curvaE = 0;
          sensor_C = digitalRead(50);
          analogWrite(mfE, 0);
          analogWrite(mtE, 210);
          analogWrite(mfD, 200);
          analogWrite(mtD, 0);
        }
      }

      analogWrite(mfE, 255);
      analogWrite(mtE, 255);
      analogWrite(mfD, 255);
      analogWrite(mtD, 255);
      delay(500);

      analogWrite(mfE, 0);
      analogWrite(mtE, 120);
      analogWrite(mfD, 0);
      analogWrite(mtD, 140);
      delay(160);
    }
    return;
  }