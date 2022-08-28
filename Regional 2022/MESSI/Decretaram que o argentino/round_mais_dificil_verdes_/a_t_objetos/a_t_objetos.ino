if (sensor_O >= 630)
{
  analogWrite(mfE, 255);
  analogWrite(mtE, 255);
  analogWrite(mfD, 255);
  analogWrite(mtD, 255);
  delay(500);

  analogWrite(mfE, 0);
  analogWrite(mtE, 160);
  analogWrite(mfD, 0);
  analogWrite(mtD, 160);
  delay(100);

  analogWrite(mfE, 200);
  analogWrite(mtE, 0);
  analogWrite(mfD, 0);
  analogWrite(mtD, 170);
  delay(1000);

  analogWrite(mfE, 200);
  analogWrite(mtE, 0);
  analogWrite(mfD, 180);
  analogWrite(mtD, 0);
  delay(900);

  analogWrite(mfE, 0);
  analogWrite(mtE, 210);
  analogWrite(mfD, 200);
  analogWrite(mtD, 0);
  delay(850);

  analogWrite(mfE, 200);
  analogWrite(mtE, 0);
  analogWrite(mfD, 180);
  analogWrite(mtD, 0);
  delay(1600);

  analogWrite(mfE, 0);
  analogWrite(mtE, 210);
  analogWrite(mfD, 200);
  analogWrite(mtD, 0);
  delay(850);

  if (sensor_ED == 0)
  {
    sensor_ED = digitalRead(42);
    while (sensor_ED == 0)
    {
      sensor_ED = digitalRead(42);
      analogWrite(mfE, 180);
      analogWrite(mtE, 0);
      analogWrite(mfD, 200);
      analogWrite(mtD, 0);
    }

    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 180);
    delay(950);
  }

  if ((sensor_A == 0) && (curvaE == 1))
  {
    Serial.println(sensor_C);
    sensor_C = digitalRead(50);
    while (sensor_C == 0)
    {
      sensor_C = digitalRead(50);
      curvaE = 0;
      sensor_C = digitalRead(50);
      analogWrite(mfE, 0);
      analogWrite(mtE, 210);
      analogWrite(mfD, 200);
      analogWrite(mtD, 0);
    }
  }
