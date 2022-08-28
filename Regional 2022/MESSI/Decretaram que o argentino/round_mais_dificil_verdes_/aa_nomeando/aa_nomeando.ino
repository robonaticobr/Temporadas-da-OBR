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

  
  }
