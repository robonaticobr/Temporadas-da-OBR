void setup() {
  serv.attach(Tail);

  serv.detach();
  pinMode(motor1, OUTPUT); pinMode(motor1t, OUTPUT);                                // Pinos do motor da esquerda - Configurados como SAÍDA de dados
  pinMode(motor2, OUTPUT); pinMode(motor2t, OUTPUT);                                // Pinos do motor da direita  - "
     
  pinMode(LED_R, OUTPUT);                                                           // Estes dados indicarão a força para os motores
  pinMode(LED_G, OUTPUT); pinMode(eLED, OUTPUT);
  pinMode(LED_B, OUTPUT); pinMode(dLED, OUTPUT);

  pinMode(Bumper, INPUT_PULLUP);

  pinMode(Avanc, INPUT_PULLUP);
  pinMode(Esq, INPUT_PULLUP);
  pinMode(Dir, INPUT_PULLUP);     // Pinos da frente, esquerda e direita configurados como ENTRADA de dados
  
  pinMode(Middle, INPUT_PULLUP);
  pinMode(extEsq, INPUT);      pinMode(extDir, INPUT_PULLUP);                                        // Pinos da extrema esquerda e da extrema direita
  pinMode(vdD, INPUT_PULLUP);  pinMode(vdE, INPUT_PULLUP);                                           // Pinos dos sensores de verde. Estão configurados como PULLUP, para termos valores mais flexíveis de leitura

  pinMode(sharp_A, INPUT);                                                            // Pinos dos sensores infravermelhos de proximidade
  pinMode(sharp_L, INPUT);
  pinMode(RSPUP,   INPUT);
  pinMode(RSPDOWN, INPUT);

  serv.attach(36);
  serv.write(97);
  delay(300);
  serv.detach();

  serv.attach(Tail);
  serv.write(3);
  delay(300);
  
  for (int i = 0; i < 2; i++) {                                                    // Regulagem da posição da alavanca traseira do robô
    serv.write(25);
    delay(150);
    serv.write(6);
    delay(150);
  }
  
  serv.detach();
  Wire.begin();                                                                     // Robô, RECEBA a biblioteca Wire.
  Serial.begin(9600);                                                               // Robô, te apresento o monitor Serial. Vocês se comunicarão a uma velocidade de 9600 bytes de transmissão
  delay(100);                                                                       // Aguarda 100 milissegundos para a biblioteca iniciar

  Wire.beginTransmission(Gyro);                                                     //Conexão inicial com o giroscópio - variável Gyro declarada com seu endereço HEX
  Wire.write(0x20);
  Wire.write(15);
  Wire.endTransmission();

  Wire.beginTransmission(Gyro);                                                     //Conexão inicial com o giroscópio - variável Gyro declarada com seu endereço HEX
  Wire.write(0x23);
  Wire.write(48);
  Wire.endTransmission();
  for (uint8_t i = 0; i <= 100; i++) {
    sharp_A = analogRead(A1);
  }
  for (uint8_t i = 0; i <= 100; i++) {
    sharp_L = analogRead(A3);
  }
  // while (true)  {
  //   idBase();
  // };
  angleY = 0.01;
  angleZ = 0.01;
}
