#include <Servo.h>

Servo bolas;

void setup() {
bolas.attach(36);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bolas.write(80);
  delay(500);
  Serial.println(bolas.read());
  bolas.write(20);
  delay(500);
  Serial.println(bolas.read());
}
