// ==================================================================================== MOTORES
#define  motor1   7                   //  Porta PWM do motor da esquerda para a frente      -           Tag: LeftD
#define  motor1t  6                   //  Porta PWM do motor da esquerda para trás          -           Tag: LeftR
#define  motor2   5                   //  Porta P40WM do motor da direita para a frente       -           Tag: RightD
#define  motor2t  4                   //  Porta PWM do motor da direita para trás           -           Tag: RightR

#define Intake    10
#define servoPort 34
#define Tail      44


byte Force_A = 120;
byte Force_B = 100;
// ==================================================================================== / MOTORES

// ==================================================================================== OBJETOS DE COMUNICAÇÃO DOS SENSORES DE COR

Adafruit_TCS34725softi2c vdE = Adafruit_TCS34725softi2c(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X, 47, 49);
Adafruit_TCS34725softi2c vdD = Adafruit_TCS34725softi2c(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X, 51, 53);

uint16_t lr, lg, lb;
uint16_t rr, rg, rb;
uint16_t clear;

int eSoma = 0;
int dSoma = 0;

// ==================================================================================== / OBJETOS DE COMUNICAÇÃO DOS SENSORES DE COR

// ==================================================================================== SÓ OS VERDES
#define eLED    22          // LED de saída para depuração de leitura
#define LED_R   24
#define LED_G   26
#define LED_B   28
#define dLED    30

int josephBoladao = A14;             // Porta analógica dos sensores
int eleGosta = A15;

long vdEAmount;        // Armazenar as leituras para realizar a média, respectiamente dos sensores vdE e vdD
long vdDAmount;

long mediaE();             // Declaração da função de filtro de média dos sensores, com base  na array
long mediaE();
// ==================================================================================== / SÓ OS VERDES





// ==================================================================================== SEnSORES DE SEGUE-LInHA
byte avEsq    = 35;                     // As portas de configuração de pino estão sendo previamente informadas para facilitar na configuração
byte avMiddle = 29;
byte avDir    = 50;
byte extEsq  = 33;
byte extDir  = 42;
byte Esq = 39;
byte Dir = 43;
byte Middle  = 66;
// ==================================================================================== / SEnSORES DE SEGUE-LInHA





// ==================================================================================== SEnSORES DE PROXIMIDADE
int sharp_A = A1;
int sharp_L = A3;
float auxiliar = 0;

int RSPUP   = A6;
int RSPDOWN = A7;

byte Bumper = 32;
// ==================================================================================== / SEnSORES DE PROXIMIDADE






// ========================================================================================================= AUXILIAR EM SEGUE-LINHA
float Consequence = 0;

uint8_t Other = 0;

int BE = 110;                   // Valor do sensor infravermelho vdE quando vê marca verde
int BD = 24;                    // Valor do sensor infravermelho vdD quando vê marca verde
int VP = 900;                   // Valor geral dos sensores quando a aparente marcação verde não parece verídica
int gustavoGadao = 0;
int Acc = 0;
int Distance = 0;


unsigned long eAnt = 0;
unsigned long gustavoCorno = 0;
unsigned long blinkk = 0;
unsigned long SirensPJ = 0;
unsigned long Lever = 0;
unsigned long Inc = 0;
unsigned long PAREDAO = 0;

long ZERO = 0;

bool TTR = false;                      // Identifica o fechamento do Segue-linha e à entrada ao terceiro salão
bool Corrigiu = false;
bool turnBack = false;
bool allow = true;                     // Confirma a condição de curva de 90° simples para permitir ou bloquear
bool wasGL = false;
bool wasGR = false;
bool subUP = false;
bool Vision = false;
bool BOLA = false;
bool outroBool = true;
// ========================================================================================================= / AUXILIAR EM SEGUE-LINHA 

