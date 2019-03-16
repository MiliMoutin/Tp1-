#include <stdio.h>
#define EXITVALUE -1

int parseCmdLine(int argc, char* argv[], int (*parseCallback) (char*, char*, void*), void *userData){
	int argCount=2;/*me salteo el nombre del archivo y el primer parametro*/
	int result=1; /*lo que devuleve parseCallback, flag siempre prendido salvo cuando parseCallback devuelve 0*/
	int unckeckedV=0; /*flag se prende en el caso que haya un key sin value*/
	int cantArgs=1; /*cantidad de argumentos totales*/
	char * value; /*guarda value valido para llamar a parseCallback*/
	char * key; /*guarda key valido para llamar a parseCallBack*/
	 /*chequear caso que no haya nada!!!*/
	while(argCount<argc && !unckeckedV && result){ /*ciclo corta si encuentra un error de cualquier tipo*/
       if(*(argv+argCount)=='-'){ 
            if(argc==argCount){  /*si key y value son validos, los guarda*/
            	unckeckedV=1;
            }
            key=*(argv+argCount); /*faltaria sacar valor de -*/
            value=*(argv+argCount+1);
            argv++;
        }
       else{
       	   value=*(argv+argCount); /*si es un parametro*/
       	   key=NULL;
       	   }
       	cantArgs++;
       result=parseCallback(key, value, userData);
   }
   if (result && !unckeckedV){
   	return cantArgs;
   }
   return EXITVALUE;
}