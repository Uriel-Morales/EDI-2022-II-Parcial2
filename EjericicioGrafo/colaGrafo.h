#include <stdio.h>
#include <string.h>
#define capacidad 100

typedef struct cola{
    char datos[capacidad+1][50];
    int inicio;
    int fin;
}Cola;

void inicializacion(Cola *c)
{
    c->inicio=0;
    c->fin=0;
}

int estaVacia(Cola cola)
{
    int r=0;
    if(cola.inicio==cola.fin)
        r=1;
    return r;
}
int estaLlena(Cola cola)
{
    if(cola.fin == cola.inicio-1 || (cola.inicio==0 && cola.fin == capacidad))
        return 1;
    return 0;
}

int insertar(Cola *c, char valor[50])
{
    int r=0;
    if(estaLlena(*c)==0)
    {
        strcpy(c->datos[c->fin], valor);
        c->fin++;
        if(c->fin == capacidad+1)
            c->fin=0;
        r=1;
    }
    return r;
}
int eliminar(Cola *c, char valor[50])
{
    int r=0;
    if(!estaVacia(*c))
    {
        strcpy(valor, c->datos[c->inicio]);
        c->inicio=(c->inicio+1)%(capacidad+1);
        r=1;
    }
    return r;
}