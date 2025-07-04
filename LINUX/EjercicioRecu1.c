/* Desarrollar un programa en LINUX para ordenar un arreglo con dos threads.
Existe una lista de 1000 números enteros en el archivo desordenado.txt. (NOTA: el archivo no es de texto,
es de datos binarios).
Desarrollar un programa que cargue los números del archivo en un único arreglo de enteros.
Luego, la mitad del arreglo debe ser ordenado de menor a mayor por un thread, y la segunda mitad del
arreglo debe ser ordenado de menor a mayor por un segundo thread.
Luego de que los dos threads finalizaron, el proceso principal hará una fusión de las dos mitades en un
segundo arreglo final del mismo tamaño. En este arreglo final la lista quedará ordenada luego de fusionada
las dos mitades.
Al finalizar, este proceso muestra cada número del arreglo final ordenado por pantalla (cada número en
una fila diferente).*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>
#include <sys/shm.h>

void abrirMemComp(void), abrirYLeerArchivo(void);
int direcMemComp;

//Debo hacer dos programas, el 0 y el 1
//El arreglo debe estar en la memoria compartida.


char *direccion = "/home/marisol/Descargas/1000_numeros_binarios.txt";

void *ptr;



char arreglo[1000];



int main(){

abrirMemComp();


abrirYLeerArchivo();




}







void abrirYLeerArchivo(void){

int i = 0;

ssize_t bytesLeidos;


int o = open(direccion, O_RDONLY); //Abrimos el archivo (solo lectura) 

if (o != -1){ //Si no hubo un error al abrir el archivo 
char buffer [4096];
ssize_t bytesLeidos; 


while(i<1000){

bytesLeidos = read(o,&buffer[i],4); //Por q van leyendo de a uno en vez de a varios

printf("Bytes leidos %zd\n",bytesLeidos); 

printf("Numero entero %i",bytesLeidos); 



sprintf(ptr,"%s",  &buffer[i]); //Coloco EL CONTENIDO del byte leido en la mem compartida

i++;

}



int cl = close(o);

if (cl == -1) {
printf("ERROR EN CERRAR EL ARCHIVO");
}else{
printf("EL archivo se abrió y se cerró con éxito");}


}

}


void abrirMemComp(void){ 


direcMemComp = shm_open("ordenar", O_CREAT | O_RDWR, 0666);  //Creo la memoria compartida
if (direcMemComp == -1) {
    perror("shm_open failed");
    exit(EXIT_FAILURE);
}
if (ftruncate(direcMemComp, 4096) == -1) {
    perror("ftruncate failed");
    exit(EXIT_FAILURE);
}



//Mapea la memoria compartida en el espacio de dirección del proceso S

ptr = mmap(0,4096,PROT_READ | PROT_WRITE, MAP_SHARED,direcMemComp,0); 

if (ptr == MAP_FAILED){
printf("Map failed \n");
exit(-1);
}


}



