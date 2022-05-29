#include <stdio.h>
#include <string.h>
#include "pila.h"
#include "cola.h"

#define CIRCLE_SANDWICH 0
#define SQUARE_SANDWICH 1

void sell_sandwich(Cola *c, Stack1 *stack2);
int imprimir_pila(Stack1 stack2);
int imprimir_cola(Cola cola);
int main(){

    Stack1 stack2;
    Cola cola;
    Estudiante2 estudiante2;

    inicializacion(&cola);
    setup(&stack2);

    push(&stack2, CIRCLE_SANDWICH);
    push(&stack2, SQUARE_SANDWICH);
    push(&stack2, CIRCLE_SANDWICH);
    push(&stack2, SQUARE_SANDWICH);
    push(&stack2, CIRCLE_SANDWICH);
    push(&stack2, SQUARE_SANDWICH);
    strcpy(estudiante2.nombres, "Andres");
    estudiante2.sandwich=CIRCLE_SANDWICH;
    insertar(&cola, estudiante2);
    strcpy(estudiante2.nombres, "Martin");
    estudiante2.sandwich=CIRCLE_SANDWICH;
    insertar(&cola, estudiante2);
    strcpy(estudiante2.nombres, "Dulce");
    estudiante2.sandwich=SQUARE_SANDWICH;
    insertar(&cola, estudiante2);
    strcpy(estudiante2.nombres, "Iliana");
    estudiante2.sandwich=CIRCLE_SANDWICH;
    insertar(&cola, estudiante2);
    strcpy(estudiante2.nombres, "Jose");
    estudiante2.sandwich=SQUARE_SANDWICH;
    insertar(&cola, estudiante2);
    strcpy(estudiante2.nombres, "Sebastian");
    estudiante2.sandwich=SQUARE_SANDWICH;
    insertar(&cola, estudiante2);
    printf("\nOrden de sandwich:  ");
    imprimir_pila(stack2);
    printf("\nEstudiantes:  ");
    imprimir_cola(cola);
    printf("\n");
    sell_sandwich(&cola, &stack2);
    return 0;
}
void sell_sandwich(Cola *c, Stack1 *s){
    Estudiante2 estudianteActual;
    int sandwichActual;

    while (estaVacia(*c)==0) {
        eliminar(c, &estudianteActual);
        pop(s, &sandwichActual);

        printf("\n%s quiere sandwich %d y en la pila hay %d", estudianteActual.nombres, estudianteActual.sandwich, sandwichActual);

        if (estudianteActual.sandwich!=sandwichActual) {
            printf("  No se entrego, estudiante pasa al final de la cola ");
            insertar(c, estudianteActual);
            push(s, sandwichActual);
        }
        else{
            printf("  El sandwich se entrego");
        }}}
int imprimir_pila(Stack1 stack2){

    for (int i = 0; i < MAX; ++i) {
        printf("%d  ",stack2.data[i]);
    }}
int imprimir_cola(Cola cola){
    for (int i = 0; i < MAX; ++i) {
        printf("%s  ",cola.datos[i]);
    }}