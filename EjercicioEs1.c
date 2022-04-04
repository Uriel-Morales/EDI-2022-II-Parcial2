#include <stdio.h>
typedef struct fecha{
    char mes[12];
    int dia;
    int year;
}date_original;
void pedirdate(date_original *fech);
void imprimir(date_original *fa);
int main(){
date_original date;
pedirdate(&date);
imprimir(&date);}
void pedirdate(date_original *fech){
    printf("Mes:\n");
    scanf("%s",fech->mes);
    printf("Dia:\n");
    scanf("%d",&fech->dia);
    printf("Year:\n");
    scanf("%d",&fech->year);}
void imprimir(date_original *fa)
{
    printf("Fecha: %d/%s/%d",fa->dia,fa->mes,fa->year);
}