#include <xinu.h> 

void produce(void), consume (void); 

int32 n = 0; 
sid32 semp, semc;

void ejercicio1tp3(void) {
semp = semcreate(1);
semc = semcreate(0);

resume(create(consume,1024,20,"cons",0)); 
resume(create(produce,1024,20,"prod",0)); 

}


void produce(void) { 

int32 i; 

for(i = 1; i <= 2000; i++){ 
wait(semp);
printf("EL productor produce");
n++;
signal(semc);
}
}


void consume(void) { 

int32 i; 
for(i = 1; i <= 2000; i++){ 
wait(semc);
printf("EL valor de n es %d ", n); 
signal(semp);

}
}

