  if  (TTR == true) {
    serv.attach(Tail);
    serv.write(0);
    delay(300);
    serv.detach();
    MOVE(255, 255, 255, 255); delay(1000);
    analogWrite(Intake, 255);
    MOVE(160, 0, 170, 0); delay(1800);
    MOVE(255, 255, 255, 255); delay(200);
    CAVALU(90.00, true, 1200);
    delay(1000);
    idBase();

    if  (ZERO >= 480) {
      mrBean(1500);
      CAVALU(-90.00, false, 0);
      Broom(0);
      do  viraGyro(0, 170, 0, 30);  while (angleZ <= 140.00);
      MOVE(0, 230, 0, 230); delay(1000);
      riseServo(3000);
      Broom(7);
      CAVALU(-152.00, true, 1200);
      Broom(0);

      do  viraGyro(0, 190, 0, 60);  while (angleZ <= 135.00);
      MOVE(0, 230, 0, 230); delay(2100);
      riseServo(3000);
      MOVE(130, 0, 130, 0); delay(2000);
      analogWrite(Intake, 0);
      MOVE(0, 0, 0, 0);
      while (true);
    }
    else  {
      Broom(0);
      CAVALU(-186.00, true, 1800);
      idBase();
      if  (ZERO >= 500)  {
        MOVE(150, 0, 150, 0); delay(300);
        CAVALU(97.00, true, 1300);
        riseServo(3000);
        do  viraGyro(0, 60, 190, 0); while (angleZ <= 45.00); angleZ = 0.01;
        Broom(0);
        CAVALU(-100.00, true, 1200);
        Broom(0);
        do  viraGyro(0, 180, 90, 0); while (angleZ <= 45.00); angleZ = 0.01;
        Broom(5);
        MOVE(0, 230, 0, 230); delay(2700);
        riseServo(3000);
        do  viraGyro(190, 0, 0, 90);  while (angleZ >= -35.00); angleZ = 0.01;
        do  viraGyro(160, 0, 0, 160); while (angleZ >= -45.00); angleZ = 0.01;
        Broom(10);
        MOVE(0, 230, 0, 230); delay(1600);
        CAVALU(50.00, false, 0);
        MOVE(0, 230, 0, 230); delay(800);
        riseServo(3000);
        analogWrite(Intake, 0);
        MOVE(120, 0, 120, 0); delay(1000);
        MOVE(0, 0, 0, 0);
        while (true);
      }
      else  {
        analogWrite(Intake, 255);
        MOVE(150, 0, 150, 0); delay(300);
        do  viraGyro(120, 0, 0, 180); while (angleZ >= -90.00);  angleZ = 0;
        Broom(0);
        // do  {
        //   ASP = analogRead(A1) * 0.0048828125;
        //   aMetrica = 26 * pow(ASP, -1);
        //   MOVE(80, 0, 190, 0);
        // } while (aMetrica >= 12);
        CAVALU(90.00, true, 1200);
        Broom(0);
        do viraGyro(170, 0, 0, 170); while (angleZ >= -60.00); angleZ = 0.01;
        MOVE(0, 230, 0, 230); delay(5000);
        riseServo(3000);
        analogWrite(Intake, 0);
        do  viraGyro(0, 80, 170, 0); while (angleZ <= 82.00); angleZ = 0.01;
        Broom(0);
        MOVE(0, 200, 0, 200); delay(1500);
        do  viraGyro(160, 0, 0, 160); while (angleZ >= -50.00); angleZ = 0.01;
        MOVE(0, 230, 0, 230); delay(900);
        riseServo(3000);
        analogWrite(Intake, 0);
        MOVE(120, 0, 120, 0); delay(1000);
        while(true) {MOVE(0, 0, 0, 0);};
      }
    }
  }
}
