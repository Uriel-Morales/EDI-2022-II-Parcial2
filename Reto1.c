#include <stdio.h>
#define MAX 5
void pedirarreglo(int arreglo[MAX]);
void imprimirarreglo(int arreglo[MAX]);
void productos(int arreglo[MAX], int respuesta[MAX]);
int main()
{
    int arreglo[MAX];
    int respuesta[MAX];
    pedirarreglo(arreglo);
    imprimirarreglo(arreglo);
    productos(arreglo,respuesta);
    imprimirarreglo(respuesta);
}
void pedirarreglo(int arreglo[MAX])
{
    int i;
    for(i=0;i < MAX;i++)
    {
        printf("Ingrese el elemento %d del arreglo\n",i);
        scanf("%d", &arreglo[i]);
    }
}
void imprimirarreglo(int arreglo[MAX])
{
    int i;
    printf("\n[");
    for(i = 0; i < MAX; i++)
    {
        printf(" %d ", arreglo[i]);
    }
    printf("]");
}
void productos(int arreglo[MAX], int respuesta[MAX])
{
    int i,j;
    for(j=0;j<MAX;j++)
    {
        respuesta[j]=1;
    }
    for(j=0; j < MAX; j++)
    {
        for(i=0; i < MAX; i++)
        {
            if(i==j)
            {
                i++;
            }
            if(i>=MAX)
            {
                break;
            }
            respuesta[j]= respuesta[j]*arreglo[i];
        }
    }
}