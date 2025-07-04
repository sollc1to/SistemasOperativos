#include <xinu.h>
void funcionProcesoUno(int inicio, int fin, int n);

void ejerciciobisiestos(void){
int pid1,pid2;
pid1 = create(funcionProcesoUno, 1024, 20, "Proceso uno",3,0,2000,1);
pid2 = create(funcionProcesoUno, 1024, 20, "Proceso dos",3, 2000,4000,2);

resume(pid1);


resume(pid2); 


printf("Soy el padre"); 


exit(); 
//EN este caso generamos dos procesos zombies. 

}


void funcionProcesoUno(int inicio, int fin, int n) {

for(int i = inicio; i<=fin; i++){

if( (i%4 == 0 && i % 100 != 0) || (i% 400 == 0)){

printf("El hijo %d encontro el año bisiesto %d\n\r",n,i); 
}
}

}




