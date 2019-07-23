/* Gere um número aleatório de 1 a 10 a cada 2 segundos e decida se o LED vai estar ligado (> que 5)
ou desligado (< que 5) plotando na tela do terminal, o valor obtido e a decisão tomada. */

#define LED 2
#define BOTAO 4

void setup() 
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);
}

void loop() 
{
  int min = 0;
  int max = 10;
  int aleatorio = random(min,max);
  String ligado = "O led está ligado, o numero é: ";
  String desligado = "O led está desligado, o numero é: ";
  if(aleatorio >5)
  {
    digitalWrite(LED, HIGH);
    Serial.println(ligado + aleatorio);
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println(desligado + aleatorio);
  } 
  delay(2000);  
}
