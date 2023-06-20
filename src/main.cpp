// Decalracion de Librerias
#include <Arduino.h>
#include <teclas.h>
#include <semaforo.h>
// ****************************** Inputs/Outputs ******************************************
const uint8_t push1 = 2;              // Pulsante 1
const uint8_t push2 = 3;             // Pulsante 2
const uint8_t led_green= 5;         // Led verde
const uint8_t led_yellow= 6;        // led amarillo
const uint8_t led_red = 7;          //Led rojo


//**************************** Configuration Loop ********************************************
void setup() {
  pinMode(push1,INPUT);   // Configura los pines como entradas en los pulsantes 1 y 2
  pinMode(push2,INPUT);
  pinMode(led_green,OUTPUT); // Configura los pines como salidas en los leds
  pinMode(led_yellow,OUTPUT); 
  digitalWrite(led_green,false);
  digitalWrite(led_yellow,false);
  Serial.begin(115200);
}
void loop() {
  bool* resultado = inicializar_MEF(push1, push2,40);      //Funcion de inializacion
  inicializar_MEF_semaforo(resultado[0], resultado[1], led_green, led_yellow, led_red);  // Inicializacion de semaforo
  free(resultado); 
}