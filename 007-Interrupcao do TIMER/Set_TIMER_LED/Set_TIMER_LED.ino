#define LED 2

/*Variável da Interrupção*/
volatile int Interrupcao;

/*Ponteiro de tipo TIMER*/
hw_timer_t*timer = NULL;

/*Criar a variavel do timpo MUX para seção critica*/
portMUX_TYPE timerMUX = portMUX_INITIALIZER_UNLOCKED;

/*Criar a fç de manipulaçao*/

void IRAM_ATTR onTimer()
{
  /*Entrar na secao critica, adicionar 1 a variavel da interrupcao e fechar a secao critica*/  
  portENTER_CRITICAL_ISR(&timerMUX);
  Interrupcao++;
  portEXIT_CRITICAL_ISR(&timerMUX);
}
void setup() 
{
  Serial.begin(115200);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000000, true);
  timerAlarmEnable(timer);

  pinMode(LED, OUTPUT);
}

void loop() 
{
  if(Interrupcao > 0)
  {
    /*Entrar na secao critica, zerar a variavel de interrupcao e fechar a secao critica*/
    portENTER_CRITICAL(&timerMUX);
    Interrupcao = 0;
    portEXIT_CRITICAL(&timerMUX);

    if(digitalRead(LED) == HIGH)
    {
      digitalWrite(LED, LOW);  
    }
    else
    {
      digitalWrite(LED, HIGH);
    }
  }

}
