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

typedef struct {
	char * name;
	int legajo;
  char asist;
}studentinfo_t;

int chkcmdline(char * pass, char * value, void * userData);
int parseall(int argc,char** argv,pCallback p,void *userData);

int main(int argc,char* argv[])
{
  studentinfo_t student={NULL,0,0};//Variable para el callback
	int flags[6];//flags para el resumen
// Prueba 1: vacio
	char *prueba1[2]={"./file",NULL};
	printf(CYAN_TEXT"Prueba 1: vacio\t"WHITE_TEXT);
	printf("CMDLINE:%s\nSalida:\n",prueba1[0]);
	flags[0]=parseall(1,prueba1,chkcmdline,&student);
//Prueba 2: con clave sin valor
	char *prueba2[3]={"./file","-name",NULL};
	printf(CYAN_TEXT"Prueba 2: con clave sin valor\t"WHITE_TEXT);
	printf("CMDLINE:%s\nSalida:\n","./file -name");
	flags[1]=parseall(2,prueba2,chkcmdline,&student);
//Prueba 3: sin clave con valor
	char *prueba3[4]={"./file","-","56328",NULL};
	printf(CYAN_TEXT"Prueba 3: sin clave con valor\t"WHITE_TEXT);
	printf("CMDLINE:%s\nSalida:\n","./file - 56328");
	flags[2]=parseall(3,prueba3,chkcmdline,&student);
//Prueba 4: opcion con valor incoherente
	char *prueba4[4]={"./file","-legajo","-1",NULL};
	printf(CYAN_TEXT"Prueba 4: opcion con valor incoherente\t"WHITE_TEXT);
	printf("CMDLINE:%s\nSalida:\n","./file -legajo -1");
	flags[3]=parseall(3,prueba4,chkcmdline,&student);
//Prueba 5: parametro inexistente
	char *prueba5[3]={"./file","ITBA",NULL};
	printf(CYAN_TEXT"Prueba 5: parametro inexistente\t"WHITE_TEXT);
	printf("CMDLINE:%s\nSalida:\n","./file ITBA");
	flags[4]=parseall(2,prueba5,chkcmdline,&student);
//Prueba 6: "todo bien"
	char *prueba6[7]={"./file","-name","Gonzalo","-legajo","57668","asistida",NULL};
	printf(CYAN_TEXT"Prueba 6: todo bien\t"WHITE_TEXT);
	printf("CMDLINE:%s\nSalida:\n","./file -name Gonzalo -legajo 57668 asistida");
	flags[5]=parseall(6,prueba6,chkcmdline,&student);
	for(int i=0;i<=6;++i)
	{
		printf("RESUMEN:\n");
		if(flags[i])
				printf("\nprueba %d: OK",i);
		else
				printf("\nprueba %d:ERROR",i);
		putchar('\n');
	}

}

/******************************************************************************/
int chkcmdline(char * pass, char * value, void * userData)
{
	studentinfo_t * usr = (studentinfo_t *)userData;
	int retValue = 1;//Es inocente hasta que se demuestre lo contrario
	if (pass)
	{
		if (!strcmp((const char*)pass, "name"))
			usr->name = value;
		else if (!strcmp((const char*)pass, "legajo"))
		{
			usr->legajo = atoi(value);
			if (usr->legajo < 0)
				retValue = 0;
		}
		else
			retValue = 0;  //Se uso una opcion incoherente
	}
	else
	{
    if (!strcmp(value, "asistida"))
			usr->asist = 1;
		else
			retValue = 0;//Se uso un parametro incoherente
	}

	return  retValue;
}
/******************************************************************************/
int parseall(int argc,char** argv,pCallback p,void *userData)
{
	studentinfo_t * usr = (studentinfo_t *)userData;
	int retvalue=0;
	if(parseCmdLine(argc,argv,p,userData)!=EXITVALUE)
	{
		printf("\nnombre:%s legajo:%d\n",usr->name,usr->legajo);
		if(usr->asist && usr->name)//Sin nombre no hay sentido
		{
			printf("El alumno esta en asistida\n");
		}
		retvalue=1;
	}
	else
	{
		printf(RED_TEXT"oh oh... parece que cargaste algo mal.\n"WHITE_TEXT);
		retvalue=0;
	}
	return retvalue;
}

