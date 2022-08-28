void loop() {
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
  avEsq    = digitalRead(35);
  avDir    = digitalRead(50);
  
  Esq = digitalRead(39);
  Dir = digitalRead(43);
  extEsq = digitalRead(33); extDir = digitalRead(42);
  Middle = digitalRead(66);
  //  Bumper = !digitalRead(32);
  eAnt = millis();
  sharp_L = analogRead(A3);
  RSPDOWN = analogRead(A7);

  if  ((extEsq == 0) && (extDir == 0) && (Esq == 0) && (Dir == 0) && (angleY >= -10.00))  moverAngYtbm(110, 0, 150, 0);
  if  ((sharp_L <= 200) && (RSPDOWN <= 200) && (millis() - Inc >= 900) && (angleY >= -6.00)) {
    angleY = 0.01;
    Inc = millis();
    digitalWrite(LED_G, HIGH);
  }
  if  (sharpAverage() <= 8) {
    rightDetour();
  }
  if  (((extEsq == 1) && (Esq == 1) && (Middle == 1)) || ((extDir == 1) && (Dir == 1) && (Middle == 1)))  {
    int Front = 0;
    stopForRead(3, 40);
    extEsq   = digitalRead(33);
    extDir   = digitalRead(42);
    shineLED(LED_G, eLED, dLED, 0);
    eAnt = millis();
    for (int i = 0; i < 40; i++)  {
      avEsq    = digitalRead(35);
      avMiddle = digitalRead(29);
      avDir    = digitalRead(50);
      Front = avEsq + avMiddle + avDir;
    }
    if  (Front == 0)  {
      for (int i = 0; i < 4; i++)  {
        avEsq    = digitalRead(35);
        avMiddle = digitalRead(29);
        avDir    = digitalRead(50);
        Front = avEsq + avMiddle + avDir;
        delay(30);
      }
    }
//    while (1) {
//      extEsq = digitalRead(33);
//      extDir = digitalRead(42);
//      Serial.print(svE()); Serial.print(" | "); Serial.println(svD());
//    };
    if  ((Front == 0) && ((extEsq == 0) || (extDir == 0)))  {
      while ((millis() - eAnt < 90) && ((extEsq == 0) || (extDir == 0)) && (Front == 0)) {
        if  (avEsq == 0)     avEsq    = digitalRead(35);
        if  (avMiddle == 0)  avMiddle = digitalRead(29);
        if  (avDir == 0)     avDir    = digitalRead(50);
        Front = avEsq + avMiddle + avDir;
        if  (extEsq == 0) extEsq = digitalRead(33);
        if  (extDir == 0) extDir = digitalRead(42);
        MOVE(0, 0, 0, 0);
      }
      if  ((extEsq  == 1) && (extDir == 0)) {
        deg90Dobra(left, true);
        while (svE() >= 1000)  MOVE(0, 110, 0, 150);
        return;
      }
      if  ((extEsq  == 0) && (extDir == 1) && (Front == 0))   {
        eAnt = millis();
//        while (millis() - eAnt < 240) viraGyro(100, 0, 0, 205);
        MOVE(140, 0, 140, 0); delay(60);
        deg90Dobra(right, true);
        while (svD() >= 1000)  MOVE(0, 90, 0, 170);
        MOVE(0, 0, 0, 0); delay(200);
        return;
      }
    }
    else {
      if  ((extEsq == 1) && (extDir == 1))  {
        if ((svE() <= 3000) && (svD() <= 3000)) {
          deg180Dobra(0.00, true);
          while ((svE() >= 1000) && (svD() >= 1000)) {MOVE(0, 110, 0, 170);}
          MOVE(0, 0, 0, 0); delay(200);
          return;
        }
        if  ((svE() <= 3000) && (svD() >= 3000) && (svE() >= 500))  {
          shineLED(LED_G, eLED, dLED, 1);
          deg90Dobra(left, true);
          shineLED(LED_G, eLED, dLED, 0);
          while (svE() >= 1000)  MOVE(0, 130, 0, 150);
          return;
        }
        if  ((svE() >= 3000) && (svD() <= 3000) && (svD() >= 500)) {
          shineLED(LED_G, eLED, dLED, 1);
          MOVE(0, 100, 0, 140); delay(140);
          deg90Dobra(right, true);
          shineLED(LED_G, eLED, dLED, 0);
          while (svD() >= 1000)  MOVE(0, 110, 0, 130);
          return;
        }
        whiteAhead(); return;
      }
      
      if  ((extEsq == 1) && (extDir == 0))  {
        if  ((svE() <= 2000) && (svD() >= 3000) && (svE() >= 500)) {
          shineLED(LED_G, eLED, 80, 1);
          deg90Dobra(left, true);
          shineLED(LED_G, eLED, dLED, 0);
          while (svE() >= 1000)  MOVE(0, 140, 0, 180);
        }
        whiteAhead(); return;
      }
      if  ((extEsq == 0) && (extDir == 1))  {
        if  ((svE() >= 3000) && (svD() <= 3000) && (svD() >= 600)) {
          shineLED(LED_G, 80, dLED, 1);
          MOVE(0, 100, 0, 140); delay(140);
          deg90Dobra(right, true);
          shineLED(LED_G, eLED, dLED, 0);
          while (svD() >= 1000)  MOVE(0, 90, 0, 160);
          return;
        }
        whiteAhead(); return;
      }
    }
  }
  digitalWrite(eLED, LOW);
  digitalWrite(dLED, LOW);

  if  ((sharp_L <= 200) && (RSPDOWN <= 200)) PAREDAO = millis();
  else PAREDAO = PAREDAO;

  if  ((sharp_L >= 200) && (RSPDOWN >= 200) && (millis() - PAREDAO > 3000))  subUP = true;
  if  ((angleY <= -20.00) && (sharp_L >= 200)) subUP = true;

  if  (angleY <= -10.00)  {
    digitalWrite(dLED, HIGH);
    if  ((Esq == 0) && (Dir == 0)) moverAngYtbm(140, 0, 190, 0);
    if  ((Esq == 1) && (Dir == 0)) moverAngYtbm(140, 0, 170, 0);
    if  ((Esq == 0) && (Dir == 1)) moverAngYtbm(170, 0, 140, 0);
  }

  if  (subUP == true) {
    digitalWrite(LED_B, HIGH);
    Esq = digitalRead(39);
    MOVE(170, 0, 190, 0); delay(600);
    eAnt = millis();
    while (millis() - eAnt <= 300) {
      if  ((Esq == 0) && (Dir == 0)) MOVE(170, 0, 190, 0);
      if  ((Esq == 1) && (Dir == 0)) MOVE(0, 110, 200, 0);
      if  ((Esq == 0) && (Dir == 1)) MOVE(190, 0, 0, 150);
    }

    serv.attach(Tail);
    serv.write(28);
    if  (sharp_L >= 200) {
      TTR = true;
      MOVE(255, 255, 255, 255);
      delay(400);
    }
    while (sharp_L >= 200) {
      float m = 0;
      sharp_L = analogRead(A3);
      Esq = digitalRead(39);
      Dir = digitalRead(43);
      extEsq = digitalRead(33);
      extDir = digitalRead(42);
      Middle = digitalRead(66);
      if  ((Esq == 0) && (Dir == 0)) moverAngYtbm(170, 0, 220, 0);
      if  (((extEsq == 1) || (Esq == 1)) && (Dir == 0)) moverAngYtbm(0, 140, 200, 0);
      if  ((Esq == 0) && ((Dir == 1) || (extDir == 1))) moverAngYtbm(150, 0, 0, 210);
      if  (((extEsq == 1) && (Esq == 1) && (Middle == 1)) || ((Middle == 1) && (Dir == 1) && (extDir == 1))) {moverAngYtbm(150, 0, 180, 0); delay(900);}
    }
  }

  if  ((angleY <= -22.00) && (sharp_L <= 200)) {
    digitalWrite(LED_G, HIGH);
    serv.attach(Tail);
    serv.write(28);
    moverAngYtbm(170, 0, 190, 0); delay(300);
    while ((TTR == false) && (angleY <= 0.00)) {
      digitalWrite(LED_G, HIGH);
      Esq = digitalRead(39);
      Dir = digitalRead(43);
      extEsq = digitalRead(33);
      extDir = digitalRead(42);
      if  ((Esq == 0) && (Dir == 0)) moverAngYtbm(150, 0, 180, 0);
      if  (((extEsq == 1) || (Esq == 1)) && (Dir == 0)) moverAngYtbm(0, 120, 180, 0);
      if  ((Esq == 0) && ((Dir == 1) || (extDir == 1))) moverAngYtbm(180, 0, 0, 130);
    }
    eAnt = millis();
    while(millis() - eAnt < 1000) {
      Esq = digitalRead(39);
      Dir = digitalRead(43);
      extEsq = digitalRead(33);
      extDir = digitalRead(42);
      Middle = digitalRead(66);
      if  ((Esq == 0) && (Dir == 0))  MOVE(0, 0, 0, 0);
      if  ((Esq == 1) && (Dir == 0)) {MOVE(0, 150, 170, 0); eAnt = millis();}
      if  ((Esq == 0) && (Dir == 1)) {MOVE(140, 0, 0, 190); eAnt = millis();}
      if  ((extEsq == 1) && (Esq == 1) && (Middle == 0)) {MOVE(0, 200, 130, 0); eAnt = millis();}
      if  ((extDir == 1) && (Dir == 1) && (Middle == 0)) {MOVE(130, 0, 0, 220); eAnt = millis();}
      if  ((extEsq == 1) && (Esq == 0)) {MOVE(0, 220, 150, 0); eAnt = millis();}
      if  ((extDir == 1) && (Dir == 0)) {MOVE(160, 0, 0, 220); eAnt = millis();}
    }
    serv.attach(Tail);
    serv.write(4);
    serv.detach();
    digitalWrite(eLED, LOW);
    eAnt = millis();
//    while (millis() - eAnt < 900)  {
//      Esq = digitalRead(39);
//      Dir = digitalRead(43);
//      if  ((Esq == 0) && (Dir == 0))  MOVE(100, 0, 140, 0);
//      if  ((Esq == 1) && (Dir == 0))  MOVE(0, 160, 110, 0);
//      if  ((Esq == 0) && (Dir == 1))  MOVE(110, 0, 0, 190);
//    }
    MOVE(120, 0, 160, 0); delay(500);
    MOVE(0, 110, 0, 160); delay(500);
    while (1) {
      digitalWrite(LED_G, HIGH);
      Esq = digitalRead(39);
      Dir = digitalRead(43);
      extEsq = digitalRead(33);
      extDir = digitalRead(42);
      Middle = digitalRead(66);
      if  ((Esq == 0) && (Dir == 0)) MOVE(100, 0, 130, 0);
      if  ((Esq == 1) && (Dir == 0)) MOVE(0, 150, 170, 0);
      if  ((Esq == 0) && (Dir == 1)) MOVE(140, 0, 0, 190);
      if  ((extEsq == 1) && (Esq == 1) && (Middle == 0))  MOVE(0, 200, 130, 0);
      if  ((extDir == 1) && (Dir == 1) && (Middle == 0)) MOVE(130, 0, 0, 220);
      if  ((extEsq == 1) && (Esq == 0)) MOVE(0, 220, 150, 0);
      if  ((extDir == 1) && (Dir == 0)) MOVE(160, 0, 0, 220);
      if  (((extEsq == 1) && (Esq == 1) && (Middle == 1)) || ((Middle == 1) && (Dir == 1) && (extDir == 1)))  {
        MOVE(255, 255, 255, 255); delay(300);
        return;
      }
      if  (sharpAverage() < 7)  {
        MOVE(255, 255, 255, 255); delay(300);
        return;
      }
    }
    eAnt = millis();
  }
  Dir = digitalRead(43);
  if  ((Esq == 1) && (Dir == 0) && (angleY >= -10.00))  {
    moverAngYtbm(0, 180, 160, 0);
  }
  if  ((Esq == 0) && (Dir == 1) && (angleY >= -10.00))  {
    moverAngYtbm(140, 0, 0, 210);
  }
  if  ((extEsq == 1) && (Esq == 1) && (Middle == 0)) moverAngYtbm(0, 220, 150, 0);
  if  ((extDir == 1) && (Dir == 1) && (Middle == 0)) moverAngYtbm(160, 0, 0, 220);
  if  ((extEsq == 1) && (Esq == 0)) moverAngYtbm(0, 220, 150, 0);
  if  ((extDir == 1) && (Dir == 0)) moverAngYtbm(160, 0, 0, 220);
