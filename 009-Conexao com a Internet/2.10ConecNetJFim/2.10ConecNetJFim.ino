/* Conectar o WiFi a Internet */
#include <WiFi.h>

//Crie duas variaveis, uma para o nome da sua internet, e outra para a respectiva senha
const char* usuario = "FERREIRA";
const char* senha =  "lu030468";
 
void setup() 
{
  //Inicialize a serial em 11520 de BaudRate
  Serial.begin(115200);
  
  //Inicializa a conexão com a internet com a rede e a senha
  WiFi.begin(usuario, senha);

  //Enquanto o status do WIFI for diferente de conectado, escreva na serial "Conectando ao WIFI..."
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Conectando ao WIFI..");
  }

  //Escreva na serial que o WIFI está conectado
  Serial.println("Conectado ao WiFi");
 
}
 
void loop() 
{
 
}
