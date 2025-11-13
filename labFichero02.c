/***********************************************
* Pontificia Universidad Javeriana
* Autor: María Fernanda Velandia Gracia
* Materia: Sistemas Operativos
* Docente: J. Corredor
* Fecha: 13 de Noviembre de 2025
* Tema: Manejo de directorios y archivos en C
* Descripción:
*    - Solicita el nombre de un directorio y muestra
*      los nombres y tamaños de los archivos.
***********************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(){
	DIR *d;
	char nomdir[90], nomfich[90];
	struct stat datos;
	struct dirent *direc;
	
	// Solicita el nombre del directorio
	printf("Introduzca el Nombre de un Directorio: ");
	fgets (nomdir, sizeof(nomdir),stdin);
	nomdir[strlen(nomdir)-1] = '\0'; /*Eliminamos el \n del Nombre del Fichero*/
	// Intenta abrir el archivo
	if ((d = opendir(nomdir))==NULL){
	printf("El directorio no existe\n");
	return -1;
	}
	// Lee las lineas
	while ((direc = readdir(d)) != NULL){
	strcpy(nomfich,nomdir);
	strcat(nomfich, "/");
	strcat(nomfich, direc->d_name);
	
	// Obtiene la información
	stat (nomfich, &datos);
	// Si es regular, se imprime el nombre y el tamaño
	if(S_ISREG(datos.st_mode))
		printf("Nombre: %s\t| Tamaño: %ld bytes\n", direc->d_name, datos.st_size);

	} /*Fin del while*/
	closedir(d);
}

//CONCLUSIONES
// Tenemos manejo de directorios y archivos con funciones como opendir, readdir, stat y closedir. El usuario ingresa el nombre del directorio, se verifica si existe o no y se recorre el contenido para mostrar los nombres y los tamaños de archivos regulares. Con ayuda de stat, obtenemos la información de cada archivo(tamaño de bytes).
