void MOVE(byte m1, byte m1t, byte m2, byte m2t) {
  analogWrite(motor1, m1);
  analogWrite(motor1t, m1t);
  analogWrite(motor2, m2);
  analogWrite(motor2t, m2t);
}
void viraGyro(byte m1, byte m1t, byte m2, byte m2t) {
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gZ0);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gZ0 = Wire.read();
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gZ1);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gZ1 = Wire.read();
  gZ1 = gZ1 << 8;
  gZ_out = gZ0 + gZ1;
  Zg = gZ_out * 0.044;
  angleZc = Zg * dt;
  angleZ = angleZ + angleZc;
  Serial.println(angleZ);
  MOVE(m1, m1t, m2, m2t);
}
void moverAngYtbm(byte m1, byte m1t, byte m2, byte m2t) {
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gY0);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gY0 = Wire.read();
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gY1);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1)    gY1 = Wire.read();
  gY1 = gY1 << 8;
  gY_out = gY0 + gY1;
  Yg = gY_out * 0.07;
  angleYc = Yg * dt;
  angleY = angleY + angleYc;
  Serial.println(angleY);
  MOVE(m1, m1t, m2, m2t);
}
void segueLinha() {
  Avanc = digitalRead(52);
  Esq = digitalRead(46);
  Dir = digitalRead(48);
  if  ((Esq == 0) && (Dir == 0))  {MOVE(130, 0, 130, 0);}
  if  ((Esq == 1) && (Dir == 0))  {MOVE(0, 160, 170, 0); Corrigiu = true;}
  if  ((Esq == 0) && (Dir == 1))  {MOVE(170, 0, 0, 160); Corrigiu = true;}
}
void Redutor() {
  Avanc = digitalRead(52);
  Esq = digitalRead(46);
  Dir = digitalRead(48);
  if  ((Esq == 0) && (Dir == 0))  {MOVE(170, 0, 170, 0);}
  if  ((Esq == 1) && (Dir == 0))  {MOVE(0, 50, 210, 0);}
  if  ((Esq == 0) && (Dir == 1))  {MOVE(190, 0, 0, 40);}
}
void stopForRead(byte READ, int varTime) {
  moverAngYtbm(255, 255, 255, 255);
  if  ((mediaE() >= VP) || (mediaD() >= VP))  {
    while ((mediaE() >= VP) || (mediaD() >= VP))  {
      Serial.println(mediaE());
      if  ((mediaE() >= VP) && (mediaD() >= VP))  MOVE(0, 140, 0, 140);
      if  ((mediaE() >= VP) && (mediaD() < VP))   MOVE(0, 190, 0, 0);
      if  ((mediaE() < VP) && (mediaD() >= VP))   MOVE(0, 0, 0, 190);
    }
    return;
  }
  for (int i = READ; i > 0; i--)  {
    // if  ((Esq == 0) && (Dir == 1) && (extDir == 0))  MOVE(100, 0, 0, 100);
    // if  ((Esq == 1) && (Dir == 0) && (extEsq == 0))  MOVE(0, 100, 100, 0);
    Serial.print(mediaE()); Serial.print(" | "); Serial.println(mediaD());
    delay(varTime);
  }
  allow = true;
  // while (true)  {
  //   Serial.print(mediaE()); Serial.print(" | "); Serial.println(mediaD());
  //   delay(10);
  // };
}
void isIt90()  {
  Corrigiu = false;
  allow = true;
  MOVE(130, 0, 110, 0);
  delay(300);
  eAnt = millis();
  while (millis() - eAnt <= 230)  {segueLinha();}
  Avanc = digitalRead(52);
  if  ((Avanc == 1) || (Corrigiu == true))  allow = false;
  if  ((Avanc == 0) && (Corrigiu == false)) allow = true;
}
void deg90Dobra(float to, bool comp)   {
  do  {
    vdE = analogRead(A15);
    vdD = analogRead(A14);
    MOVE(0, 160, 0, 160);
  } while ((vdE <= 300) && (vdD <= 300));
  do {viraGyro(0, 160, 180, 0);} while   (angleZ <= to); angleZ = 0.01;
  do {viraGyro(200, 0, 0, 200);}  while   (angleZ >= to); angleZ = 0.01;

  if  (comp == true)  {
    if  (angleZ <= to)
      do {Avanc = digitalRead(52); MOVE(0, 160, 180, 0);} while (Avanc == 0);
    if  (angleZ >= to)
      do {Avanc = digitalRead(52); MOVE(200, 0, 0, 200);} while (Avanc == 0);
  }
  angleY = 0.01;
  angleZ = 0.01;
  extEsq = digitalRead(42);
  extDir = digitalRead(50);
  while ((extEsq == 0) && (extDir == 0))  {
    extEsq = digitalRead(42);
    extDir = digitalRead(50);
    MOVE(0, 120, 0, 120);
  }
  serv.attach(36);
  serv.write(97);
  MOVE(100, 0, 100, 0); delay(350);
  serv.detach();
}
void cDesvio (float to) {
  angleZ = 0.01;
  do {viraGyro(0, 160, 170, 0);} while   (angleZ <= to); angleZ = 0.01;
  do {viraGyro(200, 0, 0, 170);}  while   (angleZ >= to); angleZ = 0.01;
  angleY = 0.01;
  angleZ = 0.01;
}
void deg180Dobra(float mError, bool comp)  {
  shineLED(LED_B, eLED, dLED, 1);
  do  {viraGyro(0, 150, 120, 0);} while   (angleZ <= 170.00 - mError);
  if  (comp == true)  {
    do  {MOVE(0, 150, 120, 0);  Avanc = digitalRead(52);} while   (Avanc == 0);
  }
  do  {MOVE(0, 100, 0, 100); vdE = analogRead(A15); vdD = analogRead(A14);} while ((vdE <= VP) && (vdD <= VP));
  shineLED(LED_B, eLED, dLED, 0);
  angleY = 0.01;
  angleZ = 0.01;
}
void whiteAhead()  {
  extEsq = digitalRead(42);
  extDir = digitalRead(50);  
  Esq = digitalRead(46);
  Dir = digitalRead(48);
  while ((extEsq == 1) && (Esq == 1))  {
    for (int i = 6; i > 0; i--) {
      extEsq = digitalRead(42);
      Esq = digitalRead(46);
    }
    MOVE(130, 0, 130, 0);
  }
  while ((extDir == 1) && (Dir == 1))  {
    for (int i = 6; i > 0; i--) {
      extDir = digitalRead(50);
      Dir = digitalRead(48);
    }
    MOVE(130, 0, 130, 0);
  }
  angleY = 0.01; angleZ = 0.01;
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
void shineLED(byte l1, byte l2, byte l3, byte mult)  {
  digitalWrite(l1, mult);
  digitalWrite(l2, mult);
  digitalWrite(l3, mult);
}
