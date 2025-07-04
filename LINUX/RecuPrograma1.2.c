/*programa A*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>
#include <sys/shm.h>


char *PATH = "/home/marisol/ordenado/desordenado(1).bin"; 

char *archivoNuevo = "/home/marisol/ordenado/desordenado(2).bin";



int main(){

int i = 0;

int direcMemComp; 
int *ptr;
int tamaño, num;


int direc = open(PATH, O_RDWR); //Abrimos el archivo

while(read(direc,&num,sizeof(int))){ //Leemos de a un entero y vamos contando el tamaño.Repite mientras no sea el final del archivo.

i++;

} //CALCULAMOS EL TAMAÑO 

close(direc); //Cerramos el archivo

printf("Tamaño %d", i);

tamaño = i;




//Solicita la dirección de memoria compartida
direcMemComp = shm_open("ejerciciorecu", O_CREAT | O_RDWR, 0666); 


if (direcMemComp == -1) {
    perror("shm_open failed");
    exit(EXIT_FAILURE);
}

//Configura el tamaño de la memoria compartida 
if (ftruncate(direcMemComp, tamaño)) {
    perror("ftruncate failed");
    exit(EXIT_FAILURE);
}


//Mapea la memoria compartida en el espacio de dirección del proceso S

ptr = mmap(0,tamaño,PROT_READ | PROT_WRITE, MAP_SHARED,direcMemComp,0); 




if (ptr == MAP_FAILED){
printf("Map failed \n");
exit(-1);
}



/* El primer programa, luego de crear la memoria compartida, coloca el entero cero (0) en el primer
lugar de la memoria compartida. Luego de eso, colocará los números del archivo desordenado.bin
en las posiciones siguientes. Cuando termina de cargar la memoria, coloca en el primer lugar de la
memoria compartida el entero n, que sea la cantidad de enteros del archivo desordenado.bin */


printf("%i\n\r",direc);

ptr[0] = 0;



direc = open(PATH, O_RDWR); //Abrimos el archivo de nuevo 

if (direc != -1) {  // SI direc == -1, entonces hubo un error 

while(read(direc,&num,sizeof(int))){
printf("NUMERO: %d\n\r", num);
ptr[i] = num;

}


}

close(direc);


//Una vez que termina, colocamos uno en la mem el TAMAÑO


ptr[0] = tamaño;

//Debería quedarse esperando hasta que el primer valor de la mem comaprtida sea 1 

/*El primer programa se quedará esperando de manera activa. Se quedará esperando a que en el
primer lugar de la memoria compartida aparezca el uno (1). Cuando ese lugar sea 1, sabrá que el
segundo programa finalizó, y podrá continuar y guardar los números enteros en el nuevo archivo
ordenado.bin */

while(ptr[0] != 1){ 
printf("EL proceso uno duerme");
sleep(1);

}





printf("Terminó de ordenar");
printf("Numeros ordenado");



int fd_2 = open(archivoNuevo, O_RDWR | O_CREAT | O_TRUNC, 0666);


i = 0;
while(write(fd_2,&ptr[i],sizeof(int))){

i++;


}




while(read(fd_2,&num,4)){


printf("%d",num);



}


close(fd_2);


shm_unlink("ejerciciorecu");
munmap(ptr,tamaño);
close(direcMemComp);



}
















