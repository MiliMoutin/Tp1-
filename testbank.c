#include <stdio.h>
#include <string.h>
#include "parsecmdline.h"

int main (void)
{
  char * key[] = {"-hola", NULL,"-","-hola","-"};
  char * value [] = {"4", "hola", "4", "",""};
  int variable;
  void * userData;
  userData = &variable;
  int prueba1, prueba2, prueba3, prueba4, prueba5;

  prueba1 = parseCallback(key[0],value[0],userData); // opción, con clave y con valor (bien pasado)
  if (prueba1)
  {
    printf ("prueba 1 OK\n");
  }
  else
  {
    printf ("prueba 1 falló\n");
  }
  prueba2 = parseCallback(key[1],value[1],userData); // parámetro, con valor (bien pasado)
  if (prueba2)
  {
    printf ("prueba 2 OK\n");
  }
  else
  {
    printf ("prueba 2 falló\n");
  }
  prueba3 = parseCallback(key[2],value[2],userData); // opción, sin clave y con valor (mal pasado)
  if (!prueba3)
  {
    printf ("prueba 3 OK\n");
  }
  else
  {
    printf ("prueba 3 falló\n");
  }
  prueba4 = parseCallback(key[3],value[3],userData); // opción, con clave y sin valor (mal pasado)
  if (!prueba4)
  {
    printf ("prueba 4 OK\n");
  }
  else
  {
    printf ("prueba 4 falló\n");
  }
  prueba5 = parseCallback(key[4],value[4],userData); // opción, sin calve y sin valor (mal pasado)
  if (!prueba5)
  {
    printf ("prueba 5 OK\n");
  }
  else
  {
    printf ("prueba 5 falló\n");
  }

return 0;
}

int parseCallback(char *key, char *value, void *userData)
{
  int salida = 1;
  char comp[] = "-";
  char compvacio[] = "";

    if (key && !strcmp(key,comp))
    {
      salida = 0;
    }
    if (key && !strcmp(value,compvacio))
    {
      salida = 0;
    }

  return salida;
}
