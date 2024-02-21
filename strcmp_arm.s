.global strcmp_arm
strcmp_arm:
    PUSH {r4, r5, lr}          @ Guarda r4, r5 y lr en la pila

    MOV r4, r0                 @ Guarda el primer parámetro (puntero a la cadena 1) en r4
    MOV r5, r1                 @ Guarda el segundo parámetro (puntero a la cadena 2) en r5

loop:
    LDRB r0, [r4], #1          @ Carga el byte actual de la cadena 1 y avanza el puntero
    LDRB r1, [r5], #1          @ Carga el byte actual de la cadena 2 y avanza el puntero

    CMP r0, #0                 @ Compara si el byte cargado de la cadena 1 es nulo
    BEQ check_end              @ Si es nulo, salta a la comprobación final

    CMP r0, r1                 @ Compara los bytes cargados de ambas cadenas
    BNE not_equal              @ Si no son iguales, salta a la etiqueta not_equal

    B loop                     @ Si son iguales, continúa en el bucle

not_equal:
    SUBS r0, r0, r1            @ Resta los bytes para calcular la diferencia
    POP {r4, r5, pc}           @ Restaura r4, r5 y pc y retorna con el resultado

check_end:
    CMP r1, #0                 @ Comprueba si el byte cargado de la cadena 2 es nulo
    POP {r4, r5, pc}           @ Si es así, retorna 0
    MOVEQ r0, #0
    MOVNE r0, r1               @ Si no es nulo, retorna la diferencia entre el byte y 0

    POP {r4, r5, pc}           @ Restaura r4, r5 y pc y retorna con el resultado
