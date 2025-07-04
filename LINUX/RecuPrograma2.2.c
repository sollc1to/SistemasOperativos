/*El segundo programa, hará espera por consulta. Estará leyendo el primer lugar de la memoria
compartida, esperando a que el valor sea diferente de cero. Cuando sea diferente de cero, significa
que el primer programa habrá terminado de cargar la memoria. Entonces, el segundo programa
puede comenzar en ese momento a ordenar los números. Finalmente, una vez ordenados,
colocará el valor uno (1), en el primer lugar de la memoria compartida.*/ 


/*Programa b*/
#include <stdio.h> 
#include <fcntl.h>
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>


int main(){
int *ptr;
int direccionMemComp = shm_open("ejerciciorecu",O_RDWR,0666);
char *PATH = "/home/marisol/ordenado/desordenado(1).bin"; 
int i = 0, num, aux;
int direc = open (PATH, O_RDWR);

int tamaño;



while(read(direc,&num,sizeof(int))){ //Leemos de a un entero y vamos contando el tamaño.Repite mientras no sea el final del archivo.

i++;

} //CALCULAMOS EL TAMAÑO 

close(direc);


tamaño = i;
if (direccionMemComp != -1) {
ptr = mmap(0,tamaño,PROT_READ | PROT_WRITE,MAP_SHARED,direccionMemComp,0); 

if (ptr == MAP_FAILED){
printf("Map failed\n"); 
exit(-1); 



 }
 
 
 
 while(ptr[0] == 0){ //MIENTRAS SEA CERO
 
 printf("EL proceso dos duerme..");
 sleep(1);
 
 }
 
 
 int i = 1,final = ptr[0]; //EN la dirección cero esta el tamaño.
 
 int j = 0, temp, min;
 
 
 printf("TAMAÑO FINAL %d", ptr[0]);
 
 //COmo el final arranca en cero, ponemos menor igual
 
 
 
 
 
 
 i =1;
 

 while( i <= final) {
 min = ptr[i]; 
 
 printf("Numero %d", ptr[i]);
 j = i;
 
 while(j <= final){ //MBUscamos el minimo
 
 
if (ptr[j] < min){
min = ptr[j];
 aux= j;

 }

 
 j++;
 
 
 }

  printf("Se intercambia  %d por %d", ptr[i],min); 
 
 temp = ptr[i]; 
 
 ptr[i] = min;
 
 
 ptr[aux] = temp;

 i++;
 
 
 }
 
 
 
 printf("Termino el ordenamiento... coloca uno en la primera posicion");
 ptr[0] = 1 ;
 
 
 

 }
 
 }
 
 
 
 

 
 
 
 
 
 
 



