#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void funcionUno(void);
void funcionDos(void);

int main(void) {
  int pid = fork();
    if(pid == 0){
      funcionUno();
      }else{
        funcionDos();    
            
    kill(pid,SIGKILL);
    exit(0);
    

  }
    return 0; 
    }
    
        
        
  void funcionUno(void){
  int esPrimo = 1;
    for (int i = 1000; i<=5000;i++){
      
      
      for(int j=2; j<i; j++){
      
      if( (i%j) ==0){
        esPrimo = 0;
        break;
        }
        }
        
        if(esPrimo){
        printf("El numero %d es primo\n", i); 
        }else{
        esPrimo = 1;}
        
        }
        }
        
        
  void funcionDos(void){
  printf("El 2 es primo\n");
  int esPrimo = 1;
  for(int i = 3; i <= 1000; i++){
    
    for (int j = 2; j<i;j++){
    
    if (i % j == 0){
    esPrimo = 0;
    break;
    }
    }
    if(esPrimo){
    printf("El numero %d es primo\n",i);
    }
    
    }
    
    printf("FInalizo mi proceso HIJO\n"); 

  
  }
  
  
        
