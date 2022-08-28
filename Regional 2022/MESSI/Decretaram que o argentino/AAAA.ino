 if (((sensor_EE == 1) && (sensor_PE == 1)) || ((sensor_ED == 1) && (sensor_PD == 1)))
  {
    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

    sensor_EE = digitalRead(52);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(46);


    //ENCRUZILHADA meia volta

    if ((sensor_EE == 1) && (sensor_ED == 1)) {
      sensor_VD = analogRead(A7);
      sensor_VE = analogRead(A15);

      if ((sensor_VD >= 810) && (sensor_VD <= 900) && (sensor_VE >= 700) && (sensor_VE <= 850)) {

        analogWrite(mfE, 120);
        analogWrite(mtE, 0);
        analogWrite(mfD, 0);
        analogWrite(mtD, 130);
        delay(1600);

        if (sensor_A == 0)  curvaD = 1;
        sensor_C = digitalRead(50);
        sensor_C = digitalRead(50);
        while (sensor_C == 0)
        {
          curvaD = 0;
          sensor_C = digitalRead(50);
          analogWrite(mfE, 150);
          analogWrite(mtE, 0);
          analogWrite(mfD, 0);
          analogWrite(mtD, 160);
        }
      }

      //ENCRUZILHADA curva para direita

      if ((sensor_VD >= 810) && (sensor_VD <= 900) && (sensor_VE < 700))
      {
        analogWrite(mfE, 160);
        analogWrite(mtE, 0);
        analogWrite(mfD, 160);
        analogWrite(mtD, 0);
        delay(350);

        analogWrite(mfE, 160);
        analogWrite(mtE, 0);
        analogWrite(mfD, 0);
        analogWrite(mtD, 160);
        delay(500);
      }
      Serial.println(sensor_C);
      sensor_C = digitalRead(50);
      while (sensor_C == 0)
      {
        sensor_C = digitalRead(50);
        analogWrite(mfE, 150);
        analogWrite(mtE, 0);
        analogWrite(mfD, 0);
        analogWrite(mtD, 160);
      }
    }

    //ENCRUZILHADA curva para esquerda

    if ((sensor_VE >= 700) && (sensor_VE <= 850) && (sensor_VD <= 810)) {

      analogWrite(mfE, 160);
      analogWrite(mtE, 0);
      analogWrite(mfD, 160);
      analogWrite(mtD, 0);
      delay(350);

      analogWrite(mfE, 0);
      analogWrite(mtE, 160);
      analogWrite(mfD, 160);
      analogWrite(mtD, 0);
      delay(500);
      sensor_C = digitalRead(50);
      while (sensor_C == 0)
      {
        sensor_C = digitalRead(50);
        analogWrite(mfE, 0);
        analogWrite(mtE, 150);
        analogWrite(mfD, 160);
        analogWrite(mtD, 0);

      }

    }
    //T para esquerda
    if ((sensor_EE == 1) && (sensor_ED == 0)) {
      sensor_VD = analogRead(A7);
      sensor_VE = analogRead(A15);

      if ((sensor_VE >= 700) && (sensor_VE <= 850) && (sensor_VD <= 810))
      {
        analogWrite(mfE, 160);
        analogWrite(mtE, 0);
        analogWrite(mfD, 160);
        analogWrite(mtD, 0);
        delay(350);

        analogWrite(mfE, 0);
        analogWrite(mtE, 160);
        analogWrite(mfD, 160);
        analogWrite(mtD, 0);
        delay(500);
      }
      sensor_EE = digitalRead(52);
      sensor_C = digitalRead(50);
      sensor_A = digitalRead(38);
      sensor_ED = digitalRead(42);
      sensor_PE = digitalRead(44);
      sensor_PD = digitalRead(46);
      if (curvaE == 1)
      {
        Serial.println(sensor_C);
        sensor_C = digitalRead(50);
        while (sensor_C == 0)
        {
          curvaE = 0;

          sensor_C = digitalRead(50);
          analogWrite(mfE, 0);
          analogWrite(mtE, 150);
          analogWrite(mfD, 160);
          analogWrite(mtD, 0);

        }
      }

      //T para direita
      if ((sensor_EE == 0) && (sensor_ED == 1)) {
        sensor_VD = analogRead(A7);
        sensor_VE = analogRead(A15);

        if ((sensor_VD >= 810) && (sensor_VD <= 900) && (sensor_VE < 700))

        {
          analogWrite(mfE, 160);
          analogWrite(mtE, 0);
          analogWrite(mfD, 160);
          analogWrite(mtD, 0);
          delay(350);

          analogWrite(mfE, 160);
          analogWrite(mtE, 0);
          analogWrite(mfD, 0);
          analogWrite(mtD, 160);
          delay(500);

          if (sensor_A == 0)  curvaD = 1;

        }
        sensor_EE = digitalRead(52);
        sensor_C = digitalRead(50);
        sensor_A = digitalRead(38);
        sensor_ED = digitalRead(42);
        sensor_PE = digitalRead(44);
        sensor_PD = digitalRead(46);
        if (curvaD == 1)
        {
          Serial.println(sensor_C);
          sensor_C = digitalRead(50);
          while (sensor_C == 0)
          {
            curvaD = 0;

            sensor_C = digitalRead(50);
            analogWrite(mfE, 150);
            analogWrite(mtE, 0);
            analogWrite(mfD, 0);
            analogWrite(mtD, 160);
          }
        }
      }

    }


  }
}

