curvaE = 0;

    verdeE = verde + sensor_VE;
    sensor_VE = analogRead(A15);
    if ((verdeE >= 600) && (verdeE <= 750))
Serial.println(verdeE);
    { analogWrite(mfE, 255);
      analogWrite(mtE, 255);
      analogWrite(mfD, 255);
      analogWrite(mtD, 255);
      delay(500);

      analogWrite(mfE, 150);
      analogWrite(mtE, 0);
      analogWrite(mfD, 150);
      analogWrite(mtD, 0);
      delay(150);

      analogWrite(mfE, 0);
      analogWrite(mtE, 150);
      analogWrite(mfD, 150);
      analogWrite(mtD, 0);
      delay(500);

      digitalWrite(26, HIGH);

      Serial.println(sensor_C);
      sensor_PD = digitalRead(46);
      while (sensor_PD == 0)
      {
        curvaE = 0;

        sensor_PD = digitalRead(46);

        sensor_PD = digitalRead(46);
        analogWrite(mfE, 0);
        analogWrite(mtE, 180);
        analogWrite(mfD, 120);
        analogWrite(mtD, 0);

      }

      analogWrite(mfE, 255);
      analogWrite(mtE, 255);
      analogWrite(mfD, 255);
      analogWrite(mtD, 255);
      delay(500);

      analogWrite(mfE, 0);
      analogWrite(mtE, 130);
      analogWrite(mfD, 0);
      analogWrite(mtD, 140);
      delay(200);


      verdeE = 0;
    }

    sensor_EE = digitalRead(52);
    sensor_C = digitalRead(50);
    sensor_A = digitalRead(38);
    sensor_ED = digitalRead(42);
    sensor_PE = digitalRead(44);
    sensor_PD = digitalRead(46);

    if ((sensor_EE == 0) && (sensor_A == 0) && (sensor_PE == 0) && (sensor_C == 0) && (sensor_PD == 0) && (curvaE == 1))
    {
      Serial.println(sensor_C);
      sensor_PD = digitalRead(46);
      while (sensor_PD == 0)
      {
        curvaE = 0;

        sensor_PD = digitalRead(46);

        sensor_PD = digitalRead(46);
        analogWrite(mfE, 0);
        analogWrite(mtE, 180);
        analogWrite(mfD, 120);
        analogWrite(mtD, 0);

      }
