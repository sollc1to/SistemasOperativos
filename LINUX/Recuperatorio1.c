/*Ejercicio 1. Implementación de procesos en LINUX.
Desarrollar un programa en linux que genere dos procesos hijos. El primer proceso calcula números primos
infinitamente. El segundo proceso calcula años bisiestos infinitamente. Ambos hijos van mostrando un mensaje del
primo o año bisiesto calculado. Ejemplo: “soy el proceso X nro primo: 31”. El padre de los dos hijos finaliza al
segundo hijo a los 4 segundos, y finaliza al primer hijo luego de 8 segundos. Luego, el padre finaliza */ 

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void numerosPrimos(void), numerosBisiestos(void);


int main(){
int pid1, pid2;

pid1 = fork();

if (pid1 == 0){

printf("Soy el hijo 1"); 
numerosPrimos();

}else{ 

pid2 = fork();

if(pid2 == 0){

printf("Soy el hijo 2"); 

numerosBisiestos();

}else{
printf("Soy el padre"); 

sleep(4); 
kill(pid2,SIGKILL);
sleep(4);
kill(pid1,SIGKILL);

printf("El padre finaliza"); 
exit(0);


}
}



return 0;
}

void numerosPrimos(){ 
int j = 2;
int esPrimo = 1;

while(1){

for(int i = 2; i<j; i++){

if (j%i == 0){
esPrimo = 0;
break;
}

}
if(esPrimo == 0){
esPrimo = 1;
}else{ 
printf("El proceso uno encontró al número %d PRIMO\n\r", j);
}

j = j+1;

}
}


void numerosBisiestos(){

int i=1;
while(1){

if(( i%4 ==0 && i%100 !=0) || (i%400 ==0)){

printf("EL proceso dos encontro el año BISIESTO %d\n\r", i);
}
i++;

}
}







 








