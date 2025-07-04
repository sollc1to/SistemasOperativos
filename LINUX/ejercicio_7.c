#include <xinu.h> 
#include <stdio.h>

  void funcionUno (void),
  int funcionDos(int); 
  
  
  ejercicio_7(){
  int pidHijo;
  
  
  pidHijo = create(funcionUno, 2048,20,"Proceso hijo", 0); //Creo mi proceso hijo 
  
  funcionDos(pidHijo);

  
  resume(pidHijo);
  
  
  }
  
  
  
  
  
  funcionDos(int pid){
  int esPrimo = 1; 
  printf("El 2 es primo");
  
  for( int i = 3; i <= 1000 < i++){
    //Por cada numero, vemos si es divisible x 1 y por si mismo 
      for(int j = 2 ; j < i; j++){
        if (i % j == 0) { //Si es divisible x otro numero aparte de sí mismo, no es primo.
          esPrimo = 0;
          break;
          }
        }
        
        if(esPrimo = 1) {
        printf("EL numero %d es primo",i);
        esPrimo = 0; 
        }
        
        
        
        
    }
    printf("FINALIZO MI PROCESO HIJO");
    kill(pid);
    
    exit();
    
    
  }
  
    
    
    funcionUno(void){
    int esPrimo = 1; 
  
    for( int i = 1000; i <= 5000 < i++){
    //Por cada numero, vemos si es divisible x 1 y por si mismo 
      for(int j = 2 ; j < i; j++){
        if (i % j == 0) { 
          esPrimo = 0;
          break;
          }
        }
        
        if(esPrimo = 1) {
        printf("EL numero %d es primo",i);
        esPrimo = 0; 
        }
      }
    }
    
        
          
      
      
    
    

  
  
  

