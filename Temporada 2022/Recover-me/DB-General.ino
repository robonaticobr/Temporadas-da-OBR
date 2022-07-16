// ==================================================================================== MOTORES
#define  motor1   7                   //  Porta PWM do motor da esquerda para a frente      -           Tag: LeftD
#define  motor1t  6                   //  Porta PWM do motor da esquerda para trás          -           Tag: LeftR
#define  motor2   5                   //  Porta P40WM do motor da direita para a frente       -           Tag: RightD
#define  motor2t  4                   //  Porta PWM do motor da direita para trás           -           Tag: RightR

#define Intake    11
#define servoPort 36
#define Tail      40


byte Force_A = 120;
byte Force_B = 100;
// ==================================================================================== / MOTORES



// ==================================================================================== SÓ OS VERDES
#define eLED    22          // LED de saída para depuração de leitura
#define LED_R   24
#define LED_G   26
#define LED_B   28
#define dLED    30

int vdE = A15;             // Porta analógica dos sensores
int vdD = A14;

long vdEAmount;        // Armazenar as leituras para realizar a média, respectiamente dos sensores vdE e vdD
long vdDAmount;

long mediaE();             // Declaração da função de filtro de média dos sensores, com base  na array
long mediaE();
// ==================================================================================== / SÓ OS VERDES



// ==================================================================================== SEnSORES DE SEGUE-LInHA
byte Avanc   = 52;                     // As portas de configuração de pino estão sendo previamente informadas para facilitar na configuração
byte extEsq  = 42;
byte extDir  = 50;
byte Esq = 46;
byte Dir = 48;
byte Middle  = 44;
// ==================================================================================== / SEnSORES DE SEGUE-LInHA



// ==================================================================================== SEnSORES DE PROXIMIDADE
float sharp_A = A1;
float sharp_L = A3;

int RSPUP   = A6;
int RSPDOWN = A7;

byte Bumper = 32;
// ==================================================================================== / SEnSORES DE PROXIMIDADE



// ========================================================================================================= AUXILIAR EM SEGUE-LINHA
int VE = 55;                    // Valor do sensor infravermelho vdE quando vê marca verde
int DV = 22;                    // Valor do sensor infravermelho vdD quando vê marca verde
int VP = 300;                   // Valor geral dos sensores quando a aparente marcação verde não parece verídica
int gustavoGadao = 0;

unsigned long eAnt = 0;
unsigned long gustavoCorno = 0;
unsigned long blinkk = 0;

long ZERO = 0;

bool TTR = false;
bool Corrigiu = false;
bool room3 = false;                    // Identifica o fechamento do Segue-linha e à entrada ao terceiro salão
bool allow = true;                     // Confirma a condição de curva de 90° simples para permitir ou bloquear
bool wasGL = false;
bool wasGR = false;
bool subUP = false;
// ========================================================================================================= / AUXILIAR EM SEGUE-LINHA 
