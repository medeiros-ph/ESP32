/*Criar um algoritmo que tenha um LED definido como ligado.*/

#define LED 2
#define BOTAO 4
void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);
}

void loop() 
{
  if(digitalRead(BOTAO) == 1){digitalWrite(LED, HIGH);}
  else{digitalWrite(LED, LOW);}

  
  
}
