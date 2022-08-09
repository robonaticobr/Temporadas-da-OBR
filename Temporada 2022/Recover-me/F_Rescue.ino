  if  (TTR == true) {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
    serv.attach(Tail);
    serv.write(10);
    delay(300);
    serv.detach();
    serv.attach(36);
    serv.write(97);
    delay(300);
    serv.detach();
    
    MOVE(255, 255, 255, 255); delay(1000);
    analogWrite(Intake, 255);
    SirensPJ = millis();
    mrBean(500);
    CAVALU(100.00, true, 1000);
    ZERO = 0;
    while (ZERO <= 1700.00)  {
      ZERO = 0;
      Sirens(470);
      for (int i = 0; i < 10; i++)  {
        sharp_A = analogRead(A1);
        ZERO += sharp_A;
      }
      Serial.println(ZERO);
      MOVE(200, 0, 200, 0);
    }
    ZERO = 0;
    eAnt = millis();
    while (millis() - eAnt < 600) {Sirens(470); MOVE(0, 0, 0, 0);}
    eAnt = millis();
    while (millis() - eAnt < 1800) {Sirens(470); MOVE(0, 200, 0, 200);}
    
    CAVALU(-92.00, false, 0);
    Vision = false;
    for (int i = 0; i < 500; i++) sharp_A = analogRead(A1);
    while (ZERO <= 1400.00)  {
      Sirens(470);
      ZERO = 0;
      for (int i = 0; i < 10; i++)  {
        sharp_A = analogRead(A1);
        ZERO += sharp_A;
      }
      Serial.println(ZERO);
      MOVE(200, 0, 200, 0);
    }
    ZERO = 0;
    CAVALU(90.00, true, 1000);  MOVE(255, 255, 255, 255);
    idBase();

    if  (ZERO >= 700) {
      digitalWrite(LED_G, HIGH);
      eAnt = millis();
      while (millis() - eAnt <= 200) Sirens(470);
      digitalWrite(LED_G, LOW);
      Broom(0);
      eAnt = millis();
      while (millis() - eAnt <= 1200) {Sirens(470); MOVE(0, 230, 0, 230);}
      CAVALU(-135.00, false, 0);
      eAnt = millis();
      while (millis() - eAnt <= 1000) {Sirens(470); MOVE(130, 0, 130, 0);}
      while (millis() - eAnt <= 1400) {Sirens(470); MOVE(0, 0, 0, 0);}
      CAVALU(200.00, true, 1200);
      riseServo(3000);
      Broom(10);
      do  viraGyro(170, 0, 0, 170); while (angleZ >= -52.00); angleZ = 0.01;
      eAnt = millis();
      while (millis() - eAnt <= 300) {Sirens(470); MOVE(255, 255, 255, 255);}
      CAVALU(-90.00, true, 1400);
      eAnt = millis();      
      while (millis() - eAnt <= 400) {Sirens(470); MOVE(255, 255, 255, 255);}
      Broom(0);
      eAnt = millis();
      while (millis() - eAnt <= 200) {Sirens(470); MOVE(120, 0, 120, 0);}
      CAVALU(-85.00, true, 1000);
      ZERO = 0;
      while (ZERO <= 1600.00)  {
        ZERO = 0;
        Sirens(470);
        for (int i = 0; i < 10; i++)  {
          sharp_A = analogRead(A1);
          ZERO += sharp_A;
        }
        Serial.println(ZERO);
        MOVE(200, 0, 200, 0);
      }
      eAnt = millis();
      while (millis() - eAnt <= 250) {Sirens(470); MOVE(170, 0, 170, 0);}
      CAVALU(-50.00, false, 0);
      eAnt = millis();
      while (millis() - eAnt <= 800) {Sirens(470); MOVE(170, 0, 170, 0);}
      CAVALU(-90.00, true, 1300);
      riseServo(3000);
      CAVALU(-45.00, false, 0);
      Broom(0);
      CAVALU(86.00, false, 0);
      Broom(0);
      eAnt = millis();
      while (millis() - eAnt <= 750)  {
        Sirens(470);
        if  (millis() - eAnt <= 150)  MOVE(170, 0, 170, 0);
        else MOVE(0, 0, 0, 0);
      }
      CAVALU(-6.00, false, 0);
      eAnt = millis();
      while (millis() - eAnt <= 300) {Sirens(470); MOVE(0, 200, 0, 200);}
      CAVALU(-10.00, false, 0);
      eAnt = millis();
      while (millis() - eAnt <= 1050) {Sirens(470); MOVE(0, 200, 0, 200);}
      CAVALU(-56.00, true, 2500);
      riseServo(3000);
      analogWrite(Intake, 0);
      MOVE(0, 0, 0, 0);
      while (true);
    }
    else  {
      Broom(0);
      eAnt = millis();
      while (eAnt = millis() <= 500)  {
        Sirens(470);
        if  (millis() - eAnt <= 300) MOVE(0, 0, 0, 0);
        else MOVE(0, 130, 0, 130);
      }
      CAVALU(-160.00, true, 1800);
      ZERO = 0;
      idBase();
      if  (ZERO >= 700)  {
        eAnt = millis();
        while (millis() - eAnt <= 500)  { 
          Sirens(470);
          if  (millis() - eAnt <= 200) digitalWrite(LED_G, HIGH);
          else {MOVE(150, 0, 150, 0); digitalWrite(LED_G, LOW);}
        }
        CAVALU(-80.00, false, 0);
        eAnt = millis();
        while (millis() - eAnt <= 1600) {Sirens(470); MOVE(130, 0, 160, 0);}
        CAVALU(90.00, true, 1200);
        riseServo(3000);
        do  viraGyro(0, 60, 190, 0); while (angleZ <= 45.00); angleZ = 0.01;
        Broom(0);
        CAVALU(-100.00, true, 1200);
        Broom(0);
        eAnt = millis();
        while (millis() - eAnt <= 400) {Sirens(470); MOVE(0, 130, 0, 130);}
        CAVALU(-90.00, true, 1200);
        eAnt = millis();
        while (millis() - eAnt <= 1200) {Sirens(470); MOVE(170, 0, 170, 0);}
        CAVALU(45.00, true, 1000);
        CAVALU(120.00, true, 2500);
        riseServo(3000);
        do  viraGyro(190, 0, 0, 90);  while (angleZ >= -35.00); angleZ = 0.01;
        do  viraGyro(160, 0, 0, 160); while (angleZ >= -45.00); angleZ = 0.01;
        Broom(10);
        eAnt = millis();
        while (millis() - eAnt <= 1600) {Sirens(470); MOVE(0, 230, 0, 230);}
        CAVALU(50.00, false, 0);
        eAnt = millis(0);
        while (millis() - eAnt <= 1000) {Sirens(470); MOVE(0, 230, 0, 230);}
        riseServo(3000);
        analogWrite(Intake, 0);
        eAnt = millis();
        while (millis() - eAnt <= 1000) {Sirens(470); MOVE(120, 0, 120, 0);}
        MOVE(0, 0, 0, 0);
        while (true);
      }
      else  {
        eAnt = millis();
        while (millis() - eAnt <= 200) digitalWrite(LED_R, HIGH);
        digitalWrite(LED_R, LOW);
        analogWrite(Intake, 255);
        eAnt = millis();
        while (millis() - eAnt <= 700) {Sirens(470); MOVE(150, 0, 150, 0);}
        CAVALU(-70.00, true, 1500);
        riseServo(3000);
        do  viraGyro(180, 0, 0, 80); while (angleZ >= -70.00);  angleZ = 0.01;
        Broom(0);
        eAnt = millis();
        while (millis() - eAnt <= 800) {Sirens(470); MOVE(0, 0, 0, 0);}
        do  viraGyro(0, 160, 160, 0); while (angleZ <= 20.00);
        do  viraGyro(160, 0, 0, 160); while (angleZ >= -2.00);
        MOVE(0, 0, 0, 0); angleZ = -2.00;
        eAnt = millis();
        while (millis() - eAnt <= 300) {Sirens(470); MOVE(0, 170, 0, 170);}
        CAVALU(90.00, true, 1200);
        Broom(0);
        CAVALU(-40.00, true, 2700);
        riseServo(3000);
        eAnt = millis();
        while (millis() - eAnt <= 700) {Sirens(470); MOVE(170, 0, 170, 0);}
        CAVALU(-270.00, false, 0);
        Broom(0);
        eAnt = millis();
        while (millis() - eAnt <= 2000) {Sirens(470); MOVE(0, 200, 0, 200);}
        do  viraGyro(160, 0, 0, 160); while (angleZ >= -50.00); angleZ = 0.01;
        eAnt = millis();
        while (millis() - eAnt <= 1200) {Sirens(470); MOVE(0, 230, 0, 230);}
        riseServo(3000);
        CAVALU(60.00, false, 0);
        Broom(0);
        CAVALU(-90.00, true, 1800);
        eAnt = millis();
        while (millis() - eAnt <= 2300) {Sirens(470); MOVE(170, 0, 170, 0);}
        CAVALU(30.00, true, 1000);
        CAVALU(50.00, true, 1600);
        while(true) {MOVE(0, 0, 0, 0);};
      }
    }
  }
}
