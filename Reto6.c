#include <stdio.h>
#define MAX 6
typedef struct cola{
    int datos[MAX+1];
    int inicio;
    int fin;
}Cola;
void inicializaCola(Cola *c);
int estaVacia(Cola cola);
int estaLlena(Cola cola);
int insertar(Cola *c, int valor);
int eliminar(Cola *c, int *v);
int main(){
    int r;
    Cola cola;
    int valor;
    int k=5;
    inicializaCola(&cola);
    r = insertar(&cola, 1);
    r = insertar(&cola, 2);
    r = insertar(&cola, 3);
    r = insertar(&cola, 4);
    r = insertar(&cola, 5);
    r = insertar(&cola, 6);
    if(r==1)
        printf("Datos ingresados");
    for(int i = 0; i<=k; i++)
    {
        r= eliminar(&cola, &valor);
        if(i!=k)
            insertar(&cola, valor);
    }
    printf("\nEl ganador es: %d", valor);
    return 0;
}
int eliminar(Cola *c, int *v){
    int r=0;
    if(!estaVacia(*c)){
        *v = c->datos[c->inicio];
        c->inicio = (c->inicio+1) % (MAX + 1);
        r=1;
    }
    return r;
}
int estaVacia(Cola cola){
    int r=0;
    if(cola.inicio==cola.fin)
        r=1;
    return r;
}
int insertar(Cola *c, int valor){
    int r=0;
    if(estaLlena(*c)==0){
        c->datos[c->fin] = valor;
        c->fin++;

        if(c->fin == MAX+1)
            c->fin = 0;
        r=1;
    }
    return r;
}
int estaLlena(Cola cola){
    if(cola.fin == cola.inicio-1 || (cola.inicio == 0 && cola.fin ==MAX))
        return 1;
    return 0;
}
void inicializaCola(Cola *c){
    c->inicio=0;
    c->fin=0;
}