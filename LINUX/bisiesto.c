#include <stdio.h> 
#include <unistd.h>
#include <sys/wait.h> 
#include <stdlib.h> 

void añosBisiestosProcesoUno(void), añosBisiestosProcesoDos(void);




int main(){

int pid1, pid2; 

pid1 = fork(); 

if (pid1 == 0){ 
printf("SOy el PROCESO UNO"); 
añosBisiestosProcesoUno(); 

}else{ 

pid2 = fork(); 
if (pid2 == 0){ 
printf("SOy el PROCESO DOS"); 
añosBisiestosProcesoDos();

}else{ 



wait(NULL); 
wait(NULL); 


printf("SOy el PADRE"); 

exit(0);

}
}
}


void añosBisiestosProcesoUno(void){
int i = 0;

while (i < 2000) {
 
 if(((i%4) == 0 && i%100 != 0) || (i%4 == 0 && i%100 == 0 && i%400 == 0)){
 
 printf("EL año %i es bisiesto :D\n\r",i);
 sleep(1);
 
 }
 
 i++;
 }
 
 }
 
 
 void añosBisiestosProcesoDos(void){
int i = 2000;

while (i < 4000) {
 
 if(((i%4) == 0 && i%100 != 0) || (i%4 == 0 && i%100 == 0 && i%400 == 0)){
 
 printf("EL año %i es bisiesto :D\n\r",i);
 sleep(1);
 
 }
 
 i++;
 }
 
 }
 
 
 
 
 













