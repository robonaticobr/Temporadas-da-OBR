//PROGRMAÇÃO_SAMURAI
//DECLARANDO MOTORES
byte mfE = 5;
byte mtE = 4;
byte mfD = 7;
byte mtD = 6;
byte LED = 26;




//VARIAVEIS GLOBAIS
byte curvaD = 0;
byte curvaE = 0;




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
  pinMode(26, OUTPUT); //LED

  

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
    analogWrite(mfD, 120);
    analogWrite(mtD, 0);
  }




  //SEGUE LINHA AJUSTE
  if ((sensor_PE == 0) && (sensor_PD == 1))

  {
    analogWrite(mfE, 140);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 120);

  }

  if ((sensor_PE == 1) && (sensor_PD == 0))
  {
    analogWrite(mfE, 0);
    analogWrite(mtE, 120);
    analogWrite(mfD, 140);
    analogWrite(mtD, 0);
  }

//verde

if ((sensor_VD <= 800) && (sensor_VD >=850))
{
  analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(5000);

digitalWrite(26, HIGH);
}

  //ENCRUZILHADA
    sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(46);
if ((sensor_PE == 1) && (sensor_PD == 1) && (sensor_A == 1))
{

    analogWrite(mfE, 120);
    analogWrite(mtE, 0);
    analogWrite(mfD, 120);
    analogWrite(mtD, 0);
    delay(250);


}

sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);



  
  // 90° DIREITA

  if ((sensor_EE == 0) && (sensor_PE == 0) && (sensor_C == 1) && (sensor_PD == 1) && (sensor_ED == 1))
  {
     
    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);

if ((sensor_VD <= 800) && (sensor_VD >=900))
{

digitalWrite(26, HIGH);
  
  analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);
}

analogWrite(mfE, 140);
    analogWrite(mtE, 0);
    analogWrite(mfD, 140);
    analogWrite(mtD, 0);
    delay(300);

    analogWrite(mfE, 140);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 140);
    delay(500);

Serial.println(sensor_C);
   sensor_PE = digitalRead(44);
    while (sensor_PE == 0)
    {
      curvaD = 0;

sensor_PE = digitalRead(44);

      sensor_PE = digitalRead(44);
      analogWrite(mfE, 140);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 150);

    }

    {
   
 analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

     analogWrite(mfE, 0);
    analogWrite(mtE, 140);
    analogWrite(mfD, 0);
    analogWrite(mtD, 140);
    delay(300);
    
    
}

    analogWrite(mfE, 150);
    analogWrite(mtE, 0);
    analogWrite(mfD, 150);
    analogWrite(mtD, 0);
    delay(400);
    curvaD = 1;
  }
  
sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);
  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(46);

  if ((sensor_EE == 0) && (sensor_A == 0) && (sensor_PE == 0) && (sensor_C == 0) && (sensor_PD == 0) && (curvaD == 1))
  {
    Serial.println(sensor_C);
   sensor_PE = digitalRead(44);
    while (sensor_PE == 0)
    {
      curvaD = 0;

sensor_PE = digitalRead(44);

      sensor_PE = digitalRead(44);
      analogWrite(mfE, 140);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 150);
    }

analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);
    
    analogWrite(mfE, 0);
    analogWrite(mtE, 130);
    analogWrite(mfD, 0);
    analogWrite(mtD, 130);
    delay(300);


    return;
  }

  
  // 90° ESQUERDA

if ((sensor_ED == 0) && (sensor_PD == 0) && (sensor_C == 1) && (sensor_PE == 1) && (sensor_EE == 1))
  {
     
    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);

if ((sensor_VD <= 800) && (sensor_VD >=900))
{

  digitalWrite(26, HIGH);

  
  analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);
}

analogWrite(mfE, 140);
    analogWrite(mtE, 0);
    analogWrite(mfD, 140);
    analogWrite(mtD, 0);
    delay(300);

    analogWrite(mfE, 0);
    analogWrite(mtE, 140);
    analogWrite(mfD, 140);
    analogWrite(mtD, 0);
    delay(500);

Serial.println(sensor_C);
   sensor_PD = digitalRead(46);
    while (sensor_PD == 0)
    {
      curvaE = 0;

sensor_PD = digitalRead(46);

      sensor_PD = digitalRead(46);
      analogWrite(mfE, 0);
      analogWrite(mtE, 180);
      analogWrite(mfD, 120);
      analogWrite(mtD, 0);

    }

    {
   
 analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

     analogWrite(mfE, 0);
    analogWrite(mtE, 130);
    analogWrite(mfD, 0);
    analogWrite(mtD, 140);
    delay(300);
    
    
}

    analogWrite(mfE, 150);
    analogWrite(mtE, 0);
    analogWrite(mfD, 150);
    analogWrite(mtD, 0);
    delay(400);
    curvaD = 1;
  }
  
sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);
  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(46);

  if ((sensor_EE == 0) && (sensor_A == 0) && (sensor_PE == 0) && (sensor_C == 0) && (sensor_PD == 0) && (curvaD == 1))
  {
    Serial.println(sensor_C);
   sensor_PD = digitalRead(46);
    while (sensor_PD == 0)
    {
      curvaE = 0;

sensor_PD = digitalRead(46);

      sensor_PD = digitalRead(46);
      analogWrite(mfE, 0);
      analogWrite(mtE, 150);
      analogWrite(mfD, 140);
      analogWrite(mtD, 0);
    }

analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);
    
    analogWrite(mfE, 0);
    analogWrite(mtE, 130);
    analogWrite(mfD, 0);
    analogWrite(mtD, 130);
    delay(300);


    return;
  }


// T PARA DIREITA

pinMode(sensor_EE, INPUT); //ExtremoEsquerdo
  pinMode(sensor_C, INPUT); //Central
  pinMode(sensor_A, INPUT); //Avançado
  pinMode(sensor_ED, INPUT); //ExtremoDireito
  pinMode(sensor_PE, INPUT); //PontaEsquerda
  pinMode(sensor_PD, INPUT); //PontaDireita
  
if ((sensor_EE == 0) && (sensor_C == 1) && (sensor_PD == 1) && (sensor_A == 1))

{
     analogWrite(mfE, 140);
    analogWrite(mtE, 0);
    analogWrite(mfD, 140);
    analogWrite(mtD, 0);
    delay(250);
}

return;

  }
