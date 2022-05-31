#include <stdio.h>
#include <string.h>
#include "pila.h"
int main()
{
    Stack1 stack;
  char cadena[MAX] = "Tercer Examen";
  char caracter;
  int longitud;

  setup(&stack);
  longitud = strlen(cadena);
  for(int i=0; i<longitud; i++)
  {
      push(&stack, cadena[i]);
  }

  while(!isEmpty(stack))
  {
      pop(&stack, &caracter);
      printf("%c",caracter);
  }
}