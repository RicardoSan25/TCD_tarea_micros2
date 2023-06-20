#include <Arduino.h>

typedef enum {
    BU1_BU2_1,
    BU1_BD2_1,
    BD1_BU2_1,
    BD1_BD2_1,
    rebote_1,
    nverde1, 
    nver_ama1,
    nrojo1,
    des_ama1,
    des_cero1,
    alar_rojo1, 
    alar_cero1
} varstr;

void printua(varstr var1, float speed);

