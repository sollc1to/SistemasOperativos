#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>


void main(void){
int pid;
int x=0;
pid = fork();

if(pid == 0){
printf("Soy el hijo");
sleep(1);
execv("/bin/date",NULL); //Proceso hijo cambia su imagen 

}else{

sleep(5);
printf("Se despertó el padre\n");
  exit(0);
  }

}


    








