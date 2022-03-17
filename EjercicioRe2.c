#include <stdio.h>
int fibonacci(int num, int i, int x, int y, int z);
int main()
{
    int num;
    int resultado;
    int i=1;
    printf("Numero de elementos:\n");
    scanf_s("%d", &num);
        if(num!=0){
            resultado=fibonacci(num, i, 0, 1, 1);
            printf("El valor es: %d",resultado);}
        else
            printf("El valor es: 0");
}
int fibonacci(int num, int i, int x, int y, int z)
{
    if(i<num){
        z=x+y;
        x=y;
        y=z;
        return fibonacci(num, i+1, x, y, z);}
    return z;
}