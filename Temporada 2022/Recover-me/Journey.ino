void loop() {
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
  Acc = 0;
  
  Esq = digitalRead(46);
  Dir = digitalRead(48);
  extEsq = digitalRead(42); extDir = digitalRead(50);
  Avanc = digitalRead(52);
  Middle = digitalRead(44);
  Bumper = !digitalRead(32);
  eAnt = millis();

  digitalWrite(LED_B, LOW);
  if  (BOLA == false) {
    for (byte i = 0; i < 5; i++) {
      sharp_A = analogRead(A1);
      Acc += sharp_A;
    }
  }

  sharp_L = analogRead(A3) * 0.0048828125;
  gustavoGadao = 26 * pow(sharp_L, -1);

  if  ((Esq == 0) && (Dir == 0))  moverAngYtbm(122, 0, 122, 0);
  
  if  (Bumper == 1) {
    eAnt = millis();
    digitalWrite(LED_B, HIGH);
//    while (millis() - eAnt < 800)  {
//      Esq = digitalRead(46);
//      Dir = digitalRead(48);
//      if  (((Esq == 0) && (Dir == 0)) || ((Esq == 1) && (Dir == 1)))  MOVE(240, 0, 240, 0);
//      if  ((Esq == 1) && (Dir == 0))  MOVE(0, 255, 255, 0);
//      if  ((Esq == 0) && (Dir == 1))  MOVE(255, 0, 0, 255);
//    }
    MOVE(200, 0, 200, 0); delay(800);
    MOVE(0, 150, 0, 150); delay(700);
    MOVE(0, 0, 0, 0); delay(400);
    digitalWrite(LED_B, LOW);
    // MOVE(170, 0, 170, 0); delay(600);
    // do {Dir = digitalRead(48); MOVE(0, 170, 170, 0);}  while (Dir == 0);
    // eAnt = millis();
    // while (millis() - eAnt < 1000)  {segueLinha();}
  }
  
  if  (Acc >= 2500.00) doDesvio();
  
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
        shineLED(LED_G, eLED, dLED, 1);
        isIt90();
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























  
  if  (angleY <= -15.00)  {
    MOVE(0, 0, 0, 0); delay(200);
    while ((angleY >= -35.00) && (angleY <= 1.00)) {
      Esq = digitalRead(46);
      Dir = digitalRead(48);
      if ((Esq == 0) && (Dir == 0)) moverAngYtbm(120, 0, 150, 0);
      if ((Esq == 1) && (Dir == 0)) moverAngYtbm(120, 0, 150, 0);
      if ((Esq == 0) && (Dir == 1)) moverAngYtbm(150, 0, 150, 0);
    }
    while (angleY <= -6.00) {
      sharp_L = analogRead(A3) * 0.0048828125;
      gustavoGadao = 26 * pow(sharp_L, -1);

      Lever = millis();
      if  (gustavoGadao <= 30) do {
        Avanc = digitalRead(52);
        Esq = digitalRead(46);
        Dir = digitalRead(48);
        MOVE(0, 130, 160, 0);
      } while ((Esq == 0) && (Avanc == 0) && (Dir == 0));
      while  (gustavoGadao <= 30) {
        serv.attach(Tail);
        if (millis() - Lever >= 600) serv.write(22);
        TTR = true;
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
        }
        if  (((Esq == 0) && (Dir == 0)) || ((Esq == 1) && (Dir == 1)))  moverAngYtbm(210, 0, 210, 0);
        if  ((Esq == 1) && (Dir == 0) || (extEsq == 1))  moverAngYtbm(0, 120, 190, 0);
        if  ((Esq == 0) && (Dir == 1) || (extDir == 1))  moverAngYtbm(190, 0, 0, 170);
      }

      eAnt = millis();
      while (gustavoGadao > 30)  {

        Esq = digitalRead(46);
        Dir = digitalRead(48);
        serv.attach(Tail);
        serv.write(22);
        if  (millis() - eAnt > 300) {
          eAnt = millis();
          digitalWrite(eLED, !digitalRead(eLED)); digitalWrite(dLED, !digitalRead(dLED));
          digitalWrite(LED_R, !digitalRead(LED_R));
        }
        sharp_L = analogRead(A3) * 0.0048828125;
        gustavoGadao = 26 * pow(sharp_L, -1);

        if  (((Esq == 0) && (Dir == 0)) || ((Esq == 1) && (Dir == 1)))  moverAngYtbm(135, 0, 135, 0);
        if  ((Esq == 1) && (Dir == 0))  moverAngYtbm(0, 100, 150, 0);
        if  ((Esq == 0) && (Dir == 1))  moverAngYtbm(170, 0, 0, 100);
        if  ((angleY >= -30.00) && (angleY <= 15.00))  {
          serv.write(10);
          serv.detach();
          eAnt = millis();
          while (millis() - eAnt < 1000)  moverAngYtbm(255, 255, 255, 255);
          MOVE(90, 0, 90, 0); delay(500);
          return;
        }
      }
    }
  }
    
  digitalWrite(eLED, LOW);
  digitalWrite(dLED, LOW);

  
  if  ((Esq == 1) && (Dir == 0))  {MOVE(0, 140, 150, 0);}
  if  ((Dir == 1) && (Esq == 0))  {MOVE(170, 0, 0, 170);}
  // TTR = true;
