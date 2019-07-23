/*Criar um algoritmo que ao pressionar um botão, o LED acende, ao deixar de pressiona-lo o LED apaga.
  Mostrando quando o LED está desligado e quando ele está ligado no terminal do arduino. */
  
#define LED 2
#define BOTAO 4

String Ligado = "O led está ligado";
String Desligado = "O led está desligado";

void setup() 
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);
}

void loop() 
{
  if(digitalRead(BOTAO) == HIGH)
  {
    digitalWrite(LED, HIGH);
    Serial.println(Ligado);
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println(Desligado);
  } 
  delay(2000);  
}
