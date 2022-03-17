#include <stdio.h>
#include <string.h>
#define MAX 30
int palindromociclo(char cadena[MAX],int n);
int palindromorecursivo(char cadena[MAX], int inicio, int fin);
int main()
{
    char cadena[MAX];
    int n;
    int resultadociclo;
    int resultadorecursivo;
    printf("Cadena:\n");
    gets(cadena);
    n= strlen(cadena);
    printf("La cadena es %s\n", cadena);
    resultadociclo=palindromociclo(cadena, n);
    printf(" -----ciclico-----\n");
    if(resultadociclo==1)
        printf("Evaluado de forma ciclica: es palindroma");
    else
        printf("Evaluado de forma ciclica: no es palindroma");
    printf("\n -----Recursivo-----\n");
    resultadorecursivo = palindromorecursivo(cadena, 0, n - 1);
    if (resultadorecursivo==1) {
        printf("Evaluado de forma recursiva: es palindroma");
    } else {
        printf("Evaluado de forma recursiva: no es palindroma");
    }
}

int palindromociclo(char cadena[MAX], int n)
{
    int i;
    int c=1;
    int m=n-1;
    for(i=0;i<n/2;i++)
    {
        if(cadena[i]==' ' && cadena[m]!=' ')
        {
            i++;
            if(cadena[i]!=cadena[m])
                c++;
        }
        if(cadena[m]==' ' && cadena[i]!=' ')
        {
            m--;
            if(cadena[i]!=cadena[m])
                c++;
        }
        if(cadena[i]!=cadena[m])
        {
            c++;
        }
        m--;
    }
    return c;
}
int palindromorecursivo(char cadena[MAX], int inicio, int fin) {

    if (inicio >= fin)
    {
        if(cadena[inicio]==' ' && cadena[fin]!=' ')
        {
            inicio++;
            if(cadena[inicio]!=cadena[fin])
                return 0;
        }
        if(cadena[fin]==' ' && cadena[inicio]!=' ')
        {
            fin--;
            if(cadena[inicio]!=cadena[fin])
                return 0;
        }
        if(cadena[inicio]!=cadena[fin])
        {
            return 0;
        }
        return 1;
    }
    if (cadena[inicio] == cadena[fin])
    {
        return palindromorecursivo(cadena, inicio + 1, fin - 1);
    }
    else
    {
        return 0;
    }
}