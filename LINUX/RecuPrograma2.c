/*Programa b*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>
#include <sys/shm.h>


/* 2. Un segundo programa lee de la memoria compartida la foto, y la guarda en un nuevo archivo de manera
invertida.
- Para invertir la imagen se debe mantener la cabecera intacta, y luego deberán estar los bytes de los píxeles
invertidos (el último byte de pixel de cat.pgm será el primer byte de pixel en cat2.pgm, etc).
El formato pgm de la imagen de ejemplo es sencillo:
- Los primeros 15 bytes son la cabecera del formato del archivo de imagen.
- Los siguientes bytes son los valores de cada pixel de la imagen.*/ 


int main(){
unsigned char *ptr;
int fd; //Direccion del nuevo archivo.


printf("PID DEL PROCESO 2 %d",getpid()); 

sleep(10);

int direccionMemComp = shm_open("cat",O_RDONLY,0666); //ABrimos la mem

if (direccionMemComp != -1) {
ptr = mmap(0,16384,PROT_READ,MAP_SHARED,direccionMemComp,0); 

if (ptr == MAP_FAILED){
printf("Map failed\n"); 
exit(-1); 



 }
 
 
 
 
printf("INICIO DEL SEGMENTO DE MEMORIA: 0x%llX",&ptr);
 
 const char *nuevo = "cat2.pgm";
 
 fd = open(nuevo,O_RDWR|O_CREAT|O_TRUNC,0666); //Pide al SO crear un archivo nuevo
 
 write(fd,&ptr[0],15); //ESCRIBIMOS LOS BYTES DE LA CABECERA. 
 
 
 int i = 16384- 15;  
 /*El numero total de bytes - 15*/
 
 while (i > 0 ){

 write(fd,&ptr[i],1);
 
 
 i--;

 
 }
 
 
 
 
 close(fd);
 
 
 


 
 
 if(shm_unlink("cat") == -1){
  //Remueve la porción de memoria compartida creada. 
 printf("ERROR AL ELIMINAR LA MEMORIA COMPARTIDA");
 

 
 
 }
 
 
 while(1){

printf("PID DEL PROCESO2 %d",getpid()); 


}
 
 
 }
 
 }
