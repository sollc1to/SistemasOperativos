
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>
#include <sys/shm.h>
void longitud(void);
void reverso (void);


char direccion [] ="/home/marisol/a.txt";

char *p; //Puntero que guardará la dirección del arreglo dinámico

int tamaño;

void longitud(void){
tamaño = 0;


int o = open(direccion, O_RDONLY); //Abrimos el archivo (solo lectura) 

if (o != -1){ //Si no hubo un error al abrir el archivo 
char caracter;

p = malloc(20); //Arreglo dinámico de 20 
if (p == NULL) {

printf("ERROR MALLOC");


}else{


while(read(o,&caracter,1) != 0){ //Leemos de a un caracter. Mientras existan caracteres...

printf("Caracter: %c\n",caracter); 
p[tamaño] = caracter; 

tamaño++; 

printf("Tamaño: %d",tamaño);

}

}

}else{
printf("ERROR OPEN");}

}

void reverso (void){
int i = 0, final = tamaño-1;
char temp;

while (i<=(tamaño/2)) {
printf("Primer caracter %c\n",p[i]); 
printf("Ultimo caracter %c\n",p[final]); 
temp = p[i];

p[i] = p[final]; 

p[final] = temp;


printf("Primer caracter %c\n",p[i]); 
printf("Ultimo caracter %c\n",p[final]); 
printf(":)\n");


i++;
final--;


}


}

int main (void){


longitud();




reverso();


int i = 0;
while(i < tamaño){

printf("%c\n",p[i]); 

i++; 

}



return 0;

}



















