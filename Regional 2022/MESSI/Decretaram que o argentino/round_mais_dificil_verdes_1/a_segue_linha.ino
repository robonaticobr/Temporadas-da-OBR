//SEGUE LINHA GAP
  if ((sensor_PE == 0) && (sensor_PD == 0)) 
  {
    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 160);
    analogWrite(mtD, 0);
  }
  //SEGUE LINHA AJUSTE
  if ((sensor_PE == 0) && (sensor_PD == 1)) 
  {
    digitalWrite(26, HIGH);
    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 190);
  }
  if ((sensor_PE == 1) && (sensor_PD == 0)) 
  {
    digitalWrite(22, HIGH);
    analogWrite(mfE, 0);
    analogWrite(mtE, 180);
    analogWrite(mfD, 190);
    analogWrite(mtD, 0);
  }
