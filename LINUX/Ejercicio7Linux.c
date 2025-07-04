Ejercicio_7Linux.c


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>



void main(void){
int pid;

pid = fork(); //Llama nuevo proceso


if (pid == 0) {
	funcionUno();}
	else{
		funcionUno();
		}

}


    
    void funcionUno(void){
    int esPrimo = 1; 
  
    for( int i = 1000; (i <= 5000); i++){
    //Por cada numero, vemos si es divisible x 1 y por si mismo 
      for(int j = 2 ; j < i; j++){
        if ((i % j) == 0) { 
          esPrimo = 0;
          break;
          }
        }
        
        if(esPrimo == 1) {
        printf("EL numero %d es primo",i);
        
        }else{
        esPrimo = 1;}
        
      }
    }
    
      



void funcionDos(){
int esPrimo = 1; 
  printf("El 2 es primo");
  
  for( int i = 3; (i <= 1000); i++){
    //Por cada numero, vemos si es divisible x 1 y por si mismo 
      for(int j = 2 ; j < i; j++){
        if (( i % j )== 0) { //Si es divisible x otro numero aparte de sí mismo, no es primo.
          esPrimo = 0;
          break;
          }
        }
        
        if(esPrimo == 1) {
        printf("EL numero %d es primo",i);
       
        }else{ esPrimo = 1;}
  
        
        
        
    }
    printf("FINALIZO MI PROCESO HIJO");
    kill(0, SIGKILL);
    }
    
    
    












