#define eLED    22
#define dLED    30 
#define LED_G   26

int vdE = A15;
int vdD = A14;

uint8_t bD2 = 8;
uint8_t bD1 = 9;
uint8_t bU1 = 25;
uint8_t bU2 = 23;

int VE = 55;
int DV = 22;
int VP = 300;

void setup()
{
  pinMode(eLED, OUTPUT);
  pinMode(dLED, OUTPUT);

  pinMode(vdE, INPUT_PULLUP);       // IMPORTANTE: A SOMA DE LEITURAS SÓ FUNCIONA COM OS PINOS
  pinMode(vdD, INPUT_PULLUP);     // CONFIGURADOS COMO PULLUP

  pinMode(bD2, INPUT);
  pinMode(bD1, INPUT);
  pinMode(bU2, INPUT);
  pinMode(bU1, INPUT);

  Serial.begin(9600);
}

void loop()
{
  bD2 = digitalRead(8);
  bD1 = digitalRead(9);
  bU2 = digitalRead(23);
  bU1 = digitalRead(25);

  if  (bD2 == 1) DV++;
  while (digitalRead(8) == 1);
  
  if  (bD1 == 1) DV--;
  while (digitalRead(9) == 1);
  
  if  (bU1 == 1)  VE++;
  while (digitalRead(23) == 1);
  
  if  (bU2 == 1) VE--;
  while (digitalRead(25) == 1);

  if  (mediaE() >= VE)  {
    digitalWrite(eLED, HIGH);
    if  (mediaE() < VP) digitalWrite(LED_G, HIGH);
    else digitalWrite(LED_G, LOW);
  }
  if  (mediaD() >= DV)  {
    digitalWrite(dLED, HIGH);
    if  (mediaD() < VP) digitalWrite(LED_B, HIGH);
    else digitalWrite(LED_B, LOW);
  }
}

long mediaE() {
  vdE = analogRead(A15);
  long JoinE = 0;
  for(int i = 0; i<20; i++)  {
    vdE = analogRead(A15);
    JoinE += vdE;
  }
  return JoinE/4 - 200;
}
long mediaD() {
  vdD = analogRead(A14);
  long JoinD = 0;
  for(int i = 0; i<10; i++)  {
    vdD = analogRead(A14);
    JoinD += vdD;
  }
  return JoinD/4 - 100;
}
