
#include <xinu.h> 


void operar(void), incrementar(void); 
unsigned char x =0 ;
int result;


void ejercicio2tp3(void) { 

  mutex_init();


resume(create(operar,1024,20,"process 1",0)); 
resume(create(incrementar,1024,20,"process 2",0));


sleep(10); 
}



void operar(void) { 

int y =0; 

printf("SI no existen mensajes de ERROR entonces todo va OK \n"); 
while(1){
/*si x es multiplo de 10*/ 





if (mutex_lock() != -1){ //Si no hubo un error de lock

if((x%10) == 0) { 
y = x*2; 

/*si no es multiplo de 10 entonces hubo un error*/

if((y%10) != 0) {
printf("\r ERROR!! y = %d, x = %d \r",y,x); }

}
if(mutex_unlock() == -1){ 

printf("ERROR DE UNLOCK");
exit();

}

}else{

printf("ERROR DE LOCK");
exit();


}
}


}

void incrementar(void){
while(1){



if(mutex_lock() != -1) {

x = x+1;


if(mutex_unlock() == -1){
printf("ERROR DE UNLOCK");
exit();

}


}else{ 
printf("ERROR DE LOCK");
exit();






}
}

}

