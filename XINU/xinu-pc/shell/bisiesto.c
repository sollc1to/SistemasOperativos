#include <xinu.h>

void añosBisiestosProcesoUno(void), añosBisiestosProcesoDos(void);




void añoBisiesto(){


resume(create(añosBisiestosProcesoUno,1024,20,"Proceso uno",0));

receive(); 
resume(create(añosBisiestosProcesoDos,1024,20,"Proceso dos",0));

receive(); 


printf("Soy el PADRE"); 

exit();


}


void añosBisiestosProcesoUno(void){
int i = 0;

while (i < 2000) {
 
 if(((i%4) == 0 && i%100 != 0) || (i%4 == 0 && i%100 == 0 && i%400 == 0)){
 
 printf("EL año %d es bisiesto :D\n\r",i);

 
 }
 
 i++;
 }
 
 }
 
 
 void añosBisiestosProcesoDos(void){
int i = 2000;

while (i < 4000) {
 
 if(((i%4) == 0 && i%100 != 0) || (i%4 == 0 && i%100 == 0 && i%400 == 0)){
 
 printf("EL año %d es bisiesto :D\n\r",i);

 }
 
 i++;
 }
 
 }
 
 
 
 
 













