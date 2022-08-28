
int japa= 53;



void setup() {
pinMode(japa,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  japa = digitalRead(53);
  Serial.println(japa);
}

