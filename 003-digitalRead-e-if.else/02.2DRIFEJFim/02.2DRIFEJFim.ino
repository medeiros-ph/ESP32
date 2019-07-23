/*Criar um algoritmo que ao pressionar um botão, o LED acende, ao deixar de pressiona-lo o LED apaga.*/
#define LED 2
#define BOTAO 4

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);
}

void loop() 
{
  if(digitalRead(BOTAO) == HIGH)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  } 
  
}
