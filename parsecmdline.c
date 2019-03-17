#include <stdio.h>
#include "parsecmdline.h"

int parseCmdLine(int argc, char* argv[],pCallback parseCallBack, void *userData)
{
	int argCount=1;/*me salteo el nombre del archivo y el primer parametro*/
	int cantArgs=0; /*cantidad de argumentos totales*/
	 /*chequear caso que no haya nada!!!*/
	for(;argCount<argc && cantArgs!=EXITVALUE ;++argCount)
	{ //ciclo corta si encuentra un error de cualquier tipo
			printf("%s\n",argv[argCount]);
			if(argv[argCount][0]=='-')//CASO OPCION
			{
					if(argv[argCount][1] == '\0')	//Analiza si el caracter siguiente al guion es vacio)
					{
							cantArgs=EXITVALUE;
					}
		      else if(argCount==(argc-1))  //si key y value son validos, los guarda
		      {
							cantArgs=EXITVALUE;
					}
					else if(!((*parseCallBack)(argv[argCount]+1, argv[argCount+1], userData)))	//Analizo Callback
					{
							cantArgs=EXITVALUE;
					}
					else
					{
								++argCount;//Todo OK -> saltear el valor
					}
			}
	    else//CASO PARAMETRO
			{
				if(!((*parseCallBack)(NULL, argv[argCount], userData)))	//Analizo Callback
					cantArgs=EXITVALUE;
			}
			if(cantArgs!=EXITVALUE)
					++cantArgs;//Si todo fue valido se aumenta el contador de argumentos
  }

   return cantArgs;
}
