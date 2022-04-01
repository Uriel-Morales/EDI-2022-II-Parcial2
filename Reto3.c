#include <stdio.h>
#define MAX 3

void pedirarreglo(char arreglo[MAX]);
void imprimeArreglo(char arreglo[MAX]);
void busqueda(char arreglo[MAX]);
int main()
{
    char arreglo[MAX];
    pedirarreglo(arreglo);
    printf("arreglo:");
    imprimeArreglo(arreglo);
    printf("\nIngresa la letra a buscar:");
    busqueda(arreglo);
}
void pedirarreglo(char arreglo[MAX])
{
    int i;
    for(i=0;i < MAX;i++)
    {
        printf("Ingrese el elemento %d del arreglo\n",i);
        scanf("%c", &arreglo[i]);
        fflush(stdin);
    }
}
void imprimeArreglo(char arreglo[MAX]){

    printf("\n[");
    for(int i = 0; i < MAX; i++){
        printf(" %c ", arreglo[i]);
    }
    printf("]");
}void busqueda(char arreglo[MAX])
{
    int in=0;
    int sp=MAX;
    int mitad;
    char band='F';
    char obt;
    scanf("%c",&obt);
    printf("Elemento a buscar: %c\n",obt);
    while(in<=sp)
    {
        mitad=(in+sp)/2;
        if(obt<arreglo[in])
        {
            arreglo[mitad]=arreglo[0];
            band='V';
            break;
        }
        if(arreglo[mitad]==obt)
        {
            arreglo[mitad]=arreglo[mitad+1];
            band='V';
            break;
        }
        if(arreglo[mitad]>obt)
        {
            printf("El elemento esta en la parte inferior\n");
            sp=mitad;
            mitad=(in+sp)/2;
            if(arreglo[mitad]>obt)
            {
                arreglo[mitad]=arreglo[mitad+1];
                band='V';
                break;
            }
        }
        if(arreglo[mitad]<obt)
        {
            printf("El elemento esta en la parte superior\n");
            in=mitad;
            mitad=(in+sp)/2;
            if(arreglo[mitad]>obt && obt>arreglo[sp])
            {
                arreglo[mitad]=arreglo[mitad];
                band='V';
                break;
            }
        }
        if(arreglo[sp]<obt)
        {
            arreglo[mitad]=arreglo[0];
            band='V';
            break;
        }
    }
    if(band=='V')
    {
            printf("La letra es %c",arreglo[mitad]);
    }
}