#include <Wire.h>              // Boas vindas à biblioteca que usaremos para o giroscópio
#include <Adafruit_TCS34725softi2c.h>
#include <Servo.h>
Servo serv;


#define Gyro_gY0    0x2A       //  Configuração dos eixos Y do giroscópio
#define Gyro_gY1    0x2B       //  Serão usados para identificar redutores de velocidade e a rampa
#define Gyro_gZ0    0x2C       //  Configuração dos eixos Z do giroscópio
#define Gyro_gZ1    0x2D       //  Serão usados para determinar curvas precisas de 90°

int Gyro = 0x69;

int gY0, gY1, gY_out;                     //  Transmissão de valores do eixo Y
int gZ0, gZ1, gZ_out;                     //  Transmissão de valroes do eixo Z

float Yg, Zg;
float angleY, angleZ, angleYc, angleZc;
float dt = 0.015;                         // Cara importante para a conversão da transmissão para valor decimal

unsigned long start,finished, elapsed;    // !         Verificar para que esses caras servem

// ========================================================================================================= AUXILIAR EM GIROSCÓPIO
float left = 70.00;             // Este valor será usado ao pedir uma curva para a esquerda
float right = -60.00;           // -_- -70 -_- / Este valor será usado ao pedir uma curva para a direita
float pAng = 5.00;
// =========================================================================================================/ AUXILIAR EM GIROSCÓPIO

