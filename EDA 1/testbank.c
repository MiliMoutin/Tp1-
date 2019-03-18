#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parsecmdline.h"
// ============ Colored Text ===========

#define BLACK_TEXT		   "\e[30;1m"
#define RED_TEXT		   "\e[31;1m"
#define GREEN_TEXT 		   "\e[32;1m"
#define YELLOW_TEXT 	   "\e[33;1m"
#define BLUE_TEXT 		   "\e[34;1m"
#define MAGENTA_TEXT 	   "\e[35;1m"
#define CYAN_TEXT 	   	   "\e[36;1m"
#define WHITE_TEXT 		   "\e[37m"

int parseCallback(char * pass, char * value, void * userData);
int parseall(int argc, char** argv, pCallback p, void *userData);

int main(int argc,char* argv[])
{
  studentinfo_t student={NULL,0,0};//Variable para el callback
// Prueba 1: vacio
	char *prueba1[2]={"./file",NULL};
	printf(CYAN_TEXT"Prueba 1: vacio\t"WHITE_TEXT);
	printf("CMDLINE:%s\t\t",prueba1[0]);
	parseall(1,prueba1,parseCallback,&student);
//Prueba 2: con clave sin valor
	char *prueba2[3]={"./file","-name",NULL};
	printf(CYAN_TEXT"Prueba 2: con clave sin valor\t"WHITE_TEXT);
	printf("CMDLINE:%s\t\t","./file -name");
	parseall(2,prueba2,parseCallback,&student);
//Prueba 3: sin clave con valor
	char *prueba3[4]={"./file","-","56328",NULL};
	printf(CYAN_TEXT"Prueba 3: sin clave con valor\t"WHITE_TEXT);
	printf("CMDLINE:%s\t\t","./file - 56328");
	parseall(3,prueba3,parseCallback,&student);
//Prueba 4: opcion con valor incoherente
	char *prueba4[4]={"./file","-legajo","-1",NULL};
	printf(CYAN_TEXT"Prueba 4: opcion con valor incoherente\t"WHITE_TEXT);
	printf("CMDLINE:%s\t\t","./file -legajo -1");
	parseall(3,prueba4,parseCallback,&student);
//Prueba 5: parametro inexistente
	char *prueba5[3]={"./file","ITBA",NULL};
	printf(CYAN_TEXT"Prueba 5: parametro inexistente\t"WHITE_TEXT);
	printf("CMDLINE:%s\t\t","./file ITBA");
	parseall(2,prueba5,parseCallback,&student);
//Prueba 6: "todo bien"
	char *prueba6[7]={"./file","-name","Gonzalo","-legajo","57668","asistida",NULL};
	printf(CYAN_TEXT"Prueba 6: todo bien\t"WHITE_TEXT);
	printf("CMDLINE:%s\t\t","./file -name Gonzalo -legajo 57668 asistida");
	parseall(6,prueba6,parseCallback,&student);


}

/******************************************************************************/
int parseCallback(char *key, char *value, void *userData)
{
  int salida = 1;//Variable de validez
    if (key)
    {
      salida = 1;//aqui se agregan los criterios para las OPCIONES
    }
    else
    {
      salida = 1;//aqui se agregan los criterios para los PARAMETROS
    }

  return salida;
}
/******************************************************************************/
int parseall(int argc,char** argv,pCallback p,void *userData)
{
	int retvalue=0;
	if(parseCmdLine(argc,argv,p,userData)!=EXITVALUE)
	{
		printf(GREEN_TEXT"Good gone champ!\n\n"WHITE_TEXT);
		retvalue=1;
	}
	else
	{
		printf(RED_TEXT"oh oh... parece que cargaste algo mal.\n\n"WHITE_TEXT);
		retvalue=0;
	}
	return retvalue;
}
