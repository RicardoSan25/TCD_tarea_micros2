#include <Arduino.h>

// Definición de estados con un tipo de dato enumerativo
typedef enum {
    BU1_BU2,
    BU1_BD2,
    BD1_BU2,
    BD1_BD2,
    rebotes
}var_estado; 

//Estructura con parámetros de pulsante 1 y 2 y ademas el estado de la MEF
typedef struct{
    int16_t push1;
    int16_t push2; 
    int16_t time1; 
    var_estado estado1_push;
} struct_actualizar;  

bool* inicializar_MEF(int16_t push1, int16_t push2,int16_t time2);  //Iniciar MEF
var_estado actualizar_MEF(struct_actualizar vstr_actualizar);       // Actualizar MEF
bool buttonPressed(int16_t tecla);                                 // Acciones correspondientes al flanco DESCENDENTE, se presiono pulsante
bool buttonReleased(int16_t tecla);                                // Acciones correspondientes al flanco ASCENDENTE, se libero pulsante
