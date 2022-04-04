#include <stdio.h>
#include <math.h>
typedef struct coor
{
    int x;
    int y;
}coordenada;

void pedirpunto(coordenada *point);
void imprimir(coordenada *point);
float distancia(coordenada *point, coordenada *point2);
int main()
{
    float resultado;
    coordenada punto;
    coordenada punto2;
    printf("Punto 1:\n");
    pedirpunto(&punto);
    printf("\nPunto 2:\n");
    pedirpunto(&punto2);
    imprimir(&punto);
    imprimir(&punto2);
    resultado=distancia(&punto,&punto2);
    printf("%.2f",resultado);
}

void pedirpunto(coordenada *point){
    printf("Valor x:\n");
    scanf("%d",&point->x);
    printf("Valor y:\n");
    scanf("%d",&point->y);}

void imprimir(coordenada *point){
    printf("(%d,%d)",point->x,point->y);
}
float distancia(coordenada *point, coordenada *point2){
    float dis;
    printf("\nLa distancia entre (%d,%d) y (%d,%d) es: ",point->x,point->y,point2->x,point2->y);
    dis= sqrt(pow(point->x - point2->x, 2) + pow(point->y - point2->y, 2));
    return dis;
}
