byte mfE = 5;
byte mtE = 4;
byte mfD = 7;
byte mtD = 6;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  analogWrite(mfE, 0);
  analogWrite(mtE, 190);
  analogWrite(mfD, 170);
  analogWrite(mtD, 0);



//  analogWrite(mfE, 165);
//  analogWrite(mtE, 0);
//  analogWrite(mfD, 0);
//  analogWrite(mtD, 190);



}
