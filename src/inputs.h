#ifndef INPUTS_H_
#define INPUTS_H_

#endif /* INPUTS_H_ */

int getValidChar(char* caracter, char* mensaje, char* mensajeError, char letra1, char letra2, int reintentos);

int pedirEntero(int *enteroValidado, char mensaje[], char mensajeError[], int minimo, int maximo);

int getString(char* cadena, char* mensaje);
int pedirCadena(char cadena[], char mensaje[], char mensajeError[], int max);

int pedirFlotante(float *numFloat, char mensaje[], char mensajeError[], float min, float max);

int validateCharacter(char string[]);
int firstCapitalChar(char name[]);
int getValidFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int imprimeMensaje(char mensaje[]);
int soloLetras(char cadena[]);
int ordenarCadena(char cadena[]);
int pedirCaracter(char *charValidado, char mensaje[], char mensajeError[], char primerChar, char segundoChar);
