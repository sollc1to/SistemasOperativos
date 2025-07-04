#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>


#define N 240000
#define BSIZE 4096
#define SMALL 4

char *pp; 

int main(){
int i,j,k; 

pp = malloc(N*BSIZE); 
printf("%d",getpid());

if (pp == NULL){
printf("Error al reservar memoria.\n"); 
sleep(10);
exit(1);


}

/*RECORREMOS y modificamos todo el segmento solicitado*/ 
for(j=0; j<BSIZE;j++){
for(i=0;i<N;i++){
*(pp+i+BSIZE+j) = 2; // pp[i][j] = 2;
/*RECORREMOS Y VERIFICAMOS QUE HEMOS MODIFICADO todo el segmento*/ 




}
}



for(i=0;i<N;i++){
for(j=0;j<BSIZE;j++){
if(*(pp+i*BSIZE+j) != 2){
printf("ERROR! \n");
sleep(10);
exit(1); 


}


}
}


printf("OK\n"); 
sleep(10);

}
