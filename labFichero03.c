/***********************************************
* Pontificia Universidad Javeriana
* Autor: María Fernanda Velandia Gracia
* Materia: Sistemas Operativos
* Docente: J. Corredor
* Fecha: 13 de Noviembre de 2025
* Tema: Atributos de archivos y permisos en directorios
* Descripción:
*    - Solicita el nombre de un directorio, recorre su
*      contenido y muestra los permisos, tipo y fecha de
*      modificación de cada archivo.
***********************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(){
	int er;
	char nomdir[100], nomfich[200], resp[30];
	struct stat atr;
	DIR *d;
	struct dirent *rd1;
	time_t fecha;

	// Solicita el nombre
	printf("Nombre directorio\n");
	fgets(nomdir, sizeof(nomdir), stdin);

	/*Hay que quitar el \n del nombre del directorio*/
	nomdir[strlen(nomdir) - 1] = '\0'; 

	// Guarda la fecha actual 
	fecha = time(&fecha);	

	// Intenta abrir el directorio
	if ((d = opendir(nomdir)) == NULL){
		printf("No existe ese directorio\n");
		return -1;
	}
	else {
		while ((rd1 = readdir(d)) != NULL){
			// Recorre cada elemento del directorio
			if((strcmp(rd1->d_name, ".") != 0) && (strcmp(rd1->d_name,"..") != 0)){
				strcpy(nomfich, nomdir);
				strcat(nomfich, "/");
				strcat(nomfich, rd1->d_name);
				printf("fichero : %s:\n", nomfich);

				// Obtiene los atributos
				er = stat(nomfich, &atr);
				if (er != 0) {
					perror("Error al obtener atributos");
					continue;
				}

				printf("modo: %o:\n", atr.st_mode);

				// Verifica permisos de lectura
				if ((atr.st_mode & 0400) != 0)
					printf("permiso R para propietario\n");
				else
					printf("No permiso R para propietario\n");

				// Verifica si es un directorio
				if (S_ISDIR(atr.st_mode))
					printf("Es un directorio\n");

				// Verifica si es un archivo regular
				if (S_ISREG(atr.st_mode))
					/*ficheros modificados en los últimos 10 dias */
					if ((fecha - 10*24*60*60) < atr.st_mtime){
						printf("FICHERO: %s | Fecha acceso: %s | En segundos: %ld\n",
							nomfich,
							ctime(&atr.st_mtime),
							atr.st_mtime);
					}
			}
		} /*Cierra while*/

		// Cierra el directorio
		closedir(d);
	}
}

// CONCLUSIONES
// Con este programa logramos recorrer el contenido de un directorio y tener la información de cada archivo (permisos, tipo y fecha de modificación) con el uso de funciones como opendir, readdir, stat, closedir. Con st_mode podemos saber los permisos de lectura del propietario y si es directorio o archivo regular.

