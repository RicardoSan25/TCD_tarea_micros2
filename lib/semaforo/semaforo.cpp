#include <Arduino.h>
#include <semaforo.h>
#include <uart.h>
float tiempos[] = {2,1,0.5};
float rapidez = 0; 
bool tiempo_demora(int16_t time_1){
    static bool es = true;
    static unsigned long tiempo_anterior = 0; 
    static unsigned long tiempo_actual = 0; 
    bool res = false; 
    
    if (es == true){es = false; tiempo_anterior = millis();}
    tiempo_actual = millis();

    if (tiempo_actual-tiempo_anterior > (unsigned long)time_1){res = true; es = true;} 
    else {res = false; es=false;}
    return res; 
}

void inicializar_MEF_semaforo(bool push1, bool push2, int16_t led_green, int16_t led_yellow, int16_t led_red){
    static int16_t pos_tiempos = 0; 
    static estados state1 = nverde;
    struct_var datos; 
    datos = {push1,led_green,led_yellow,led_red,state1};
    if (push2) pos_tiempos=(pos_tiempos+1)%3;
    rapidez = tiempos[pos_tiempos]; 
    state1 = actualizar_MEF_semaforo(datos); 
}
estados actualizar_MEF_semaforo(struct_var vstr_actualizar){
    estados estado1_push;
    switch (vstr_actualizar.es){
    case nverde:
        if (vstr_actualizar.push1) estado1_push = des_ama; 
        else{
            if (tiempo_demora((int16_t)(3000*rapidez))) estado1_push = nver_ama; 
            else estado1_push = nverde;
        } 
        digitalWrite(vstr_actualizar.led_green,HIGH);
        digitalWrite(vstr_actualizar.led_yellow,LOW);
        digitalWrite(vstr_actualizar.led_red,LOW);
        printua(nverde1,rapidez);
        break;
    case nver_ama: 
        if (vstr_actualizar.push1) estado1_push = des_ama; 
        else{
            if (tiempo_demora((int16_t)(500*rapidez))) estado1_push = nrojo; 
            else estado1_push = nver_ama;
        } 
        digitalWrite(vstr_actualizar.led_green,HIGH);
        digitalWrite(vstr_actualizar.led_yellow,HIGH);
        digitalWrite(vstr_actualizar.led_red,LOW);
        printua(nver_ama1,rapidez);
        break;
    case nrojo: 
        if (vstr_actualizar.push1) estado1_push = des_ama; 
        else{
            if (tiempo_demora((int16_t)(2000*rapidez))) estado1_push = nverde; 
            else estado1_push = nrojo;
        } 
        digitalWrite(vstr_actualizar.led_green,LOW);
        digitalWrite(vstr_actualizar.led_yellow,LOW);
        digitalWrite(vstr_actualizar.led_red,HIGH);
        printua(nrojo1,rapidez);
        break;
    case des_ama: 
        if (vstr_actualizar.push1) estado1_push = alar_rojo; 
        else{
            if (tiempo_demora((int16_t)(500*rapidez))) estado1_push = des_cero; 
            else estado1_push = des_ama;
        } 
        digitalWrite(vstr_actualizar.led_green,LOW);
        digitalWrite(vstr_actualizar.led_yellow,HIGH);
        digitalWrite(vstr_actualizar.led_red,LOW);
        printua(des_ama1,rapidez);
        break;
    case des_cero: 
        if (vstr_actualizar.push1) estado1_push = alar_rojo; 
        else{
            if (tiempo_demora((int16_t)(500*rapidez))) estado1_push = des_ama; 
            else estado1_push = des_cero;
        } 
        digitalWrite(vstr_actualizar.led_green,LOW);
        digitalWrite(vstr_actualizar.led_yellow,LOW);
        digitalWrite(vstr_actualizar.led_red,LOW);
        printua(des_cero1,rapidez);
        break;
    case alar_rojo: 
        if (vstr_actualizar.push1) estado1_push = nverde; 
        else{
            if (tiempo_demora((int16_t)(500*rapidez))) estado1_push = alar_cero; 
            else estado1_push = alar_rojo;
        } 
        digitalWrite(vstr_actualizar.led_green,LOW);
        digitalWrite(vstr_actualizar.led_yellow,LOW);
        digitalWrite(vstr_actualizar.led_red,HIGH);
        printua(alar_rojo1,rapidez);
        break;
    case alar_cero:
        if (vstr_actualizar.push1) estado1_push = nverde; 
        else{
            if (tiempo_demora((int16_t)(500*rapidez))) estado1_push = alar_rojo; 
            else estado1_push = alar_cero;
        } 
        digitalWrite(vstr_actualizar.led_green,LOW);
        digitalWrite(vstr_actualizar.led_yellow,LOW);
        digitalWrite(vstr_actualizar.led_red,LOW);
        printua(alar_cero1,rapidez);
        break;
    default:
        estado1_push = nverde;
        digitalWrite(vstr_actualizar.led_green,HIGH);
        digitalWrite(vstr_actualizar.led_yellow,LOW);
        digitalWrite(vstr_actualizar.led_red,LOW);
        break;
    }
    return estado1_push;
}