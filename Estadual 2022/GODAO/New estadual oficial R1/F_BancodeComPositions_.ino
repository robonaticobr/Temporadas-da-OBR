void rightDetour()  {
  do  MOVE(0, 120, 0, 190); while (sharpAverage() < 13);
  MOVE(255, 255, 255, 255);
  digitalWrite(eLED, LOW);  digitalWrite(dLED, LOW);
  shineLED(LED_R, 80, 80, 1);
  delay(300);
  //  Avanc = digitalRead(52);
  Esq = digitalRead(46);
  Dir = digitalRead(48);
  //  MOVE(110, 0, 170, 0); delay(150);
  do  {
    sharp_A = analogRead(A1);
    MOVE(200, 0, 0, 200);
  } while (sharp_A >= 10.00);
  do  viraGyro(190, 0, 0, 210); while (angleZ >= -40.00);
  do  {
    Distance = map(sharpLAverage(), 470, 96, 5, 23);
    Serial.println(Distance);
    MOVE(110, 0, 140, 0);
  } while (Distance >= 19);
  extEsq = 0; Esq = 0; Middle = 0;
  angleZ = 0.01;
  while (true)  {
    if  (angleZ >= 99.00)
    {
      MOVE(0, 110, 0, 190); delay(400);
      bool RMarch = false;
      MOVE(255, 255, 255, 255); delay(300);
      for  (int i = 0; i < 10; i++) {
        Esq = digitalRead(39);
        Dir = digitalRead(43);
        extEsq = digitalRead(33); extDir = digitalRead(42);
        Middle = digitalRead(66);
      }
      angleZ = 0.01;
      eAnt = millis();
      while (1) {
        Esq = digitalRead(39);
        Dir = digitalRead(43);
        extEsq = digitalRead(33); extDir = digitalRead(42);
        Middle = digitalRead(66);
        if  ((Esq == 0) && (Dir == 0))  MOVE(100, 0, 160, 0);
        if  (((extEsq == 1) && (Esq == 1) && (Middle == 1)) || ((Middle == 1) && (Dir == 1) && (extDir == 1)))  {
          if  (RMarch == false) {
            RMarch = true;
            MOVE(0, 110, 0, 190);
            delay(550);
            eAnt = millis();
          }
          else  {
            stopForRead(4, 70);
            if  ((extEsq == 1) || (extDir == 1)) {
              //          do  viraGyro(160, 0, 0, 200); while (angleZ >= -10.00); angleZ = 0.01;
              eAnt = millis();
              MOVE(110, 0, 170, 0); delay(400);
              eAnt = millis();
              int Front = 0;
              Corrigiu = false;
              eAnt = millis();
              while (millis() - eAnt < 300) {
                Esq = digitalRead(39);
                Dir = digitalRead(43);
                avEsq = digitalRead(35);
                avDir = digitalRead(29);
                extEsq = digitalRead(33); extDir = digitalRead(42);
                if  ((Esq == 0) && (Dir == 0)) MOVE(0, 0, 0, 0);
                if  ((Esq == 1) && (Dir == 0)) {
                  MOVE(0, 220, 150, 0);
                  Corrigiu = true;
                }
                if  ((Esq == 0) && (Dir == 1)) {
                  MOVE(160, 0, 0, 220);
                  Corrigiu = true;
                }
                if  ((extEsq == 1) && (Esq == 1) && (Middle == 0)) {MOVE(0, 220, 150, 0); Corrigiu = true;}
                if  ((extDir == 1) && (Dir == 1) && (Middle == 0)) {MOVE(160, 0, 0, 220); Corrigiu = true;}
                if  ((extEsq == 1) && (Esq == 0)) {MOVE(0, 220, 150, 0); Corrigiu = true;}
                if  ((extDir == 1) && (Dir == 0)) {MOVE(160, 0, 0, 220); Corrigiu = true;}
              }
              do  {
                Esq = digitalRead(39);
                extEsq == digitalRead(33);
                viraGyro(160, 0, 0, 200);} 
              while ((extEsq == 0) && (Esq == 0) && (angleZ >= -20.00)); angleZ = 0.01;
              MOVE(120, 0, 180, 0); delay(200);
              do  {
                Esq = digitalRead(39);
                extEsq == digitalRead(33);
                viraGyro(160, 0, 0, 230);}
              while ((extEsq == 0) && (Esq == 0) && (angleZ >= -80.00)); angleZ = 0.01;
              return;
            }
          }
        }
        if  ((extEsq == 0) && (Esq == 0) && (Middle == 0) && (Dir == 0) && (extDir == 0) && (millis() - eAnt > 900)) {
          do  viraGyro(160, 0, 0, 200); while (angleZ >= -30.00); angleZ = 0.01;
          do  viraGyro(160, 0, 0, 230); while (angleZ >= -80.00); angleZ = 0.01;
          MOVE(110, 0, 170, 0); delay(500);
          return;
        }
        if  ((Esq == 1) && (Dir == 0) && (angleY >= -10.00))  {
          MOVE(0, 180, 160, 0);
        }
        if  ((Dir == 1) && (Esq == 0) && (angleY >= -10.00))  {
          MOVE(160, 0, 0, 215);
        }
        if  ((extEsq == 1) && (Esq == 1) && (Middle == 0)) MOVE(0, 220, 150, 0);
        if  ((extDir == 1) && (Dir == 1) && (Middle == 0)) MOVE(160, 0, 0, 220);
        //        if  ((extEsq == 1) && (Esq == 0)) MOVE(0, 220, 150, 0);
        //        if  ((extDir == 1) && (Dir == 0)) MOVE(160, 0, 0, 220);
      }
    }
    Distance = map(sharpLAverage(), 470, 96, 5, 23);
    if  (angleZ <= 80.00) {
      if  (Distance <= 19)  viraGyro(0, 70, 200, 0);
      if  (Distance > 19)  viraGyro(80, 0, 170, 0);
    }
    else  {
      if  (Distance <= 19)  viraGyro(0, 100, 200, 0);
      if  (Distance > 19)  viraGyro(50, 0, 170, 0);
    }
  }
}

//void rightDetour() {
//  do  {
//    if  (BOLA == false) {
//      Acc = 0;
//      for (byte i = 0; i < 5; i++) {
//        sharp_A = analogRead(A1);
//        Acc += sharp_A;
//      }
//    }
//    MOVE(0, 130, 0, 130);
//  } while (Acc >= 2600);
//  MOVE(255, 255, 255, 255);
//  digitalWrite(eLED, LOW);  digitalWrite(dLED, LOW);
//  shineLED(LED_R, 80, 80, 1);
//  delay(300);
//  Avanc = digitalRead(52);
//  Esq = digitalRead(46);
//  Dir = digitalRead(48);
//  do  {
//    sharp_A = analogRead(A1);
//    MOVE(200, 0, 0, 200);
//  } while (sharp_A >= 80.00);
//  do  viraGyro(200, 0, 0, 200); while (angleZ >= -78.00);
//  do  {
//    extEsq = digitalRead(42);
//    extDir = digitalRead(50);
//    if  (extEsq == 0)  MOVE(0, 130, 0, 130);
////    if  ((extEsq == 1) && (extDir == 0))  MOVE(60, 0, 0, 130);
////    if  ((extEsq == 0) && (extDir == 1))  MOVE(0, 130, 60, 0);
//  } while (extEsq == 0);
//  Middle = digitalRead(44);
//  extEsq = digitalRead(42);
//  do  {
//    Middle = digitalRead(44);
//    extEsq = digitalRead(42);
//    if  ((Middle == 0) && (extEsq == 0)) MOVE(120, 0, 120, 0);
//    if  ((Middle == 1) && (extEsq == 0)) MOVE(140, 0, 0, 0);
//    if  ((Middle == 0) && (extEsq == 1)) MOVE(0, 0, 140, 0);
//  } while ((Middle == 0) && (extEsq == 0));
//  MOVE(255, 255, 255, 255); delay(300);
//  angleZ = 0.01;
//
//  for (int i = 0; i < 10; i++)  sharp_L = analogRead(A3);
//  shineLED(LED_R, 80, 80, 0);
//
//  while (vdE <= VP) {
//    vdE = analogRead(A15);
//    digitalWrite(LED_G, HIGH);
//    MOVE(170, 0, 170, 0);
//  }
//  digitalWrite(LED_G, LOW);
//  MOVE(170, 0, 170, 0); delay(1100);
//  MOVE(255, 255, 255, 255); delay(300);
//  MOVE(0, 0, 0, 0); while (true);
//
//  cDesvio(116.00);
//  MOVE(255, 255, 255, 255); delay(300);
//  digitalWrite(eLED, HIGH);
//  MOVE(180, 0, 180, 0); delay(700);
//  digitalWrite(eLED, LOW);
//  MOVE(255, 255, 255, 255); delay(300);
//
//  do  viraGyro(0, 160, 170, 0); while (angleZ <= 110.00);
//  MOVE(255, 255, 255, 255);
//  angleZ = 0.01;
//  do  {
//    sharp_L = analogRead(A3);
//    extEsq = digitalRead(42);
//    if  (extEsq == 1) digitalWrite(eLED, HIGH);
//    else digitalWrite(eLED, LOW);
//    MOVE(150, 0, 150, 0);
//  } while (sharp_L <= 200.00);
//  delay(160);
////  MOVE(255, 255, 255, 255); delay(300);
//  while (extEsq == 0) {
//    extEsq = digitalRead(42);
//    MOVE(140, 0, 150, 0);
//  }
////  do  viraGyro(200, 0, 0, 200); while (angleZ >= -90.00);
//  angleZ = 0.01;
//}

//void leftDetour() {
//  do  {
//    if  (BOLA == false) {
//      Acc = 0;
//      for (byte i = 0; i < 5; i++) {
//        sharp_A = analogRead(A1);
//        Acc += sharp_A;
//      }
//    }
//    MOVE(0, 130, 0, 130);
//  } while (Acc >= 2600);
//  MOVE(255, 255, 255, 255);
//  digitalWrite(eLED, LOW);  digitalWrite(dLED, LOW);
//  shineLED(LED_R, 80, 80, 1);
//  delay(300);
//  Avanc = digitalRead(52);
//  Esq = digitalRead(46);
//  Dir = digitalRead(48);
//  do  {
//    sharp_A = analogRead(A1);
//    MOVE(0, 160, 160, 0);
//  } while (sharp_A >= 80.00);
//  angleZ = 0.01;
//  do  viraGyro(0, 160, 160, 0); while (angleZ <= 85.00);
//  do  {
//    Avanc = digitalRead(52);
//    MOVE(0, 130, 0, 130);
//  } while (Avanc == 0);
//
//  MOVE(0, 150, 0, 150); delay(300);
//  Middle = digitalRead(44);
//  extEsq = digitalRead(42);
//  do  {
//    Middle = digitalRead(44);
//    extEsq = digitalRead(42);
//    if  ((Middle == 0) && (extEsq == 0)) MOVE(120, 0, 120, 0);
//    if  ((Middle == 1) && (extEsq == 0)) MOVE(140, 0, 0, 0);
//    if  ((Middle == 0) && (extEsq == 1)) MOVE(0, 0, 140, 0);
//  } while ((Middle == 0) && (extEsq == 0));
//  MOVE(255, 255, 255, 255); delay(300);
//  angleZ = 0.01;
//
//  for (int i = 0; i < 10; i++)  sharp_L = analogRead(A3);
//  shineLED(LED_R, 80, 80, 0);
//  MOVE(170, 0, 170, 0); delay(1100);
//  MOVE (255, 255, 255, 255); delay(300);
//  cDesvio(-90.00);
//  MOVE (255, 255, 255, 255); delay(300);
//  do  {
//    RSPDOWN = analogRead(A7);
//    MOVE(170, 0, 170, 0);
//  } while (RSPDOWN <= 200.00);
//  digitalWrite(dLED, HIGH);
//  MOVE(190, 0, 190, 0); delay(730);
//  digitalWrite(dLED, LOW);
//  MOVE(255, 255, 255, 255); delay(300);
//  cDesvio(110.00);
//  MOVE(255, 255, 255, 255); delay(300);
//  do  {
//    sharp_L = analogRead(A3);
//    extDir = digitalRead(50);
//    if  (extDir == 1) digitalWrite(dLED, HIGH);
//    else digitalWrite(dLED, LOW);
//    MOVE(0, 160, 0, 160);
//  } while (sharp_L <= 200.00);
//  do  {
//    vdE = analogRead(A10);
//    MOVE(0, 150, 0, 150);
//  } while (vdE <= VP);
//  do  {
//    extEsq = digitalRead(50);
//    MOVE(0, 150, 0, 150);
//  } while (extEsq == 0);
//  MOVE(150, 0, 150, 0); delay(160);
//  MOVE(255, 255, 255, 255); delay(300);
//  angleZ = 0.01;
//  do  viraGyro(200, 0, 0, 200); while (angleZ >= -90.00);
//  while ((angleZ >= -110.00) && (Avanc == 0)) {
//    Avanc = digitalRead(52);
//    viraGyro(200, 0, 0, 200);
//  }
//}

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

//void segueLinha()   {
//  Avanc = digitalRead(52);
//  Esq = digitalRead(46);
//  Dir = digitalRead(48);
//
//  if  ((Esq == 0) && (Dir == 0))  {
//    MOVE(120, 0, 120, 0);
//  }
//  if  ((Esq == 1) && (Dir == 0))  {
//    MOVE(0, 140, 140, 0);
//    Corrigiu = true;
//  }
//  if  ((Dir == 1) && (Esq == 0))  {
//    MOVE(170, 0, 0, 180);
//    Corrigiu = true;
//  }
//}

void stopForRead(byte READ, int varTime)  {
  moverAngYtbm(255, 255, 255, 255);
  for (int i = READ; i > 0; i--)  {
    delay(varTime);
    if  (avEsq == 0)     avEsq    = digitalRead(35);
    if  (avMiddle == 0)  avMiddle = digitalRead(29);
    if  (avDir == 0)     avDir    = digitalRead(50);
    Esq = digitalRead(39);
    Dir = digitalRead(43);
    extEsq = digitalRead(33);
    extDir = digitalRead(42);
    svE(); svD();
    Serial.print(extEsq); Serial.print(" | "); Serial.println(extDir);
  }
  allow = true;
}





void deg90Dobra(float to, bool comp)   {
  angleZ = 0.01;
  if  (comp == true)  {
    MOVE(140, 0, 180, 0); delay(400);
  }
  do {
    viraGyro(0, 160, 170, 0);
  } while   (angleZ <= to); angleZ = 0.01;
  do {
    viraGyro(140, 0, 0, 205);
  }  while   (angleZ >= to); angleZ = 0.01;

  if  (comp == true)  {
    if  (angleZ <= to)
      do {
        Dir = digitalRead(43);
        Middle = digitalRead(66);
        MOVE(0, 160, 170, 0);
      } while ((Dir == 0) &&  (Middle == 0) && (angleZ <= 15.00));
    if  (angleZ >= to)  {
      do {
        Esq = digitalRead(39);
        Middle = digitalRead(66);
        viraGyro(40, 0, 0, 210);
      } while ((Middle == 0) && (angleZ >= -35.00));
    }
  }
  angleZ = 0.01;
  angleY = 0.01;
}







void deg180Dobra(float mError, bool comp)  {
  shineLED(LED_B, eLED, dLED, 1);
  MOVE(140, 0, 180, 0); delay(400);
  angleZ = 0.01;
  do    {
    viraGyro(0, 190, 170, 0);
  } while   (angleZ <= 170.00 - mError);
  if  (comp == true)  {
    do    {
      MOVE(0, 130, 200, 0);
      Middle = digitalRead(66);
    } while   (Middle == 0);
  }
  extEsq = digitalRead(33);
  extDir = digitalRead(42);
  shineLED(LED_B, eLED, dLED, 0);
  angleY = 0.01;
  angleZ = 0.01;
}




void whiteAhead()  {
  extEsq = digitalRead(33);
  extDir = digitalRead(42);
  Esq = digitalRead(39);
  Dir = digitalRead(43);
  eAnt = millis();
  while ((extEsq == 1) && (Esq == 1) && (millis() - eAnt < 200))  {
    if  (millis() - eAnt >= 200)  {
      eAnt = millis();
      digitalWrite(eLED, !digitalRead(eLED));
      digitalWrite(dLED, !digitalRead(dLED));
    }
    for (int i = 6; i > 0; i--) {
      extEsq = digitalRead(33);
      Esq = digitalRead(39);
    }
    MOVE(110, 0, 150, 0);
  }
  eAnt = millis();
  while ((extDir == 1) && (Dir == 1) && (millis() - eAnt < 200))  {
    if  (millis() - eAnt >= 200)  {
      eAnt = millis();
      digitalWrite(eLED, !digitalRead(eLED));
      digitalWrite(dLED, !digitalRead(dLED));
    }
    for (int i = 6; i > 0; i--) {
      extDir = digitalRead(42);
      Dir = digitalRead(43);
    }
    MOVE(110, 0, 150, 0);
  }
  angleY = 0.01; angleZ = 0.01;
}
//
float sharpLAverage() {
  float Consequence = 0;
  for (uint8_t i = 0; i < 100; i++)  {
    sharp_L = analogRead(A3);
    Consequence += sharp_L;
  }
  return Consequence / 100;
}

long svE() {
  vdE.getRawData(&lr, &lg, &lb, &clear);
  return lr + lg + lb;
}
long svD() {
  vdD.getRawData(&rr, &rg, &rb, &clear);
  return rr + rg + rb;
}

void shineLED(byte l1, byte l2, byte l3, byte mult)  {
  digitalWrite(l1, mult);
  digitalWrite(l2, mult);
  digitalWrite(l3, mult);
}

