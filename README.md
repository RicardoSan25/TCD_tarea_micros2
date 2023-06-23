# TCD_tarea_micros2
Trabajo de micros 2,Implementar mediante el modelo de Máquina de Estados Finitos (MEF) el antirrebote de teclas y la lógica de funcionamiento de un semáforo.

# Máquina de estado del semáforo
  Vamos a tener tres modos normales de estado identificados por los colores que predominan en un semáforo [verde, amarillo, rojo], donde vemos que podemos pasar un estado a otro, usando el desplazamiento en tiempo y la solución de un pulsante no bloqueante.
  # Debe cumplir con lo siguiente modos de operación
La secuencia normal con la secuencia de Leds, donde si esta en verde un T=3s, pasa amarillo a un T=500mseg para pasar a rojo a un T=2seg, y luego repite esta secuencia nuevamente. hasta que ingresemos alguna acción que la generara los pulsantes no bloqueantes.
El modo desconexión que permite la intermitencia del Led amarillo por un T=500mseg.
El modo alarma esto podemos indicar que estara en modo intermiente el Led rojo por un T=1seg.
Todo estos procesos nos permitira entender como funciona un semáforo inteligente como el que contamos en la unviersidad central para llegar a la AV. Tarqui.

Tambien contamos con los dos pulsadores deben ser capaz de cambiar el tiempo de condición para cada operación normal de la siguiente manera [0.5x, 1x, 2x].

Ahora tambein podemos contar con que las dos teclas debe permitir cambiar el modo de operación del mismo semáforo a normal, que vamos siempre al modo de operación anterior, verificando los flancos ascendentens vamos a tener el siguiente modo de operación [normal, desconectado, alarma , normal, se repite].
# Máquina de estado de teclas
