void loop() {
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);

  Esq = digitalRead(46);
  Dir = digitalRead(48);
  extEsq = digitalRead(42); extDir = digitalRead(50);
  Avanc = digitalRead(52);
  Bumper = !digitalRead(32);
  eAnt = millis();

  digitalWrite(LED_B, LOW);
  sharp_A = analogRead(A1);

  sharp_L = analogRead(A3) * 0.0048828125;
  gustavoGadao = 26 * pow(sharp_L, -1);

  if  ((Esq == 0) && (Dir == 0))  moverAngYtbm(120, 0, 130, 0);
  
  if  (Bumper == 1) {
    eAnt = millis();
    digitalWrite(LED_B, HIGH);
    while (millis() - eAnt < 2800)  {
      Esq = digitalRead(46);
      Dir = digitalRead(48);
      if  (((Esq == 0) && (Dir == 0)) || ((Esq == 1) && (Dir == 1)))  MOVE(240, 0, 240, 0);
      if  ((Esq == 1) && (Dir == 0))  MOVE(0, 255, 255, 0);
      if  ((Esq == 0) && (Dir == 1))  MOVE(255, 0, 0, 255);
    }
    digitalWrite(LED_B, LOW);
    // MOVE(170, 0, 170, 0); delay(600);
    // do {Dir = digitalRead(48); MOVE(0, 170, 170, 0);}  while (Dir == 0);
    // eAnt = millis();
    // while (millis() - eAnt < 1000)  {segueLinha();}
  }
  
  if  (sharp_A >= 390.00) {
    MOVE(255, 255, 255, 255);
    digitalWrite(eLED, LOW);  digitalWrite(dLED, LOW);
    shineLED(LED_R, 80, 80, 1);
    delay(300);
    Avanc = digitalRead(52);
    Esq = digitalRead(46);
    Dir = digitalRead(48);
    // do  {
    //   Avanc = digitalRead(52);
    //   Esq = digitalRead(46);
    //   Dir = digitalRead(48);
    //   MOVE(0, 140, 0, 0);
    // } while (Esq == 0);
    do  viraGyro(200, 0, 0, 200); while (angleZ >= -73.00);
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

    // while (sharp_L <= 70.00)  {
    //   sharp_L = analogRead(A3);
    //   MOVE(200, 0, 200, 0);
    // }
    // while (sharp_L >= 30.00)  {
    //   sharp_L = analogRead(A3);
    //   MOVE(200, 0, 200, 0);
    // }
    MOVE(200, 0, 200, 0); delay(1000);
    MOVE(255, 255, 255, 255); delay(300);
    cDesvio(105.00);
    MOVE(255, 255, 255, 255); delay(300);
    while (sharp_L <= 200.00)  {
      sharp_L = analogRead(A3);
      MOVE(200, 0, 200, 0);
    }
    while (sharp_L >= 100.00)  {
      digitalWrite(eLED, HIGH);
      sharp_L = analogRead(A3);
      MOVE(200, 0, 200, 0);
    }
    digitalWrite(eLED, LOW);
    MOVE(200, 0, 200, 0); delay(260);
    MOVE(255, 255, 255, 255); delay(300);
    cDesvio(117.00);
    while (sharp_L <= 300.00)  {
      sharp_L = analogRead(A3);
      MOVE(200, 0, 200, 0);
    }
    MOVE(255, 255, 255, 255); delay(300);
    do  viraGyro(180, 0, 0, 200); while (angleZ >= -90.00);
    MOVE(0, 130, 0, 130);
    delay(300);
    // return;
    MOVE(160, 0, 160, 0); delay(400);
    // do  viraGyro(0, 180, 180, 0); while (angleZ <= 90.00);
    do  {
      MOVE(0, 180, 180, 0); Avanc = digitalRead(52);
    } while (Avanc == 0);
  }


  if  (((extEsq == 1) && (Esq == 1)) || ((extDir == 1) && (Dir == 1)))  {
    shineLED(LED_G, eLED, dLED, 0);
    stopForRead(4, 270);
    extEsq = digitalRead(42); extDir = digitalRead(50);

    if  ((extEsq == 1) && (extDir == 1))  {
      if  ((mediaE() < VP) && (mediaD() < VP))
      {
        if  ((mediaE() >= VE) && (mediaD() >= DV))  {
          shineLED(LED_B, eLED, dLED, 1);
          deg180Dobra(0.00, true);
          return;
        }
        shineLED(LED_B, eLED, dLED, 0);
      }
      if  ((mediaE() >= VE) && (mediaE() < VP))
      {
        isIt90();
        shineLED(LED_G, eLED, dLED, 1);
        deg90Dobra(left, true);
        shineLED(LED_G, eLED, dLED, 0);
        return;
      }
      if  ((mediaD() >= DV) && (mediaD() < VP)) {
        isIt90();
        shineLED(LED_G, eLED, dLED, 1);
        deg90Dobra(right, true);
        shineLED(LED_G, eLED, dLED, 0);
        return;
      }
      if  ((mediaE() < VE) && (mediaD() < DV))  {
        shineLED(80, eLED, dLED, 1);
        isIt90();
        whiteAhead();
        shineLED(80, eLED, dLED, 0);
        return;        
      }
    }    
    if  ((extEsq == 1) && (extDir == 0))  {
      if  ((mediaE() >= VE) && (mediaE() < VP)) wasGL = true;
      if  (mediaE() < VE) wasGL = false;
      shineLED(eLED, 80, 80, 1);
      if  ((mediaE() < VP) && (mediaD() < VP)){
        if  ((mediaE() >= VE) && (mediaD() >= DV))  {
          shineLED(LED_B, eLED, 80, 1);
          deg180Dobra(0.00, true);
          shineLED(LED_B, eLED, 80, 0);
          return;
        }
      }
      shineLED(80, eLED, 80, 1);
      isIt90();
      MOVE(0, 100, 0, 100);
      if  (allow == true) {
        shineLED(80, eLED, 80, 1);
        deg90Dobra(left, true);
        shineLED(80, eLED, 80, 0);
        return;
      }
      if  (wasGL == true) {
        shineLED(LED_G, eLED, 80, 1);
        deg90Dobra(left, true);
        shineLED(LED_G, eLED, 80, 0);
        return;
      }
      else  {
        shineLED(80, eLED, 80, 1);
        whiteAhead();
        shineLED(80, eLED, 80, 0);
      }
    }
    if  ((extEsq == 0) && (extDir == 1))  {
      MOVE(100, 0, 100, 0);
      if  ((mediaD() >= DV) && (mediaD() < VP)) wasGR = true;
      if  (mediaD() < DV) wasGR = false;
      shineLED(80, 80, dLED, 1);
      if  ((mediaE() < VP) && (mediaD() < VP))  {
        if  ((mediaE() >= VE) && (mediaD() >= DV))  {
          shineLED(LED_B, 80, dLED, 1);
          deg180Dobra(0.00, true);
          shineLED(LED_B, 80, dLED, 0);
          return;
        }
      }
      isIt90();
      MOVE(255, 255, 255, 255);
      if  (allow == true) {
        shineLED(80, 80, dLED, 1);
        deg90Dobra(right, true);
        shineLED(80, 80, dLED, 0);
        return;
      }
      if  (wasGR == true) {
        shineLED(LED_G, 80, dLED, 1);
        deg90Dobra(right, true);
        shineLED(LED_G, 80, dLED, 0);
        return;
      }
      else  {
        shineLED(80, 80, dLED, 1);
        whiteAhead();
        shineLED(80, 80, dLED, 1);
      }
    }
  }
  if  (angleY <= -26.00)  {
    eAnt = millis();
    MOVE(150, 0, 150, 0);
    serv.attach(Tail);
    serv.write(34);
    delay(300);
    sharp_L = analogRead(A3) * 0.0048828125;
    gustavoGadao = 26 * pow(sharp_L, -1);
    while  (gustavoGadao <= 20) {
      digitalWrite(LED_R, LOW);
      sharp_L = analogRead(A3) * 0.0048828125;
      gustavoGadao = 26 * pow(sharp_L, -1);
      Esq = digitalRead(46);
      Dir = digitalRead(48);
      if  (millis() - eAnt >= 200)  {
        eAnt = millis();
        digitalWrite(LED_B, !digitalRead(LED_B));
        digitalWrite(eLED, !digitalRead(eLED));
        digitalWrite(dLED, !digitalRead(dLED));
        TTR = true;
      }
      if  (((Esq == 0) && (Dir == 0)) || ((Esq == 1) && (Dir == 1)))  moverAngYtbm(230, 0, 210, 0);
      if  ((Esq == 1) && (Dir == 0))  moverAngYtbm(0, 150, 170, 0);
      if  ((Esq == 0) && (Dir == 1))  moverAngYtbm(170, 0, 0, 150);
    }
    eAnt = millis();
    while((gustavoGadao > 20) && (angleY <= -10.00))  {
      Serial.print(gustavoGadao); Serial.print(" | ");
      Esq = digitalRead(46);
      Dir = digitalRead(48);
      if  (millis() - eAnt > 300) {
        eAnt = millis();
        digitalWrite(eLED, !digitalRead(eLED)); digitalWrite(dLED, !digitalRead(dLED));
        digitalWrite(LED_R, !digitalRead(LED_R));
      }
      sharp_L = analogRead(A3) * 0.0048828125;
      gustavoGadao = 26 * pow(sharp_L, -1);

      if  (((Esq == 0) && (Dir == 0)) || ((Esq == 1) && (Dir == 1)))  moverAngYtbm(200, 0, 200, 0);
      if  ((Esq == 1) && (Dir == 0))  moverAngYtbm(0, 120, 160, 0);
      if  ((Esq == 0) && (Dir == 1))  moverAngYtbm(160, 0, 0, 120);
      if  ((angleY >= -17.00) && (angleY <= 15.00))  {
        serv.write(5);
        serv.detach();
        eAnt = millis();
        while (millis() - eAnt < 1000)  {
          moverAngYtbm(255, 255, 255, 255);
        }
      }
      while (angleZ >= 6.00)  {
        Esq = digitalRead(46);
        Dir = digitalRead(48);
        if  (((Esq == 0) && (Dir == 0)) || ((Esq == 1) && (Dir == 1)))  moverAngYtbm(90, 0, 90, 0);
        if  ((Esq == 1) && (Dir == 0))  moverAngYtbm(0, 180, 180, 0);
        if  ((Esq == 0) && (Dir == 1))  moverAngYtbm(180, 0, 0, 180);
      }
    }

  }
  digitalWrite(eLED, LOW);
  digitalWrite(dLED, LOW);

  
  if  ((Esq == 1) && (Dir == 0))  moverAngYtbm(0, 180, 200, 0);
  if  ((Dir == 1) && (Esq == 0))  moverAngYtbm(200, 0, 0, 190);
