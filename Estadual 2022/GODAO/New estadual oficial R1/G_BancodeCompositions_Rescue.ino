// Aplicação da sirene de LED
// ======================================================================== mrBean com Sirene
void mrBean(int Delay)
{
  eAnt = millis();
  while (millis() - eAnt < Delay) {
    MOVE(160, 0, 190, 0);
    Sirens(330);
  }
}
void mrBeanInvertido(int Delay)
{
  eAnt = millis();
  while (millis() - eAnt < Delay) {
    MOVE(0, 160, 0, 210);
    Sirens(330);
  }
}
// ======================================================================== / mrBean com Sirene



// ======================================================================== Varredura e média de sensor frontal
void Broom(uint8_t metric)
{
  do  {
    Sirens(330);
    MOVE(160, 0, 190, 0);
  } while (sharpAverage() > metric);
}

unsigned int sharpAverage()  {
  unsigned int uuuuuui = 0;
  unsigned int Division = 0;
  for (int i = 0; i < 100; i++)  {
    sharp_A = analogRead(A1);
    uuuuuui += sharp_A;
  }
  Division = uuuuuui/100;
  return map(Division, 633, 154, 5, 30);
}
// ======================================================================== / Varredura e média de sensor frontal




// ======================================================================== CAVALU com sirene
void CAVALU(float a, bool zError, int dm)
{
  analogWrite(Intake, 255);
  angleZ = 0.01;
  do  {
    viraGyro(0, 140, 200, 0);
    Sirens(330);
  } while (angleZ <= a); angleZ = 0.01;

  do  {
    viraGyro(130, 0, 0, 220);
    Sirens(330);
  } while (angleZ >= a); angleZ = 0.01;

  if  (zError == true)
  {
    eAnt = millis();
    while (millis() - eAnt < dm)
    {
      Sirens(330);
      MOVE(0, 180, 0, 220);
    }
  }
}
// ======================================================================== / CAVALU com sirene




// ======================================================================== Porteira com Sirene
void riseServo(int TTL)
{
  int Time = millis();
  MOVE(0, 0, 0, 0);
  serv.attach(servoPort);
  serv.write(0);
  eAnt = millis();
  while (millis() - eAnt < 2000)  Sirens(330);
  for (int i = 0; i < 2; i++) {
    MOVE(140, 0, 170, 0);
    eAnt = millis();    
    while (millis() - eAnt < TTL/10) Sirens(330);
    MOVE(0, 200, 0, 220);
    eAnt = millis();
    while (millis() - eAnt < TTL/7) Sirens(330);
  }
  MOVE(0, 0, 0, 0);
  eAnt = millis();
  while (millis() - eAnt < 1800) Sirens(330);
  serv.write(97);
  eAnt = millis();
  while (millis() - eAnt < TTL/2) Sirens(330);
  serv.detach();
}
// ======================================================================== / Porteira com Sirene




// ======================================================================== Identificação estável de base
unsigned int idBase() {
  digitalWrite(LED_B, LOW);
  MOVE(0, 0, 0, 0);
  delay(1000);
  int OCO = 0;
  for(uint8_t i = 0; i<15; i++)
  {
    RSPUP   = analogRead(A6);
    RSPDOWN = analogRead(A7);
    OCO += RSPDOWN;
  }
  Serial.println(OCO);
  ZERO = OCO;
  if  (RSPDOWN >= 100) digitalWrite(LED_G, HIGH);
  else digitalWrite(LED_G, LOW);
  return RSPDOWN;
}
// ======================================================================== / Identificação estável de base




// ======================================================================== Função de controles de Sirenes
void Sirens(int Rhythm) {
  if  (millis() - SirensPJ >= Rhythm) {
    SirensPJ = millis();
    digitalWrite(eLED, digitalRead(dLED));
    digitalWrite(dLED, !digitalRead(eLED));
    digitalWrite(LED_B, digitalRead(LED_R));
    digitalWrite(LED_R, !digitalRead(LED_B));
  }
}
// ======================================================================== / Função de controles de Sirenes

