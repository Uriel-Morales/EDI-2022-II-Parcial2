#include <stdio.h>
int main() {
    int arreglo[4];
    int i,Num,Ban=0;
    for (i=0;i<4;i++)
    {
        printf("Introduce el elemento %d \n",i);
        scanf("%d",&arreglo[i]);
    }
    printf("numero a buscar: \n" );
    scanf("%d",&Num);
    for (i=0;i<4;i++)
    {
        if (Num==arreglo[i])
        {
            Ban=1;
            printf("El numero esta en la posicion %d",i);
            break;
        }
        else
        {
            Ban=0;
        }
    }
    if (Ban==0)
    {
        for(i=0;i<4;i++)
        {
            if(Num<arreglo[i])
            {
                printf("El numero estaria en la posicion %d",i);
                break;
            }
            if(Num>arreglo[i] && Num<arreglo[i+1])
            {
                printf("El numero estaria en la posicion %d",i+1);
                break;
            }
        }
    }
    return 0;
}