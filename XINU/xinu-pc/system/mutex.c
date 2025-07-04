#include <xinu.h>


int mutex_lock();
int mutex_unlock();
void mutex_init();
int32 pid = -1;


sid32 semaforo;


void mutex_init(){ //En caso de que la creación de error, el mismo crear del semáforo devuelve error.


  semaforo = semcreate(1);
  
}


int mutex_lock(){


wait(semaforo); 

pid = getpid(); 
return 1;

}



int mutex_unlock(){

if(pid == getpid()){ //Verificamos que el mismo proceso sea el que quiera desbloquearlo

signal(semaforo);

pid = -1; //Reiniciamos el pid


return 1;

}else{ 
return -1; //El mismo proceso intenta hacer lock dos veces. 
}

}










