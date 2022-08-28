//T para esquerda
if ((sensor_EE == 1) && (sensor_ED == 0))
{
  digitalWrite(mfE, 255);
  digitalWrite(mtD, 255);
  digitalWrite(mfE, 255);
  digitalWrite(mtD, 255);
  delay(1000);

  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(27);

  if ((sensor_EE == 1) && (sensor_ED == 0))
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

    if ((davigay >= 1370) && (davigay <= 1800))
    {
      curvaE = 1;
      pinMode(26, OUTPUT);  // LEDV
      digitalWrite(LEDV, HIGH);
      pinMode(22, OUTPUT);  // LEDBE
      digitalWrite(LEDBE, HIGH);
      pinMode(28, OUTPUT);  //LEDA
      digitalWrite(LEDA, HIGH);

      digitalWrite(mtE, 120);
      digitalWrite(mfD, 120);
      digitalWrite(mfE, 0);
      digitalWrite(mtD, 0);
      delay(400);

      if ((sensor_A == 0) && (curvaE == 1))
      {
        Serial.println(sensor_A);
        sensor_PD = digitalRead(27);
        while (sensor_PD == 0)
        {
          sensor_PD = digitalRead(27);
          curvaE = 0;
          sensor_PD = digitalRead(27);
          analogWrite(mfE, 0);
          analogWrite(mtE, 160);
          analogWrite(mfD, 150);
          analogWrite(mtD, 0);
        }
      }

      sensor_EE = digitalRead(52);
      sensor_C = digitalRead(50);
      sensor_A = digitalRead(38);
      sensor_ED = digitalRead(42);
      sensor_PE = digitalRead(44);
      sensor_PD = digitalRead(27);

      digitalWrite(mfE, 160);
      digitalWrite(mtD, 0);
      digitalWrite(mfD, 160);
      digitalWrite(mtE, 0);
      delay(100);
      return;
    }
  }
}
sensor_EE = digitalRead(52);
sensor_C = digitalRead(50);
sensor_A = digitalRead(38);
sensor_ED = digitalRead(42);
sensor_PE = digitalRead(44);
sensor_PD = digitalRead(27);


//      //T para direita
if ((sensor_EE == 0) && (sensor_ED == 1))
{
  curvaD = 1;
  digitalWrite(mfE, 255);
  digitalWrite(mtD, 255);
  digitalWrite(mfE, 255);
  digitalWrite(mtD, 255);
  delay(1000);

  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(27);

  if ((sensor_EE == 0) && (sensor_ED == 1))
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

    if ((daviviado >= 1550) && (daviviado <= 1800)) 
    {
      pinMode(30, OUTPUT);  // LEDBD
      digitalWrite(LEDBD, HIGH);
      pinMode(26, OUTPUT);  // LEDV
      digitalWrite(LEDV, HIGH);
      pinMode(28, OUTPUT);  //LEDA
      digitalWrite(LEDA, HIGH);

      analogWrite(mfE, 150);
      analogWrite(mtE, 0);
      analogWrite(mfD, 150);
      analogWrite(mtD, 0);
      delay(150);

      analogWrite(mfE, 200);
      analogWrite(mtE, 0);
      analogWrite(mfD, 0);
      analogWrite(mtD, 180);
      delay(600);

      sensor_EE = digitalRead(52);
      sensor_C = digitalRead(50);
      sensor_A = digitalRead(38);
      sensor_ED = digitalRead(42);
      sensor_PE = digitalRead(44);
      sensor_PD = digitalRead(27);


      if ((sensor_A == 0) && (curvaD = 1)) 
      {
        while (sensor_C == 0) 
        {
          sensor_C = digitalRead(50);
          curvaD = 0;
          analogWrite(mfE, 200);
          analogWrite(mtE, 0);
          analogWrite(mfD, 0);
          analogWrite(mtD, 200);
        }
      }
      analogWrite(mfE, 160);
      analogWrite(mtE, 0);
      analogWrite(mfD, 160);
      analogWrite(mtD, 0);
      delay(100);
      return;
    }
  }
}
digitalWrite(mfE, 50);
digitalWrite(mtE, 0);
digitalWrite(mfD, 50);
digitalWrite(mtD, 0);
delay(50);
return;
}  //chave 2
}    //chave 1
