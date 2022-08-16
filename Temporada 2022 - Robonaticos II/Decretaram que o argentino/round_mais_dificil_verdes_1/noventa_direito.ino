// 90° DIREITA
if ((sensor_EE == 0) && (sensor_A == 0) && (sensor_C == 1) && (sensor_PD == 1) && (sensor_ED == 1)) 
{
  curvaD = 1;

  analogWrite(mfE, 255);
  analogWrite(mtE, 255);
  analogWrite(mfD, 255);
  analogWrite(mtD, 255);
  delay(500);

  pinMode(30, OUTPUT);  // LEDBD
  digitalWrite(LEDBD, HIGH);

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
  if ((sensor_A == 0) && (curvaD == 1)) 
  {
    sensor_PE = digitalRead(44);
    while (sensor_PE == 0) 
    {
      sensor_PE = digitalRead(44);
      curvaD = 0;
      sensor_PE = digitalRead(44);
      analogWrite(mfE, 220);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 205);
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
}
return;
