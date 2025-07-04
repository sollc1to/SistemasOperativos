#include <xinu.h>

void funcion1 (void);

ejercicio10(void){

  int pid1 = create( funcion1, 1024, 20, "Proceso 1, 0);
  
  resume(pid1);
  
  
  }
  
  
  void funcion1(void){
  
  
  sleep(5);
  
  suspend(gettpid());
  }
  
  
  
  
