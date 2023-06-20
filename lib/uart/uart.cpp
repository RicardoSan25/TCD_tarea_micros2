#include <Arduino.h>
#include <uart.h>


void printua(varstr var1,float speed){
    static varstr alm1 = BD1_BU2_1; 
    static int16_t alm2 = 1;
    static float alm_velcidad = 2; 
    int16_t test1 = 1; 
    

    if (speed != 0) {
        if (alm_velcidad != speed){
            test1 = 3; 
        }
        else if (var1 == nrojo1 ||var1 == nverde1 || var1 == nver_ama1){
            test1 = 0; 
        }
        else if (var1 == des_ama1 || var1 == des_cero1){
            test1 = 1; 
        }
        else {
            test1 = 2;
        }
    }
    else test1 = alm2; 

    
    if ((alm1 != var1 && (var1 == BU1_BU2_1 ||var1 == BU1_BD2_1 || var1 == BD1_BD2_1 || var1 == BD1_BU2_1 || var1 == rebote_1)) ||  alm2 != test1){
        switch (var1){
        case BU1_BU2_1:
            Serial.println("push1: OFF");
            Serial.println("push2: OFF"); 
            break;
        case BD1_BU2_1:
            Serial.println("push1: ON");
            Serial.println("push2: OFF"); 
            break;
        case BU1_BD2_1:
            Serial.println("push1: OFF");
            Serial.println("push2: ON"); 
            break;
        case BD1_BD2_1:
            Serial.println("push1: ON");
            Serial.println("push2: ON"); 
            break;
        case rebote_1: 
            Serial.println("Estado: Rebounds"); 
            break;
        case nverde1: 
            Serial.print("Modo: Normal "); 
            Serial.print("speed: X");
            Serial.println(speed); 
            break;
        case nver_ama1: 
            Serial.print("Modo: Normal "); 
            Serial.print("speed: X");
            Serial.println(speed); 
            break;
        case nrojo1: 
            Serial.print("Modo: Normal "); 
            Serial.print("speed: X");
            Serial.println(speed); 
            break;
        case des_ama1: 
            Serial.print("Modo: Desconectado "); 
            Serial.print("speed: X");
            Serial.println(speed); 
            break;
        case des_cero1: 
            Serial.print("Modo: Desconectado "); 
            Serial.print("speed: X");
            Serial.println(speed); 
            break;
        case alar_rojo1: 
            Serial.print("Modo: Alarma "); 
            Serial.print("speed: X");
            Serial.println(speed); 
            break;
        case alar_cero1: 
            Serial.print("Modo: Alarma "); 
            Serial.print("speed: X");
            Serial.println(speed); 
            break;
        default:
            Serial.println(" "); 
            break;
        }
    Serial.println("*******************************************************");
    }
    if (var1 == BU1_BU2_1 || var1 == BD1_BU2_1 || var1 == BU1_BD2_1 || var1 == BD1_BD2_1 || var1 == rebote_1) {
        alm1 = var1;
    }
    else {alm2 = test1; alm_velcidad = speed;}    
    
}