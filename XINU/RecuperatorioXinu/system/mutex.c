#include <xinu.h> 

void mutex_init();
void mutex_lock(), mutex_unlock();

int32 pid = -1;

sid32 semaforo;

void mutex_init(){ //En caso de que la creación de error, el mismo crear

semaforo = semcreate(1);

}

void mutex_lock(){
wait(semaforo);
pid = getpid();
}

void mutex_unlock(){
if(pid == getpid()){ //Verificamos que el mismo proceso sea el que quiera

pid =-1;
signal(semaforo);

}
}

