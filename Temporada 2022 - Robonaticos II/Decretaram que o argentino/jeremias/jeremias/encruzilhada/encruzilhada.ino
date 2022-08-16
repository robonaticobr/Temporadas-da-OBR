 //ENCRUZILHADA
  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(46);

  if ((sensor_EE == 1) && (sensor_ED == 1) && (sensor_PE == 1) && (sensor_PD == 1) && (sensor_A == 1))
  {

    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);

    analogWrite(mfE, 120);
    analogWrite(mtE, 0);
    analogWrite(mfD, 120);
    analogWrite(mtD, 0);
    delay(250);
  }
  return;

