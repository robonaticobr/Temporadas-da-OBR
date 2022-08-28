///??????????

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
  pinMode(sensor_T, INPUT);   //redutor
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
    analogWrite(mfE, 195);
    analogWrite(mtE, 0);
    analogWrite(mfD, 185);
    analogWrite(mtD, 0);
  }
  //SEGUE LINHA AJUSTE
  if ((sensor_PE == 0) && (sensor_PD == 1))
  {
    digitalWrite(26, HIGH);
    analogWrite(mfE, 195);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 205);
  }
  if ((sensor_PE == 1) && (sensor_PD == 0))
  {
    digitalWrite(22, HIGH);
    analogWrite(mfE, 0);
    analogWrite(mtE, 185);
    analogWrite(mfD, 195);
    analogWrite(mtD, 0);
  }

  //OBJETOS

  if (sensor_O >= 630)
  {
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
    delay(1000);

    analogWrite(mfE, 200);
    analogWrite(mtE, 0);
    analogWrite(mfD, 180);
    analogWrite(mtD, 0);
    delay(850);

    analogWrite(mfE, 0);
    analogWrite(mtE, 210);
    analogWrite(mfD, 200);
    analogWrite(mtD, 0);
    delay(800);

    analogWrite(mfE, 200);
    analogWrite(mtE, 0);
    analogWrite(mfD, 180);
    analogWrite(mtD, 0);
    delay(2000);

    analogWrite(mfE, 0);
    analogWrite(mtE, 210);
    analogWrite(mfD, 200);
    analogWrite(mtD, 0);
    delay(900);

    analogWrite(mfE, 200);
    analogWrite(mtE, 0);
    analogWrite(mfD, 180);
    analogWrite(mtD, 0);
    delay(490);

    if (sensor_ED == 0)
    {
      sensor_ED = digitalRead(42);
      while (sensor_ED == 0)
      {
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

    if ((sensor_A == 0) && (curvaE == 1))
    {
      Serial.println(sensor_C);
      sensor_C = digitalRead(50);
      while (sensor_C == 0)
      {
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

  if (((sensor_EE == 1) && (sensor_A == 1) && (sensor_PE == 1)) || ((sensor_ED == 1) && (sensor_PD == 1) && (sensor_A == 1)))
  { //chave 1
    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

    sensor_EE = digitalRead(52);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(27);

    if (((sensor_EE == 1) && (sensor_A == 1) && (sensor_PE == 1)) || ((sensor_ED == 1) && (sensor_PD == 1) && (sensor_A == 1)))
    { //chave 2
      pinMode(22, OUTPUT);  // LEDBE
      digitalWrite(LEDBE, HIGH);
      pinMode(24, OUTPUT);  //LEDv
      digitalWrite(LEDv, HIGH);
      pinMode(30, OUTPUT);  // LEDBD
      digitalWrite(LEDBD, HIGH);

      analogWrite(mfE, 255);
      analogWrite(mtE, 255);
      analogWrite(mfD, 255);
      analogWrite(mtD, 255);
      delay(500);

      //ENCRUZILHADA meia volta

      if ((sensor_EE == 1) && (sensor_ED == 1))
      {
        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++)
        {
          sensor_VD = analogRead(A7);
          sensor_VE = analogRead(A15);
          davigay += sensor_VE;
          daviviado += sensor_VD;
        }
        sensor_VD = analogRead(A7);
        sensor_VE = analogRead(A15);

        if ((daviviado >= 1490) && (daviviado <= 2000) && (davigay >= 1370) && (davigay <= 2000))
        {
          curvaD = 1;
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);

          analogWrite(mfE, 190);
          analogWrite(mtE, 0);
          analogWrite(mfD, 0);
          analogWrite(mtD, 180);
          delay(2200);

          //          if ((sensor_EE == 0) && (curvaD = 1)) sensor_C = digitalRead(50);
          sensor_C = digitalRead(50);
          while (sensor_C == 0)
          {
            curvaD = 0;
            sensor_C = digitalRead(50);
            analogWrite(mfE, 190);
            analogWrite(mtE, 0);
            analogWrite(mfD, 0);
            analogWrite(mtD, 180);
          }
        }
        digitalWrite(mfE, 50);
        digitalWrite(mtD, 0);
        digitalWrite(mfD, 50);
        digitalWrite(mtE, 0);
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
          sensor_VD = analogRead(A7);
          sensor_VE = analogRead(A15);
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

          analogWrite(mfE, 180);
          analogWrite(mtE, 0);
          analogWrite(mfD, 180);
          analogWrite(mtD, 0);
          delay(200);

          analogWrite(mfE, 180);
          analogWrite(mtE, 0);
          analogWrite(mfD, 0);
          analogWrite(mtD, 200);
          delay(700);

          sensor_A = digitalRead(38);
          while (sensor_A == 0)
          {
            sensor_A = digitalRead(38);
            analogWrite(mfE, 170);
            analogWrite(mtE, 0);
            analogWrite(mfD, 0);
            analogWrite(mtD, 200);
          }
          digitalWrite(mfE, 160);
          digitalWrite(mtD, 0);
          digitalWrite(mfD, 160);
          digitalWrite(mtE, 0);
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
          sensor_VD = analogRead(A7);
          sensor_VE = analogRead(A15);
          davigay += sensor_VE;
          daviviado += sensor_VD;
        }

        if ((davigay >= 1370) && (davigay <= 2000))
        {
          pinMode(26, OUTPUT);  // LEDV
          digitalWrite(LEDV, HIGH);

          analogWrite(mfE, 160);
          analogWrite(mtE, 0);
          analogWrite(mfD, 160);
          analogWrite(mtD, 0);
          delay(190);

          analogWrite(mfE, 0);
          analogWrite(mtE, 190);
          analogWrite(mfD, 170);
          analogWrite(mtD, 0);
          delay(550);
          sensor_A = digitalRead(38);
          while (sensor_A == 0)
          {
            sensor_A = digitalRead(38);
            analogWrite(mfE, 0);
            analogWrite(mtE, 190);
            analogWrite(mfD, 160);
            analogWrite(mtD, 0);
          }
        }
        digitalWrite(mfE, 160);
        digitalWrite(mtD, 0);
        digitalWrite(mfD, 160);
        digitalWrite(mtE, 0);
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
        digitalWrite(mfE, 255);
        digitalWrite(mtD, 255);
        digitalWrite(mfE, 255);
        digitalWrite(mtD, 255);
        delay(1000);

        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++)
        {
          sensor_VD = analogRead(A7);
          sensor_VE = analogRead(A15);
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

          digitalWrite(mtE, 120);
          digitalWrite(mfD, 120);
          digitalWrite(mfE, 0);
          digitalWrite(mtD, 0);
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
              analogWrite(mfE, 0);
              analogWrite(mtE, 160);
              analogWrite(mfD, 150);
              analogWrite(mtD, 0);
            }
          }

          sensor_EE = digitalRead(52);
          sensor_C = digitalRead(50);
          sensor_A = digitalRead(38);
          sensor_ED = digitalRead(42);
          sensor_PE = digitalRead(44);
          sensor_PD = digitalRead(27);
        }

        digitalWrite(mfE, 160);
        digitalWrite(mtD, 0);
        digitalWrite(mfD, 160);
        digitalWrite(mtE, 0);
        delay(100);
        return;
      }

      //      }
      sensor_EE = digitalRead(52);
      sensor_C = digitalRead(50);
      sensor_A = digitalRead(38);
      sensor_ED = digitalRead(42);
      sensor_PE = digitalRead(44);
      sensor_PD = digitalRead(27);


      //      //T para direita
      if ((sensor_EE == 0) && (sensor_ED == 1))
      {
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
        sensor_PD = digitalRead(27);

        //        if ((sensor_EE == 0) && (sensor_ED == 1))
        //        {
        int davigay = 0;
        int daviviado = 0;
        for (int i = 0; i < 30; i++)
        {
          sensor_VD = analogRead(A7);
          sensor_VE = analogRead(A15);
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

          analogWrite(mfE, 150);
          analogWrite(mtE, 0);
          analogWrite(mfD, 150);
          analogWrite(mtD, 0);
          delay(150);

          analogWrite(mfE, 200);
          analogWrite(mtE, 0);
          analogWrite(mfD, 0);
          analogWrite(mtD, 180);
          delay(600);

          sensor_EE = digitalRead(52);
          sensor_C = digitalRead(50);
          sensor_A = digitalRead(38);
          sensor_ED = digitalRead(42);
          sensor_PE = digitalRead(44);
          sensor_PD = digitalRead(27);


          if ((sensor_A == 0) && (curvaD = 1)) {
            while (sensor_C == 0) {
              sensor_C = digitalRead(50);
              curvaD = 0;
              analogWrite(mfE, 200);
              analogWrite(mtE, 0);
              analogWrite(mfD, 0);
              analogWrite(mtD, 200);
            }
          }
          analogWrite(mfE, 160);
          analogWrite(mtE, 0);
          analogWrite(mfD, 160);
          analogWrite(mtD, 0);
          delay(100);
          return;
        }
      }
      digitalWrite(mfE, 50);
      digitalWrite(mtE, 0);
      digitalWrite(mfD, 50);
      digitalWrite(mtD, 0);
      delay(50);
      return;
    }  //chave 2
  }    //chave 1

  // 90° DIREITA
  if ((sensor_EE == 0) && (sensor_A == 0) && (sensor_C == 1) && (sensor_PD == 1) && (sensor_ED == 1)) {
    curvaD = 1;

    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

    pinMode(30, OUTPUT);  // LEDBD
    digitalWrite(LEDBD, HIGH);

    analogWrite(mfE, 190);
    analogWrite(mtE, 0);
    analogWrite(mfD, 190);
    analogWrite(mtD, 0);
    delay(140);

    sensor_EE = digitalRead(52);
    sensor_C = digitalRead(50);
    sensor_A = digitalRead(38);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(27);
    if ((sensor_A == 0) && (curvaD == 1)) {
      sensor_PE = digitalRead(44);
      while (sensor_PE == 0) {
        sensor_PE = digitalRead(44);
        curvaD = 0;
        sensor_PE = digitalRead(44);
        analogWrite(mfE, 220);
        analogWrite(mtE, 0);
        analogWrite(mfD, 0);
        analogWrite(mtD, 205);
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
    return;
  }


  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(27);
  //90° ESQUERDA
  if ((sensor_ED == 0) && (sensor_A == 0) && (sensor_PE == 1) && (sensor_C == 1) && (sensor_EE == 1))
  {
    curvaE = 1;

    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

    pinMode(22, OUTPUT);  // LEDBE
    digitalWrite(LEDBE, HIGH);

    analogWrite(mfE, 190);
    analogWrite(mtE, 0);
    analogWrite(mfD, 190);
    analogWrite(mtD, 0);
    delay(140);

    sensor_EE = digitalRead(52);
    sensor_C = digitalRead(50);
    sensor_A = digitalRead(38);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(27);
    if ((sensor_A == 0) && (curvaE == 1))
    {
      sensor_PD = digitalRead(27);
      while (sensor_PD == 0)
      {
        sensor_PD = digitalRead(27);
        curvaE = 0;
        sensor_PD = digitalRead(27);
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
    return;
  }

}
