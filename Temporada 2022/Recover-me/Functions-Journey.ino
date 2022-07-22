void doDesvio() {
  do  {
    if  (BOLA == false) {
      Acc = 0;
      for (byte i = 0; i < 5; i++) {
        sharp_A = analogRead(A1);
        Acc += sharp_A;
      }
    }
    MOVE(0, 130, 0, 130);
  } while (Acc >= 2600);
  MOVE(255, 255, 255, 255);
  digitalWrite(eLED, LOW);  digitalWrite(dLED, LOW);
  shineLED(LED_R, 80, 80, 1);
  delay(300);
  Avanc = digitalRead(52);
  Esq = digitalRead(46);
  Dir = digitalRead(48);
  
  do  {
    sharp_A = analogRead(A1);
    MOVE(200, 0, 0, 200);
  } while (sharp_A >= 80.00);
  do  viraGyro(200, 0, 0, 200); while (angleZ >= -78.00);
  do  {
    Avanc = digitalRead(52);
    MOVE(0, 130, 0, 130);
  } while (Avanc == 0);
  
  MOVE(0, 150, 0, 150); delay(300);
  Middle = digitalRead(44);
  extEsq = digitalRead(42);
  do  {
    Middle = digitalRead(44);
    extEsq = digitalRead(42);
    if  ((Middle == 0) && (extEsq == 0)) MOVE(120, 0, 120, 0);
    if  ((Middle == 1) && (extEsq == 0)) MOVE(140, 0, 0, 0);
    if  ((Middle == 0) && (extEsq == 1)) MOVE(0, 0, 140, 0);
  } while ((Middle == 0) && (extEsq == 0));
  MOVE(255, 255, 255, 255); delay(300);
  angleZ = 0.01;

  for (int i = 0; i < 10; i++)  sharp_L = analogRead(A3);
  shineLED(LED_R, 80, 80, 0);
  
  MOVE(170, 0, 170, 0); delay(800);
  MOVE(255, 255, 255, 255); delay(300);
  
  cDesvio(105.00);
  MOVE(255, 255, 255, 255); delay(300);
  
  while (sharp_L <= 200.00)  {
    sharp_L = analogRead(A3);
    MOVE(180, 0, 180, 0);
  }
  while (sharp_L >= 100.00)  {
    digitalWrite(eLED, HIGH);
    sharp_L = analogRead(A3);
    MOVE(180, 0, 180, 0);
  }
  digitalWrite(eLED, LOW);
  MOVE(120, 0, 120, 0); delay(150);
  MOVE(255, 255, 255, 255); delay(300);
  cDesvio(117.00);
  angleZ = 0.01;
  
  while ((Avanc == 0) || (angleZ >= -90.00))  {
    Avanc = digitalRead(52);
    Dir = digitalRead(48);
    if  (Dir == 0)  viraGyro(120, 0, 120, 0);
    else {do viraGyro(200, 0, 0, 200); while ((angleZ >= -90.00) || (Avanc == 0));}
  }
  angleZ = 0.01;
  MOVE(255, 255, 255, 255); delay(600);
  
//  do {
//    extEsq = digitalRead(42);
//    extDir = digitalRead(50);
//    MOVE(0, 150, 0, 150);
//  } while ((extEsq == 1) || (extDir == 1));                   // MODO 1
  angleZ = 0.01;

  MOVE(255, 255, 255, 255); delay(600);

  MOVE(130, 0, 130, 0); delay(500);

  do  {
    vdE = analogRead(A15);
    vdD = analogRead(A14);

    MOVE(0, 140, 0, 140);
  } while ((vdE <= VP) && (vdD <= VP));

  deg90Dobra(-80.00, true);
  
  BOLA = true;
  return;
}

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

void segueLinha()   {
  Avanc = digitalRead(52);
  Esq = digitalRead(46);
  Dir = digitalRead(48);

  if  ((Esq == 0) && (Dir == 0))  {MOVE(130, 0, 130, 0);}
  if  ((Esq == 1) && (Dir == 0))  {MOVE(0, 160, 170, 0); Corrigiu = true;}
  if  ((Esq == 0) && (Dir == 1))  {MOVE(170, 0, 0, 160); Corrigiu = true;}
}

void stopForRead(byte READ, int varTime)  {
  moverAngYtbm(255, 255, 255, 255);
  if  ((mediaE() >= VP) || (mediaD() >= VP))  {
    while ((mediaE() >= VP) || (mediaD() >= VP))  {
      if  ((mediaE() >= VP) && (mediaD() >= VP))  moverAngYtbm(0, 140, 0, 140);
      if  ((mediaE() >= VP) && (mediaD() < VP))   moverAngYtbm(0, 190, 0, 0);
      if  ((mediaE() < VP) && (mediaD() >= VP))   moverAngYtbm(0, 0, 0, 190);
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
  Avanc = 0;
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
    extEsq = digitalRead(42);
    extDir = digitalRead(50);
    MOVE(0, 160, 0, 160);
  } while ((extEsq == 0) && (extDir == 0));
  angleZ = 0.01;
  do {viraGyro(0, 160, 180, 0);} while   (angleZ <= to); angleZ = 0.01;
  do {viraGyro(200, 0, 0, 200);}  while   (angleZ >= to); angleZ = 0.01;

  if  (comp == true)  {
    if  (angleZ <= to)
      do {Dir = digitalRead(48); Avanc = digitalRead(52); MOVE(0, 140, 190, 0);} while ((Avanc == 0) && (Dir == 0));
    if  (angleZ >= to)
      do {Esq = digitalRead(46); Avanc = digitalRead(52); MOVE(200, 0, 0, 200);} while ((Avanc == 0) && (Esq == 0));
  }
  angleY = 0.01;
  angleZ = 0.01;
  extEsq = digitalRead(42);
  extDir = digitalRead(50);
  while ((extEsq == 0) && (extDir == 0))  {
    extEsq = digitalRead(42);
    extDir = digitalRead(50);
    MOVE(0, 140, 0, 140);
  }
  while ((extEsq == 1) || (extDir == 1)) {
    extEsq = digitalRead(42);
    extDir = digitalRead(50);
    MOVE(120, 0, 120, 0);
  }
  MOVE(70, 0, 70, 0);
  eAnt = millis();
  serv.attach(36);
  serv.write(97);
  delay(300);
  serv.detach();
//  while (millis() - eAnt < 350) {
//    Esq = digitalRead(46);
//    Dir = digitalRead(48);
//    if ((Esq == 0) && (Dir == 0)) MOVE(130, 0, 150, 0);
//    if ((Esq == 1) && (Dir == 0)) MOVE(0, 150, 160, 0);
//    if ((Esq == 0) && (Dir == 1)) MOVE(160, 0, 0, 190);
//  }
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
  do    {viraGyro(0, 150, 120, 0);} while   (angleZ <= 170.00 - mError);
  if  (comp == true)  {
    do    {MOVE(0, 150, 120, 0);  Avanc = digitalRead(52);} while   (Avanc == 0);
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
