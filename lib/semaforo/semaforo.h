#include <Arduino.h>

typedef enum{
    nverde, 
    nver_ama,
    nrojo,
    des_ama,
    des_cero,
    alar_rojo, 
    alar_cero
}estados;

typedef struct {
    bool push1; 
    int16_t led_green;
    int16_t led_yellow;
    int16_t led_red;
    estados es; 
} struct_var;

void inicializar_MEF_semaforo(bool push1, bool push2, int16_t led_green, int16_t led_yellow, int16_t led_red);
estados actualizar_MEF_semaforo(struct_var vstr_actualizar);
bool tiempo_demora(int16_t time_1);