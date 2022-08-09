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
//    idBase();
    ZERO = 0;
//    while (true)  {
//      ZERO = 0;
//      for (int i = 0; i < 10; i++)  {
//        sharp_A = analogRead(A1);
//        Serial.print(sharp_A); Serial.print(" | ");
//        sharp_A = analogRead(A1) * 0.0048828125;
//        gustavoCorno = 26 * pow(sharp_A, -1);
//      }
//      Serial.println(gustavoCorno);
//    };
    
    MOVE(255, 255, 255, 255); delay(1000);
    analogWrite(Intake, 255);
    MOVE(170, 0, 170, 0); delay(300);
    CAVALU(100.00, true, 1000);
    ZERO = 0;
    while (ZERO <= 1700.00)  {
      ZERO = 0;
      for (int i = 0; i < 10; i++)  {
        sharp_A = analogRead(A1);
        ZERO += sharp_A;
      }
      Serial.println(ZERO);
      MOVE(200, 0, 200, 0);
    }
    ZERO = 0;
    MOVE(0, 0, 0, 0); delay(600);
    MOVE(0, 200, 0, 200); delay(2000);
    CAVALU(-95.00, false, 0);
    Vision = false;
    Broom(24);
    ZERO = 0;
    CAVALU(110.00, true, 1200);  MOVE(255, 255, 255, 255);
    idBase();

    if  (ZERO >= 700) {
      digitalWrite(LED_G, HIGH); delay(200); digitalWrite(LED_G, LOW);
      Broom(0);
      MOVE(0, 230, 0, 230); delay(1200);
      CAVALU(-135.00, false, 0);
      MOVE(130, 0, 130, 0); delay(1000);
      MOVE(0, 0, 0, 0); delay(300);
      CAVALU(200.00, true, 1200);
      serv.attach(15);
      serv.write(180);
      delay(600);
      serv.detach();
      riseServo(3000);
      Broom(10);
      do  viraGyro(170, 0, 0, 170); while (angleZ >= -52.00); angleZ = 0.01;
      MOVE(255, 255, 255, 255); delay(300);
      CAVALU(-90.00, true, 1400);
      MOVE(255, 255, 255, 255); delay(400);
      Broom(0);
      MOVE(120, 0, 120, 0); delay(200);
      CAVALU(-85.00, true, 1000);
      ZERO = 0;
      while (ZERO <= 1600.00)  {
        ZERO = 0;
        for (int i = 0; i < 10; i++)  {
          sharp_A = analogRead(A1);
          ZERO += sharp_A;
        }
        Serial.println(ZERO);
        MOVE(200, 0, 200, 0);
      }
      MOVE(170, 0, 170, 0); delay(350);
      CAVALU(-50.00, false, 0);
      MOVE(170, 0, 170, 0); delay(800);
      CAVALU(-90.00, true, 1300);
      riseServo(3000);
      CAVALU(-45.00, false, 0);
      Broom(0);
      CAVALU(86.00, false, 0);
      Broom(0);
      MOVE(170, 0, 170, 0); delay(150);
      MOVE(0, 0, 0, 0); delay(600);
      CAVALU(-6.00, false, 0);
      MOVE(0, 200, 0, 200); delay(300);
      CAVALU(-10.00, false, 0);
      MOVE(0, 200, 0, 200); delay(1050);
      CAVALU(-56.00, true, 2500);
      riseServo(3000);
      analogWrite(Intake, 0);
      MOVE(0, 0, 0, 0);
      while (true);
    }
    else  {
      Broom(0);
      MOVE(0, 0, 0, 0); delay(300);
      MOVE(0, 130, 0, 130); delay(200);
      CAVALU(-110.00, false, 0);
      MOVE(0, 140, 0, 140); delay(300);
      CAVALU(-150.00, true, 1800);
      ZERO = 0;
      while (1) {idBase();};
      if  (ZERO >= 700)  {
        digitalWrite(LED_G, HIGH); delay(200); digitalWrite(LED_G, LOW);
        MOVE(150, 0, 150, 0); delay(300);
        CAVALU(-80.00, false, 0);
        MOVE(130, 0, 160, 0); delay(1600);
        CAVALU(90.00, true, 1200);
        serv.attach(15);
        serv.write(180);
        delay(600);
        serv.detach();
        riseServo(3000);
        do  viraGyro(0, 60, 190, 0); while (angleZ <= 45.00); angleZ = 0.01;
        Broom(0);
        CAVALU(-100.00, true, 1200);
        Broom(0);
        MOVE(0, 130, 0, 130); delay(400);
        CAVALU(-90.00, true, 1200);
        MOVE(170, 0, 170, 0); delay(1200);
        CAVALU(45.00, true, 1000);
        CAVALU(120.00, true, 2500);
        riseServo(3000);
        do  viraGyro(190, 0, 0, 90);  while (angleZ >= -35.00); angleZ = 0.01;
        do  viraGyro(160, 0, 0, 160); while (angleZ >= -45.00); angleZ = 0.01;
        Broom(10);
        MOVE(0, 230, 0, 230); delay(1600);
        CAVALU(50.00, false, 0);
        MOVE(0, 230, 0, 230); delay(1000);
        riseServo(3000);
        analogWrite(Intake, 0);
        MOVE(120, 0, 120, 0); delay(1000);
        MOVE(0, 0, 0, 0);
        while (true);
      }
      else  {
        digitalWrite(LED_R, HIGH); delay(200); digitalWrite(LED_R, LOW);
        analogWrite(Intake, 255);
        MOVE(150, 0, 150, 0); delay(700);
        CAVALU(-70.00, true, 1500);
        serv.attach(15);
        serv.write(180);
        delay(600);
        serv.detach();
        riseServo(3000);
        do  viraGyro(180, 0, 0, 80); while (angleZ >= -70.00);  angleZ = 0.01;
        Broom(0);
        MOVE(0, 0, 0, 0); delay(800);
        do  viraGyro(0, 160, 160, 0); while (angleZ <= 20.00);
        do  viraGyro(160, 0, 0, 160); while (angleZ >= -2.00);
        MOVE(0, 0, 0, 0); angleZ = -2.00;
        MOVE(0, 170, 0, 170); delay(300);
        CAVALU(90.00, true, 1200);
        Broom(0);
        CAVALU(-40.00, true, 2700);
        riseServo(3000);
        MOVE(170, 0, 170, 0); delay(700);
        CAVALU(-270.00, false, 0);
        Broom(0);
        MOVE(0, 200, 0, 200); delay(2000);
        do  viraGyro(160, 0, 0, 160); while (angleZ >= -50.00); angleZ = 0.01;
        MOVE(0, 230, 0, 230); delay(1200);
        riseServo(3000);
        CAVALU(60.00, false, 0);
        Broom(0);
        CAVALU(-90.00, true, 1800);
        MOVE(170, 0, 170, 0); delay(2300);
        CAVALU(30.00, true, 1000);
        CAVALU(50.00, true, 1600);
        while(true) {MOVE(0, 0, 0, 0);};
      }
    }
  }
}
