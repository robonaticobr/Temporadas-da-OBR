//ENCRUZILHADA meia volta

if ((sensor_EE == 1) && (sensor_ED == 1))
{
  int davigay = 0;
  int daviviado = 0;
  for (int i = 0; i < 30; i++)
  {
    sensor_VD = analogRead(A7);
    sensor_VE = analogRead(A15);
    davigay += sensor_VE;
    daviviado += sensor_VD;
  }
  sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);

  if ((daviviado >= 1510) && (daviviado <= 1800) && (davigay >= 1370) && (davigay <= 1800))
  {
    curvaD = 1;
    pinMode(26, OUTPUT);  // LEDV
    digitalWrite(LEDV, HIGH);

    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 180);
    delay(2200);

    //          if ((sensor_EE == 0) && (curvaD = 1)) sensor_C = digitalRead(50);
    sensor_C = digitalRead(50);
    while (sensor_C == 0) 
    {
      curvaD = 0;
      sensor_C = digitalRead(50);
      analogWrite(mfE, 180);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 180);
    }
  }
  digitalWrite(mfE, 50);
  digitalWrite(mtD, 0);
  digitalWrite(mfD, 50);
  digitalWrite(mtE, 0);
  delay(70);
  return;
}
//ENCRUZILHADA curva para direita

if ((sensor_EE == 1) && (sensor_ED == 1)) 
{
  pinMode(30, OUTPUT);  // LEDBD
  digitalWrite(LEDBD, HIGH);
  pinMode(24, OUTPUT);  //LEDv
  digitalWrite(LEDv, HIGH);

  int davigay = 0;
  int daviviado = 0;
  for (int i = 0; i < 30; i++) 
  {
    sensor_VD = analogRead(A7);
    sensor_VE = analogRead(A15);
    davigay += sensor_VE;
    daviviado += sensor_VD;
  }

  Serial.print(sensor_VE);
  Serial.print(" | ");
  Serial.println(sensor_VD);
  if ((daviviado >= 1510) && (daviviado <= 1800)) 
  {
    pinMode(26, OUTPUT);  // LEDV
    digitalWrite(LEDV, HIGH);

    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 180);
    analogWrite(mtD, 0);
    delay(200);

    analogWrite(mfE, 180);
    analogWrite(mtE, 0);
    analogWrite(mfD, 0);
    analogWrite(mtD, 200);
    delay(700);

    sensor_A = digitalRead(38);
    while (sensor_A == 0) 
    {
      sensor_A = digitalRead(38);
      analogWrite(mfE, 170);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 200);
    }
    digitalWrite(mfE, 160);
    digitalWrite(mtD, 0);
    digitalWrite(mfD, 160);
    digitalWrite(mtE, 0);
    delay(100);
    return;
  }
}

//ENCRUZILHADA curva para esquerda
if ((sensor_EE == 1) && (sensor_ED == 1)) 
{
  pinMode(22, OUTPUT);  // LEDBE
  digitalWrite(LEDBE, HIGH);
  pinMode(24, OUTPUT);  //LEDv
  digitalWrite(LEDv, HIGH);

  int davigay = 0;
  int daviviado = 0;
  for (int i = 0; i < 30; i++) 
  {
    sensor_VD = analogRead(A7);
    sensor_VE = analogRead(A15);
    davigay += sensor_VE;
    daviviado += sensor_VD;
  }

  if ((davigay >= 1370) && (davigay <= 1800))
  {
    pinMode(26, OUTPUT);  // LEDV
    digitalWrite(LEDV, HIGH);

    analogWrite(mfE, 160);
    analogWrite(mtE, 0);
    analogWrite(mfD, 160);
    analogWrite(mtD, 0);
    delay(190);

    analogWrite(mfE, 0);
    analogWrite(mtE, 190);
    analogWrite(mfD, 170);
    analogWrite(mtD, 0);
    delay(550);
    sensor_A = digitalRead(38);
    while (sensor_A == 0)
    {
      sensor_A = digitalRead(38);
      analogWrite(mfE, 0);
      analogWrite(mtE, 190);
      analogWrite(mfD, 160);
      analogWrite(mtD, 0);
    }
  }
  digitalWrite(mfE, 160);
  digitalWrite(mtD, 0);
  digitalWrite(mfD, 160);
  digitalWrite(mtE, 0);
  delay(100);
  return;
}
