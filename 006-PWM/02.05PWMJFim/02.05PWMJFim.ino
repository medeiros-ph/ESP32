/* Criar um algoritmo que alterne as potências de 25, 50, 75 e 100 a cada 2 segundos para uma resolução de 128. */
/*Use a resolução de 7bits = de 0 a 127*/

#define LED 2

int freq = 5000; //5MHz
int ledChannel = 0;
int resolution = 7;
 
void setup()
{
  //Configura um canal para trabalhar a uma determinada frequência e resolução
  //Canal: 0-15
  //Frequência: 1 a 40 MHz
  //Resolução: 1-16 Bits
  ledcSetup(ledChannel, freq, resolution);
  //Essa função apenas atribui um pino a um canal. 16 canais possíveis
  ledcAttachPin(LED, ledChannel);
 
}
 
void loop() 
{
  
  ledcWrite(ledChannel,25);
  delay(2000); 
  ledcWrite(ledChannel,50); 
  delay(2000);
  ledcWrite(ledChannel,75); 
  delay(2000);
  ledcWrite(ledChannel,100); 
  delay(2000);
}
