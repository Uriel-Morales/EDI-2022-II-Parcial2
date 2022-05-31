#include <stdio.h>
int main()
{
    FILE *archivo;
    int cerrado;
    int cantidad;
    int calf;
    char nombre[20];
    archivo= fopen("Alumnos.txt","w");
    printf("ingresa la cantidad de alumnos a capturar: \n");
    scanf("%d",&cantidad);
    for(int i=0; i< cantidad; i++){
        printf("\nIngresa el nombre: \n");
        scanf("%s",&nombre);
        printf("Ingresa la calificacion: \n");
        scanf("%d",&calf);
        fprintf(archivo, "Alumno: %s Calificacion: %d\n", nombre, calf);
    }
    cerrado= fclose(archivo);
    if(cerrado == EOF){
        printf("El archivo no se cerro bien");
    }
    return 0;}