#define potPin 0 // Define o pino analógico em que o potenciômetro vai ser conectado
#define led1Pin 6 // Define o pino que terá um LED e um resistência ligada ao terra
#define led2Pin 5 // Define o pino que terá um LED e um resistência ligada ao terra
int valAnalog = 0; //Variável que armazena o valor da leitura do potenciômetro 
int valAnalogInvertido = 255; //Variável que armazena o valor da leitura do potenciômetro 


void setup() {
  // put your setup code here, to run once:
  pinMode(led1Pin,OUTPUT); // Configura o pino do LED como saída 
  pinMode(led2Pin,OUTPUT); // Configura o pino do LED como saída 
}

void loop() {
  int valPot = analogRead(potPin); //Faz a leitura analógica do pino em que o potenciômetro esta ligado
  valAnalog = map(valPot,0,1023,0,255); //Utilizando a função map() para transformar uma escala de 0-1023 em uma escala 0 a 255
  valAnalogInvertido = map(valPot,0,1023,255,0); //Utilizando a função map() para transformar uma escala de 0-1023 em uma escala 0 a 255
  analogWrite(led1Pin,valAnalog ); // Aciona o LED proporcionalmente ao valor da leitura analógica
  analogWrite(led2Pin,valAnalogInvertido); // Aciona o LED proporcionalmente ao valor da leitura analógica
}
