#ifndef PARSECMDLINE_H
#define PARSECMDLINE_H

#define EXITVALUE -1

typedef int (* pCallback) (char*, char*, void*);

//PARSECMDLINE valida lo ingresado por linea de comando y utiliza una funcion
// para corroborar la validez de cada dato.
//RECIBE:   argc: cantidad de argumentos en CMDLINE
//          argv: argumentos de CMDLINE
//          parseCallBack: funcion que analiza el por argumentos de CMDLINE
//          userData: bloque de memoria designado para el uso del Callback
//
//DEVUELVE: -1 si hubo un error a la hora de analizar los argumentos,
//          devuelve 0 o mas equivalente a la cantidad de argumentos ingresados

int parseCmdLine(int argc, char *argv[], pCallback parseCallBack, void * userData);
int parseCallback(char *key, char *value, void *userData);
#endif
