#include <Arduino.h>
#include <teclas.h>
#include <uart.h>
bool flanco_push1 = false;  // Flanco descendente pulsante 1
bool flanco_push2 = false;  //Flanco descendente pulsante 2


bool buttonPressed(int16_t tecla){     // Funcion correspondientes al flanco descendente, pulsante se presiono
    static bool prev_state = true; 
    bool act_state = digitalRead(tecla);
    bool result = false;
    if (prev_state == true && act_state == false){
        result = true; 
    }
    else result = false;
    prev_state = act_state; 
    return result; 
}

bool buttonReleased(int16_t tecla){   // Funcion correspondientes al flanco ascendente, pulsante se libero
    static bool prev_state = true; 
    bool act_state = digitalRead(tecla);
    bool result = true;
    if (prev_state == false && act_state == true){
        result = true; 
    }
    else result = false;
    prev_state = act_state; 
    return result; 
}

bool* inicializar_MEF(int16_t push1, int16_t push2, int16_t time2){   //Funcion de inicialización
    static var_estado es = BU1_BU2; 
    struct_actualizar datos;
    bool* vector = (bool*)malloc(2*sizeof(bool));
    datos = {push1,push2,time2,es};
    es = actualizar_MEF(datos);
    if (flanco_push1) vector[0] = flanco_push1;
    else vector[0] = false;

    if (flanco_push2) vector[1] = flanco_push2; 
    else vector[1] = false;

    flanco_push1 = false; flanco_push2 = false;
    return vector;
}

var_estado actualizar_MEF(struct_actualizar vstr_actualizar){    // Función de actualizar e implementacion de MEF para antirebote con switch-case
    static int16_t time_pass = 0;
    static int16_t time_present = 0;
    static bool es_time = false; 
    static bool es_push1 = true; 
    static bool es_push2 = true;

    switch (vstr_actualizar.estado1_push){
    case BU1_BU2:
        printua(BU1_BU2_1,0); 
        if (buttonPressed(vstr_actualizar.push1) || buttonPressed(vstr_actualizar.push2)){
            es_push1 = false; 
            es_push2 = false;
            return rebotes;
        }
        else {
            es_push1 = true; 
            es_push2 = true; 
            return BU1_BU2; 
        }

        break;
    case BU1_BD2:
      
        printua(BU1_BD2_1,0); 
        if (buttonPressed(vstr_actualizar.push1) || buttonReleased(vstr_actualizar.push2)){
            es_push1 = false; 
            es_push2 = true;
            return rebotes;
        }
        else {
            es_push1 = true; 
            es_push2 = false; 
            return BU1_BD2; 
        }
        break;
    case BD1_BU2:
        
        printua(BD1_BU2_1,0); 
        if (buttonReleased(vstr_actualizar.push1) || buttonPressed(vstr_actualizar.push2)){
            es_push1 = true; 
            es_push2 = false;
            return rebotes;
        }
        else {
            es_push1 = false; 
            es_push2 = true; 
            return BD1_BU2; 
        }
        break;
    case BD1_BD2:
       
        printua(BD1_BD2_1,0);
        if (buttonReleased(vstr_actualizar.push1) || buttonReleased(vstr_actualizar.push2)){
            es_push1 = true; 
            es_push2 = true;
            return rebotes;
        }
        else {
            es_push1 = false; 
            es_push2 = false; 
            return BD1_BD2; 
        } 
        break;
    case rebotes:
        printua(rebote_1,0); 
        if (es_time == false) {time_pass = millis(); es_time = true;}
        time_present = millis();
        if (time_present-time_pass > vstr_actualizar.time1){
            es_time = false;
            bool es_act_push1, es_act_push2;
            
            if (es_push1 == digitalRead(vstr_actualizar.push1)) {
                if (es_push1 == false) flanco_push1 = true;
                es_act_push1 = es_push1;
            }
            else es_act_push1 = !es_push1;
            
            if (es_push2 == digitalRead(vstr_actualizar.push2)) {
                if (es_push2 == false) flanco_push2 = true;
                es_act_push2 = es_push2;
            }
            else es_act_push2 = !es_push2;

            if (es_act_push1 == false){
                if (es_act_push2 == false) return BD1_BD2;
                else return BD1_BU2;
            }
            else{
                if (es_act_push2 == false) return BU1_BD2;
                else return BU1_BU2;
            } 
        }
        else return rebotes;
        break;       
    default:
        printua(BU1_BU2_1,0); 
        es_push1 = true;
        es_push2 = true;
        return BU1_BU2; 
        break;
    }
}
