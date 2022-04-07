#include <stdio.h>
void pedirarreglo(int array[], int *n);
void imprimirarreglo(int array[], int *n);
void concatenar(int array[],int array2[],int array3[],int *o,int *n);
void bubbleSort(int arreglo[],int *o);
int main()
{
    int n,m;
    printf("cantidad de elementos del primer array:\n");
    scanf("%d",&n);
    int array[n];
    pedirarreglo(array, &n);
    imprimirarreglo(array,&n);
    printf("\ncantidad de elementos del segundo array:\n");
    scanf("%d",&m);
    int array2[m];
    pedirarreglo(array2, &m);
    imprimirarreglo(array2,&m);
    int o=n+m;
    int array3[o];
    concatenar(array, array2, array3, &o, &n);
    printf("\nArreglo 3:");
    imprimirarreglo(array3,&o);
    printf("\nSaliendo de la funcion:");
    bubbleSort(array3,&o);
    imprimirarreglo(array3,&o);
    return 0;
}
void pedirarreglo(int array[], int *n)
{
    int i;
    for(i=0;i < *n;i++)
    {
        printf("Ingrese el elemento %d del arreglo\n",i);
        scanf("%d", &array[i]);
    }
}
void concatenar(int array[],int array2[],int array3[],int *o,int *n)
{
    int i;
    for(i=0;i < *o;i++){
        if(i < *n){
            array3[i]=array[i];
        }
        else
        {
            array3[i] = array2[i-(*n)];
        }}}
void bubbleSort(int arreglo[],int *o){
    int aux;
    int intercambio = 1;
    int actual;
    for(int i = 0; i < *o && intercambio == 1; i++){
        intercambio = 0;
        for(actual = 0; actual < *o - i - 1; actual++){
            if(arreglo[actual] > arreglo[actual + 1]){
                aux = arreglo[actual];
                arreglo[actual] = arreglo[actual + 1];
                arreglo[actual + 1] = aux;
                intercambio = 1;
            }}}}
void imprimirarreglo(int array[],int *n)
{
    int i;
    printf("\n[");
    for(i = 0; i < *n; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("]");
}