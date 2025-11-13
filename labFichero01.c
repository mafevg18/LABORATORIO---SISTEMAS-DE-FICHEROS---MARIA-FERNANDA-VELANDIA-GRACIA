/***********************************************
* Pontificia Universidad Javeriana
* Autor: María Fernanda Velandia Gracia
* Materia: Sistemas Operativos
* Docente: J. Corredor
* Fecha: 13 de Noviembre de 2025
* Tema: Manejo de ficheros en C
* Descripción:
*    - Abrir y leer el contenido de un archivo de texto llamado "readme.txt".    
***********************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	// Nombre del archivo
	char *filname = "readme.txt";
	// Abrir en modo lectura
	FILE *fp = fopen(filname, "r");
	//Verificación apertura
	if(fp == NULL){
        	printf("Error: no se puede abrir el fichero %s", filname);
        	return 1;
	}

	const unsigned MAX_LENGTH = 256;
	char buffer[MAX_LENGTH];
	//Leer linea por linea del archivo
	while(fgets(buffer, MAX_LENGTH, fp)){
        	printf("%s", buffer);
	}
	// Cerrar el archivo
	fclose(fp);
	printf("\n ================================== \n");
	printf("\n Lectura de fichero readme.txt\n ");
	printf("\n ================================== \n");

	return 0; 
}

//CONCLUSIONES
// Se abre y se lee el archivo de texto(readme.txt). Usamos fopen para tener abierto el archivo en modo lectura, fgets para leer línea por línea del contenido y por último fclose para cerrarlo. Contamos con una verificación de apertura para los posibles errores si no existe el archivo o no se puede acceder. 
