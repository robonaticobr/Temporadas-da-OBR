sensor_EE = digitalRead(52);
sensor_C = digitalRead(50);
sensor_A = digitalRead(38);
sensor_ED = digitalRead(42);
sensor_PE = digitalRead(44);
sensor_PD = digitalRead(27);
//90° ESQUERDA
if ((sensor_ED == 0) && (sensor_A == 0) && (sensor_PE == 1) && (sensor_C == 1) && (sensor_EE == 1))
{
  curvaE = 1;

  analogWrite(mfE, 255);
  analogWrite(mtE, 255);
  analogWrite(mfD, 255);
  analogWrite(mtD, 255);
  delay(500);

  pinMode(22, OUTPUT);  // LEDBE
  digitalWrite(LEDBE, HIGH);

  analogWrite(mfE, 190);
  analogWrite(mtE, 0);
  analogWrite(mfD, 190);
  analogWrite(mtD, 0);
  delay(140);

  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(27);
  if ((sensor_A == 0) && (curvaE == 1))
  {
    sensor_PD = digitalRead(27);
    while (sensor_PD == 0)
    {
      sensor_PD = digitalRead(27);
      curvaE = 0;
      sensor_PD = digitalRead(27);
      analogWrite(mfE, 0);
      analogWrite(mtE, 210);
      analogWrite(mfD, 200);
      analogWrite(mtD, 0);
    }
  }

  analogWrite(mfE, 255);
  analogWrite(mtE, 255);
  analogWrite(mfD, 255);
  analogWrite(mtD, 255);
  delay(500);

  analogWrite(mfE, 0);
  analogWrite(mtE, 120);
  analogWrite(mfD, 0);
  analogWrite(mtD, 140);
  delay(160);
  return;
}
}

