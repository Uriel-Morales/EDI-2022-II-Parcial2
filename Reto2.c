#include <stdio.h>
void hex(int n);
int main()
{
    int valor;
    printf("Ingrese el valor en decimal:\n");
    scanf("%d",&valor);
    hex(valor);
    return 0;
}
void hex(int n)
{
    int i = n % 16;
    char c;
    switch (i)
    {
        case 0: c='0';break;
        case 1: c='1';break;
        case 2: c='2';break;
        case 3: c='3';break;
        case 4: c='4';break;
        case 5: c='5';break;
        case 6: c='6';break;
        case 7: c='7';break;
        case 8: c='8';break;
        case 9: c='9';break;
        case 10: c='A';break;
        case 11: c='B';break;
        case 12: c='C';break;
        case 13: c='D';break;
        case 14: c='E';break;
        case 15: c='F';break;
    }
    if(n>0)
    {
        hex(n / 16);
        printf("%c",c);
    }
}