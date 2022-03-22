#include <stdio.h>
#define MAX 4
#define NUM 10
void solicitarnombres(char arreglo[MAX][NUM]);
int busqueda(char arreglo[MAX][NUM], char *nombre);
int main()
{
    char arreglo[MAX][NUM];
    char nombre;
    int resultado;
    solicitarnombres(&arreglo[MAX]);
    printf("\n");
    resultado = busqueda(&arreglo[MAX], &nombre);
    printf("\n");
    printf("La ubicacion es %d",resultado);

}

void solicitarnombres(char arreglo[MAX][NUM])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("Ingresa el nombre %d:\n",i);
        scanf("%s",&arreglo[i][NUM]);
    }
    printf("[");
    for(i=0;i<=MAX;i++)
    {
        printf("%s ", arreglo[i]);
    }
    printf("]");
}

int busqueda(char arreglo[MAX][NUM], char *nombre)
{
    int i;
    printf("Nombre a buscar:\n");
    scanf("%s",nombre);
    printf("%s\n", nombre);
    for(i=1;i<=MAX;i++)
    {
        printf("Evaluado %s  con  %s\n",nombre, arreglo[i]);
        if(nombre==arreglo[i])
        {
            i=i;
        }
    }
    return i;
}