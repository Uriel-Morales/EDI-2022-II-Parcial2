#include <stdio.h>
#include "capacidad.h"
typedef struct {
    int data[MAX];
    int top;
} Stack1;

void setup(Stack1 *s){
    s->top=-1;
}
int isEmpty(Stack1 stack2){
    if (stack2.top==-1)
        return 1;
    return 0;
}
int isFull(Stack1 stack2){
    if (stack2.top== MAX-1)
        return 1;
    return 0;
}
int push(Stack1 *s, int value){
    int r=0;
    if (isFull(*s)==0){
        s->top++;
        s->data[s->top]=value;
        r=1;
    }
    return r;
}
int pop (Stack1 *s, int *v){
    if (!isEmpty(*s)){
        *v= s->data[s->top];
        s->top--;
        return 1;
    }
    return 0;
}

int imprimir(Stack1 stack2){

    for (int i = 0; i < MAX; ++i) {
        printf("%d\n",stack2.data[i]);
    }
}