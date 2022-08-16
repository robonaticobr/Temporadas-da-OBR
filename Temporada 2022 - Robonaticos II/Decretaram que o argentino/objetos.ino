//PROGRMAÇÃO_SAMURAI
//DECLARANDO MOTORES
byte mfE = 5;
byte mtE = 4;
byte mfD = 7;
byte mtD = 6;


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
int sensor_O(A3);     //sensor de objetos

void setup()
{
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
  pinMode(sensor_PE, INPUT_PULLUP); //PontaEsquerda
  pinMode(sensor_PD, INPUT_PULLUP); //PontaDireita
  pinMode(sensor_O, INPUT); //objeto
}

void loop()
{
  // BLOCO DE LEITURA DE SENSORES

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
  if ((sensor_PE == 0) && (sensor_PD == 0))
  {
    analogWrite(mfE, 160);
    analogWrite(mtE, 0);
    analogWrite(mfD, 140);
    analogWrite(mtD, 0);
  }
  //SEGUE LINHA AJUSTE
  if ((sensor_PE == 0) && (sensor_PD == 1))
  {
    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 190);
  }
  if ((sensor_PE == 1) && (sensor_PD == 0))
  {
    analogWrite(mfE, 0);
    analogWrite(mtE, 180);
    analogWrite(mfD, 190);
    analogWrite(mtD, 0);
  }


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
    delay(2000);

    analogWrite(mfE, 0);
    analogWrite(mtE, 210);
    analogWrite(mfD, 200);
    analogWrite(mtD, 0);
    delay(900);

    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 160);
    analogWrite(mtD, 0);
    delay(1000);






  }











}

