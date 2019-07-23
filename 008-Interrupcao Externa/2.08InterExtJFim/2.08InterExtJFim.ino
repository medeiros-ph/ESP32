/*Cria um código por meio de interrupção que seja capaz de detectar o apertar de um botão, e daí mantenha um led ligado por 2 segundos*/
/*Declaração do Pino que será usado na interrupção*/
const byte botao = 2;

/*Declaração da variavel que vai sinalizar a interrupção*/
volatile int sinal = 0;

/*Declaração do Pino que será usado no LED*/
#define Led 4

/*Criar a variavel do tipo MUX para entrar na seção critica*/
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

/*Função de Manipulação*/
void IRAM_ATTR interrupcao()
{
  portENTER_CRITICAL_ISR(&mux);
  sinal++;
  portEXIT_CRITICAL_ISR(&mux);
}

void setup() 
{
  pinMode(botao, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(botao), interrupcao, RISING);
  digitalWrite(Led, LOW);
}

void loop() 
{
  if(sinal>0)
  {
    portENTER_CRITICAL_ISR(&mux);
    sinal = 0;
    portEXIT_CRITICAL_ISR(&mux);
    digitalWrite(Led, HIGH);
    delay(2000);
    digitalWrite(Led, LOW);
  } 

}
