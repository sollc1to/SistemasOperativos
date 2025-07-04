#include <xinu.h> 
#include <stdio.h>

  void funcionUno(void), funcionDos(void); 
  
  
  void ejercicio_7(){
  int pidHijo, pidHijoD;
  
  
  pidHijo = create(funcionUno, 2048,20,"Proceso hijo 1", 0); //Creo mi proceso hijo 
  pidHijoD = create(funcionDos, 2048, 30, "Proceso hijo 2", 0); //Le damos mas prioridad
  
  resume(pidHijo);
  resume(pidHijoD); 

  

  }
  

  
  void funcionDos( void){
  int esPrimo = 1; 
  int cantidadPrimos = 0;
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
        cantidadPrimos++; 
       
        }else{ esPrimo = 1;}
        
        
        
        
        if(cantidadPrimos == 100){
        printf("EL PROCESO  DOS SE DUERME");
        sleep(5);
      

        
        
        
    }
    
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
    
    
    
    
    
      
