//TESTE DE SENSOR
int sensor_VD = A7;
int sensor_VE = A15;
int sensor_EE = 52;
int sensor_C = 50;
int sensor_A = 38;
int sensor_ED = 42;
int sensor_PE = 44;
int sensor_PD = 27;
int sensor_O = A3;
int sensor_T = 53;

void setup() {

  pinMode(sensor_VE, INPUT_PULLUP);
  pinMode(sensor_VD, INPUT_PULLUP);
  pinMode(sensor_EE, INPUT_PULLUP);
  pinMode(sensor_C, INPUT_PULLUP);
  pinMode(sensor_A, INPUT_PULLUP);
  pinMode(sensor_ED, INPUT_PULLUP);
  pinMode(sensor_PE, INPUT_PULLUP);
  pinMode(sensor_PD, INPUT_PULLUP);
  pinMode(sensor_O, INPUT_PULLUP);
  pinMode(sensor_T, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  sensor_VD = analogRead(A7);
  sensor_VE = analogRead(A15);
  sensor_EE = digitalRead(52);
  sensor_C = digitalRead(50);
  sensor_A = digitalRead(38);
  sensor_ED = digitalRead(42);
  sensor_PE = digitalRead(44);
  sensor_PD = digitalRead(27);
  sensor_O = analogRead(A3);
  sensor_T = digitalRead(53);

  Serial.print("sensor_T= ");
  Serial.println(sensor_T);

  //SENSORES VERDES

//    int davigay = 0;
//    int daviviado = 0;
//    for (int i = 0; i < 30; i++)
//    {
//      sensor_VD = analogRead(A7);
//      sensor_VE = analogRead(A15);
//      davigay += sensor_VE;
//      daviviado += sensor_VD;
//    }
//    Serial.print("VE"); Serial.print(" | "); Serial.print(davigay); Serial.print(" VD | "); Serial.println(daviviado);
//    Serial.print("sensor_VD=");
//    Serial.print(sensor_VD);
//    Serial.print("||");
//    Serial.print("sensor_VE=");
//    Serial.println(sensor_VE);

  //SENSORES NORMAIS

//    Serial.print("sensor_EE= ");
//    Serial.print(sensor_EE);
//    Serial.print("||");
//    Serial.print(" sensor_C= ");
//    Serial.print(sensor_C);
//    Serial.print("||");
//    Serial.print(" sensor_A= ");
//    Serial.print(sensor_A);
//    Serial.print("||");
//    Serial.print(" sensor_ED= ");
//    Serial.print(sensor_ED);
//    Serial.print("||");
//    Serial.print(" sensor_PE= ");
//    Serial.print(sensor_PE);
//    Serial.print("||");
//    Serial.print(" sensor_PD= ");
//    Serial.print(sensor_PD);
//    Serial.println("||");

  //SESNSOR DE OBJEYOS

  //Serial.print("sensor_O = ");
  //Serial.println(sensor_O);
  //Serial.print("||");
}
