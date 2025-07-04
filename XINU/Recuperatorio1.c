#include <xinu.h>

void numerosPrimos(void), numerosBisiestos(void);


void recuperatorio(){
int pid1, pid2;


pid1 = create(numerosPrimos,1024,30,"Proceso uno",0);

resume(pid1); 

pid2 = create(numerosBisiestos,1024,20,"Proceso dos",0);


printf("Soy el padre"); 

sleep(4); 
kill(pid2);
sleep(4);
kill(pid1);

printf("El padre finaliza"); 
exit();


}

void numerosPrimos(){ 
int j = 2;
int esPrimo = 1;

while(1){

for(int i = 2; i<j; i++){

if (j%i == 0){
esPrimo = 0;
break;
}

}
if(esPrimo == 0){
esPrimo = 1;
}else{ 
printf("El proceso uno encontró al número %d PRIMO\n\r", j);
}

j = j+1;

}
}


void numerosBisiestos(){

int i=1;
while(1){

if(( i%4 ==0 && i%100 !=0) || (i%400 ==0)){

printf("EL proceso dos encontro el año BISIESTO %d\n\r", i);
}
i++;

}
}







 








