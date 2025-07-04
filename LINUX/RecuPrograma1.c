/* Ejercicio 1.
a.
Implemente en Linux dos programas:
1. Un programa crea memoria compartida, y carga en la memoria compartida la foto cat.pgm, usando
funciones para acceder a archivos en el sistema de archivos.
2. Un segundo programa lee de la memoria compartida la foto, y la guarda en un nuevo archivo de manera
invertida.
- Para invertir la imagen se debe mantener la cabecera intacta, y luego deberán estar los bytes de los píxeles
invertidos (el último byte de pixel de cat.pgm será el primer byte de pixel en cat2.pgm, etc).
El formato pgm de la imagen de ejemplo es sencillo:
- Los primeros 15 bytes son la cabecera del formato del archivo de imagen.
- Los siguientes bytes son los valores de cada pixel de la imagen.*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>
#include <sys/shm.h>


int main(){



int direcMemComp; 
void *ptr;
void *aux;

char *PATH = "/home/marisol/Descargas/cat(1).pgm";

//Solicita la dirección de memoria compartida
direcMemComp = shm_open("cat", O_CREAT | O_RDWR, 0666); 
if (direcMemComp == -1) {
    perror("shm_open failed");
    exit(EXIT_FAILURE);
}

//Configura el tamaño de la memoria compartida 
if (ftruncate(direcMemComp, 16384) == -1) {
    perror("ftruncate failed");
    exit(EXIT_FAILURE);
}



//Mapea la memoria compartida en el espacio de dirección del proceso S

ptr = mmap(0,18000,PROT_READ | PROT_WRITE, MAP_SHARED,direcMemComp,0); 

if (ptr == MAP_FAILED){
printf("Map failed \n");
exit(-1);
}

aux = ptr; //Guardo la dirección inicial de la memoria compartida

int direc = open(PATH, O_RDONLY);

printf("%i\n\r",direc);


if (direc != -1) { // SI direc == -1, entonces hubo un error 
char buffer [16384];
ssize_t bytesLeidos; 


bytesLeidos = read(direc,buffer,16384); //Leemos 20 bytes 


if (bytesLeidos != -1){ //SI no hubo error, escribimos el contenido de la lectura en la memoria compartida

memcpy(ptr, buffer, bytesLeidos); //Coloco EL CONTENIDO del archivo en la memoria compartida


int cl = close(direc);

if (cl == -1) {
printf("ERROR EN CERRAR EL ARCHIVO");
}else{
printf("EL archivo se abrió y se cerró con éxito");}


}else{
printf("ERROR AL LEER BYTES");

}

}else{  
printf("ERROR AL ABRIR EL ARCHIVO");

}


while(1){

printf("PID DEL PROCESO 1 %d",getpid()); 


}

sleep(10);

}


