##########################################
# Pontificia Universidad Javeriana
# Autor: María Fernanda Velandia Gracia
# Materia: Sistemas Operativos
# Docente: J. Corredor
# Fecha: 13 de Noviembre de 2025
# Tema: Compilación automatizada de programas 
####################################################

GCC = gcc

PROGRAMAS = labFichero01 labFichero02 labFichero03

labFichero01:
	$(GCC) $@.c -o $@

labFichero02:
	$(GCC) $@.c -o $@

labFichero03:
	$(GCC) $@.c -o $@

clean:
	$(RM) $(PROGRAMAS)

