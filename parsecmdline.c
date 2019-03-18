#include <stdio.h>
#include <string.h>
#include "parsecmdline.h"

int main(int argc, char *argv[])
{
	int resultado;
	int (*pCallback) (char*, char*, void*);
	void * userData = &resultado;

	pCallback = parseCallback;
	resultado = parseCmdLine(argc,argv,pCallback,userData);
	printf("%d\n", resultado);

	return 0;
}

int parseCmdLine(int argc, char* argv[],pCallback p, void * userData)
{
	int argCount=1;/*me salteo el nombre del archivo y el primer parametro*/
	int cantArgs=0; /*cantidad de argumentos totales*/
	 /*chequear caso que no haya nada!!!*/
	for(;argCount<argc && cantArgs!=EXITVALUE ;argCount++)
	{ //ciclo corta si encuentra un error de cualquier tipo
			printf("%s\n",argv[argCount]);
			if(argv[argCount][0]=='-')//CASO OPCION
			{
			 		if(argCount==argc-1 || !((*p)(argv[argCount], argv[argCount+1], userData)))	//Analizo Callback (si es el ultimo argumento deberia tirar error)
					{
							cantArgs=EXITVALUE;
					}
					else
					{
								argCount++;//Todo OK -> saltear el valor
					}
			}
	    else//CASO PARAMETRO
			{
				if(!((*p)(NULL, argv[argCount], userData)))	//Analizo Callback
					cantArgs=EXITVALUE;
			}
			if(cantArgs!=EXITVALUE)
					cantArgs++;//Si todo fue valido se aumenta el contador de argumentos
  }

   return cantArgs;
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
