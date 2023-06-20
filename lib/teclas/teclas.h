#include <Arduino.h>

typedef enum {
    BU1_BU2,
    BU1_BD2,
    BD1_BU2,
    BD1_BD2,
    rebotes
}var_estado; 

typedef struct{
    int16_t push1;
    int16_t push2; 
    int16_t time1; 
    var_estado estado1_push;
} struct_actualizar;  

bool* inicializar_MEF(int16_t push1, int16_t push2,int16_t time2);
var_estado actualizar_MEF(struct_actualizar vstr_actualizar); 
bool buttonPressed(int16_t tecla); 
bool buttonReleased(int16_t tecla); 
