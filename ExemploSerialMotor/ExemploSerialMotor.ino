#define LED 5 // Define o pino analógico em que o potenciômetro vai ser conectado
char rxChar= 0; // RXcHAR holds the received command.

//#define led1Pin 6 // Define o pino que terá um LED e um resistência ligada ao terra
//#define led2Pin 5 // Define o pino que terá um LED e um resistência ligada ao terra
int valAnalog = 0; //Variável que armazena o valor da leitura do potenciômetro 
int valAnalogInvertido = 255; //Variável que armazena o valor da leitura do potenciômetro 

//Funcao com menu
void printMenu(){
  Serial.println("--- Serial Monitor ---");
  Serial.println("a -> Ligar o LED");
  Serial.println("d -> Desligar o LED");
  Serial.println("s -> Status do LED");
 }

void setup() {
  Serial.begin(9600); // Open serial port (9600 bauds).
  pinMode(LED, OUTPUT); // Sets pin 13 as OUTPUT.
  Serial.flush(); // Clear receive buffer.
  printMenu(); // Print the command list.
}

void loop() {
  /*
  int valPot = analogRead(potPin); //Faz a leitura analógica do pino em que o potenciômetro esta ligado
  valAnalog = map(valPot,0,1023,0,255); //Utilizando a função map() para transformar uma escala de 0-1023 em uma escala 0 a 255
  valAnalogInvertido = map(valPot,0,1023,255,0); //Utilizando a função map() para transformar uma escala de 0-1023 em uma escala 0 a 255
  analogWrite(led1Pin,valAnalog ); // Aciona o LED proporcionalmente ao valor da leitura analógica
  analogWrite(led2Pin,valAnalogInvertido); // Aciona o LED proporcionalmente ao valor da leitura analógica
  */
  if (Serial.available() >0){ // Verifica se recebeu alguma coisa no buffer
    rxChar = Serial.read(); // Salva o caracter lido
    Serial.flush(); // Limpa o buffer

    switch (rxChar) {
      case 'a':
      case 'A':
        if (digitalRead(LED) == LOW){
          digitalWrite(LED,HIGH);
          Serial.println("LED Ligado");
        } else
          Serial.println("LED ja esta ligado");
          break;
        case 'd':
        case 'D':
          if (digitalRead(LED) == HIGH){
            digitalWrite(LED,LOW);
            Serial.println("LED desligado");
          }
          else Serial.println("LED ja esta desligado");
          break;
        case 's':
        case 'S':
          if (digitalRead(LED) == HIGH) 
            Serial.println("LED status: Ligado");
          else
            Serial.println("LED status: Desligado");
            break;
        default:
          Serial.print("'");
          Serial.print((char)rxChar);
          Serial.println("' nao eh um comando valido!");
      }
    }
  }
