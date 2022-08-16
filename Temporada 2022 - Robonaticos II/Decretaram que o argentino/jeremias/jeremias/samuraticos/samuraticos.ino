
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
int sensor_VE(A15);   //sensor verde esquerdo
int sensor_VD(A7);   //sensor verde direito
int sensor_EE(52);    //sensor extrema esquerda
int sensor_C(50);     //sensor central
int sensor_A(38);     //sensor avançado
int sensor_ED(42);    //sensor extrema direita
int sensor_PE(44);    //sensor ponta esquerda
int sensor_PD(46);    //sensor ponta direita

void setup() {




  //CONFIGURAÇÃO MOTORES
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(26, OUTPUT); //LEDV
  pinMode(24, OUTPUT); //LEDv
  pinMode(28, OUTPUT); //LEDA
  pinMode(22, OUTPUT); // LEDBE
  pinMode(30, OUTPUT);// LEDBD

  Serial.begin(9600);

  //CONFIGURAÇÃO SENSORES
  pinMode(sensor_VD, INPUT_PULLUP); //VerdeDireito
  pinMode(sensor_VE, INPUT_PULLUP); //VerdeEsquerdo
  pinMode(sensor_EE, INPUT); //ExtremoEsquerdo
  pinMode(sensor_C, INPUT); //Central
  pinMode(sensor_A, INPUT); //Avançado
  pinMode(sensor_ED, INPUT); //ExtremoDireito
  pinMode(sensor_PE, INPUT); //PontaEsquerda
  pinMode(sensor_PD, INPUT); //PontaDireita

}

void loop() {




  // BLOCO DE LEITURA DE SENSORES
  Serial.println(sensor_A);
  digitalWrite(26, LOW);
  sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);
  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(46);




  //SEGUE LINHA GAP
  if ((sensor_PE == 0) && (sensor_PD == 0))

  {
    analogWrite(mfE, 120);
    analogWrite(mtE, 0);
    analogWrite(mfD, 130);
    analogWrite(mtD, 0);
    verdeD = 0;
  }




  //SEGUE LINHA AJUSTE
  if ((sensor_PE == 0) && (sensor_PD == 1))

  {
    analogWrite(mfE, 140);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 120);
    verdeD = 0;

  }

  if ((sensor_PE == 1) && (sensor_PD == 0))
  {
    analogWrite(mfE, 0);
    analogWrite(mtE, 120);
    analogWrite(mfD, 140);
    analogWrite(mtD, 0);
    verdeD = 0;
  }

  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(46);
  // 90° DIREITA

    if ((sensor_EE == 0) && (sensor_A == 0) && (sensor_C == 1) && (sensor_PD == 1) && (sensor_ED == 1))
    {
  
      analogWrite(mfE, 255);
      analogWrite(mtE, 255);
      analogWrite(mfD, 255);
      analogWrite(mtD, 255);
      delay(500);
  
      pinMode(30, OUTPUT);// LEDBD
      digitalWrite(LEDBD, HIGH);
  
      analogWrite(mfE, 160);
      analogWrite(mtE, 0);
      analogWrite(mfD, 160);
      analogWrite(mtD, 0);
      delay(100);
    }
  
     // if (sensor_A == 0)  curvaD = 1;
  
  
    sensor_EE = digitalRead(52);
    sensor_C = digitalRead(50);
    sensor_A = digitalRead(38);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(46);
  
  
    if (curvaD == 0)
    {
      Serial.println(sensor_C);
      sensor_C = digitalRead(50);
      while (sensor_C == 0)
      {
        curvaD = 0;
  
        sensor_C = digitalRead(50);
        analogWrite(mfE, 150);
        analogWrite(mtE, 0);
        analogWrite(mfD, 0);
        analogWrite(mtD, 160);
      }
  
      analogWrite(mfE, 255);
      analogWrite(mtE, 255);
      analogWrite(mfD, 255);
      analogWrite(mtD, 255);
      delay(500);
  
      analogWrite(mfE, 0);
      analogWrite(mtE, 120);
      analogWrite(mfD, 0);
      analogWrite(mtD, 130);
      delay(200);
  
  
      return;
    }


  //90° ESQUERDA
  if ((sensor_ED == 0) && (sensor_A == 0) && (sensor_C == 1) && (sensor_PE == 1) && (sensor_EE == 1))
  {
    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);
    curvaE = 1;
    pinMode(22, OUTPUT); // LEDBE
    digitalWrite(LEDBE, HIGH);

    // HIGH
    // LOW
    analogWrite(mfE, 160);
    analogWrite(mtE, 0);
    analogWrite(mfD, 170);
    analogWrite(mtD, 0);
    delay(100);

    sensor_EE = digitalRead(52);
    sensor_C = digitalRead(50);
    sensor_A = digitalRead(38);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(46);

      if ((sensor_A == 0) && ( curvaE == 1))
      {
        sensor_EE = digitalRead(52);
        sensor_C = digitalRead(50);
        sensor_A = digitalRead(38);
        sensor_ED = digitalRead(42);
        sensor_PE = digitalRead(44);
        sensor_PD = digitalRead(46);
  
        Serial.println(sensor_PD);
        sensor_PD = digitalRead(46);
        while (sensor_PD == 0)
        { sensor_PD = digitalRead(46);
  
          curvaE = 0;
  
          sensor_PD = digitalRead(46);
  
          analogWrite(mfE, 0);
          analogWrite(mtE, 150);
          analogWrite(mfD, 160);
          analogWrite(mtD, 0);
  
        }
  
        analogWrite(mfE, 255);
        analogWrite(mtE, 255);
        analogWrite(mfD, 255);
        analogWrite(mtD, 255);
        delay(500);
  
        analogWrite(mfE, 0);
        analogWrite(mtE, 120);
        analogWrite(mfD, 0);
        analogWrite(mtD, 130);
        delay(200);
      } return;
  
    }
  }

