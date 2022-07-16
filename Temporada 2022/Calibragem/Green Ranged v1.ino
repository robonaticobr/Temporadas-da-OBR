#define eLED    22
#define dLED    30

int vdE = A15;
int vdD = A14;

uint8_t bD2 = 8;
uint8_t bD1 = 9;
uint8_t bU1 = 25;
uint8_t bU2 = 23;


int VE = 58; // 55
int DV = 20; // 22
int VP = 300;

void setup() {
  pinMode(eLED, OUTPUT);
  pinMode(dLED, OUTPUT);

  pinMode(vdE, INPUT_PULLUP);
  pinMode(vdD, INPUT_PULLUP);

  pinMode(bD2, INPUT);
  pinMode(bD1, INPUT);
  pinMode(bU2, INPUT);
  pinMode(bU1, INPUT);

  Serial.begin(9600);
}

void loop() {

  bU1 = digitalRead(23);
  bU2 = digitalRead(25);
  bD1 = digitalRead(9);
  bD2 = digitalRead(8);
  Serial.print(mediaE()); Serial.print(" | "); Serial.println(mediaD());
  if  (bU1 == 1)  {
    VE++;
    Serial.print(bU1); Serial.print(" | "); Serial.println(VE);
    delay(600);
  }
  if  (bU2 == 1)  {
    VE--;
    Serial.print(bU2); Serial.print(" | "); Serial.println(VE);
    delay(600);
  }
  if  (bD2 == 1)  {
    DV++;
    Serial.print(bD1); Serial.print(" | "); Serial.println(DV);
    delay(600);
  }
  if  (bD1 == 1)  {
    DV--;
    Serial.print(bD2); Serial.print(" | "); Serial.println(DV);
    delay(600);
  }

  if  ((mediaE() >= VE) && (mediaE() < VP))  digitalWrite(eLED, HIGH);
  if  ((mediaE() < VE) || (mediaE() >= VP))  digitalWrite(eLED, LOW);
  if  ((mediaD() >= DV) && (mediaD() < VP))  digitalWrite(dLED, HIGH);
  if  ((mediaD() < DV) || (mediaD() >= VP))  digitalWrite(dLED, LOW);
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
