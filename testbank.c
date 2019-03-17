#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parsecmdline.h"

typedef struct {
	char * name;
	int legajo;
  char asist;
}studentinfo_t;

int chkcmdline(char * pass, char * value, void * userData);

int main(int argc,char* argv[])
{
  studentinfo_t student={NULL,0,0};
  char argv1[11][15]={"./exe","-name","philippe","-legajo","59009","asistida"};
  char argc1=6;
  if(parseCmdLine(argc,argv,chkcmdline,&student)!=EXITVALUE)
  {
    printf("nombre:%s legajo:%d\n",student.name,student.legajo);
    if(student.asist && student.name)//Sin nombre no hay sentido
    {
      printf("El alumno esta en asistida\n");
    }
  }
  else
  {
    printf("oh oh... parece que cargaste algo mal.\n");
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
