#include <stdio.h>
#include "parsecmdline.h"

int parseCmdLine(int argc, char* argv[],pCallback p, void *userData)
{
	int argCount=1;/*me salteo el nombre del archivo y el primer parametro*/
	int cantArgs=0; /*cantidad de argumentos totales*/
	 /*chequear caso que no haya nada!!!*/
	for(;argCount<argc && cantArgs!=EXITVALUE ;argCount++)
	{ //ciclo corta si encuentra un error de cualquier tipo
			if(argv[argCount][0]=='-')//CASO OPCION
			{
			 		if(argv[argCount][1] == '\0' || argCount==argc-1 || !((*p)(argv[argCount], argv[argCount+1], userData)))	//Analizo Callback (si es el ultimo argumento deberia tirar error)
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
