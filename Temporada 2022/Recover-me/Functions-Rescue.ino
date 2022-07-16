void mrBean(int Delay) {
  digitalWrite(Intake, 255);
  MOVE(150, 0, 170, 0);
  delay(Delay);
}
void CAVALU(float a, bool zError, int dm) {
  analogWrite(Intake, 255);
  do  viraGyro(0, 160, 160, 0); while (angleZ <= a); angleZ = 0.01;
  do  viraGyro(200, 0, 0, 200); while (angleZ >= a); angleZ = 0.01;

  if  (zError == true)
  {
    MOVE(0, 230, 0, 230);  delay(dm);
  }
}
void idBase() {
  digitalWrite(LED_B, LOW);
  while (true)  {
    MOVE(0, 0, 0, 0); analogWrite(Intake, 0);
    int OCO = 0;
    for(uint8_t i = 0; i<15; i++)
    {
      RSPUP   = analogRead(A6);
      RSPDOWN = analogRead(A7);
      OCO += RSPDOWN;
    }
    Serial.println(RSPDOWN);
    ZERO = OCO;
    if  (ZERO >= 500) digitalWrite(LED_G, HIGH);
    else  digitalWrite(LED_G, LOW);
  };
}
void Broom(uint8_t plus) {
  analogWrite(Intake, 255);
  do  {
    sharp_A = analogRead(A1) * 0.0048828125;
    gustavoCorno = 26 * pow(sharp_A, -1);
    Serial.println(gustavoCorno);
    MOVE(150, 0, 170, 0);
  } while (gustavoCorno >= 10 + plus);
}
void riseServo(int TTL) {
  int Time = millis();
  MOVE(0, 0, 0, 0);
  serv.attach(servoPort);
  serv.write(0);
  delay(2000);
  // while (true)  {serv.read();}     // // APENAS DESCOMENTE SE FOR NECESSÁRIO
  for (int i = 0; i < 2; i++) {
    MOVE(130, 0, 130, 0);
    delay(TTL/10);
    MOVE(0, 200, 0, 200);
    delay(TTL/10);
  }
  MOVE(0, 0, 0, 0);
  delay(1800);
  serv.write(97);
  delay(TTL/2);
  serv.detach();
}
