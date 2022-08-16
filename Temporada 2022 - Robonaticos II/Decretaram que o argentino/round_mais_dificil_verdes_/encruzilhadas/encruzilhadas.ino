//IFzão

if (((sensor_EE == 1) && (sensor_A == 1) && (sensor_PE == 1)) || ((sensor_ED == 1) && (sensor_PD == 1) && (sensor_A == 1))) 
{  //chave 1
  analogWrite(mfE, 255);
  analogWrite(mtE, 255);
  analogWrite(mfD, 255);
  analogWrite(mtD, 255);
  delay(500);

  sensor_EE = digitalRead(52);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(27);

  if (((sensor_EE == 1) && (sensor_A == 1) && (sensor_PE == 1)) || ((sensor_ED == 1) && (sensor_PD == 1) && (sensor_A == 1))) 
  {  //chave 2
    pinMode(22, OUTPUT);  // LEDBE
    digitalWrite(LEDBE, HIGH);
    pinMode(24, OUTPUT);  //LEDv
    digitalWrite(LEDv, HIGH);
    pinMode(30, OUTPUT);  // LEDBD
    digitalWrite(LEDBD, HIGH);

    analogWrite(mfE, 255);
    analogWrite(mtE, 255);
    analogWrite(mfD, 255);
    analogWrite(mtD, 255);
    delay(500);


 
