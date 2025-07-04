/*Desarrollar tres programas en XINU (tres procesos) que verifican si un número es primo y/o es un año
bisiesto.
El proceso principal, debe esperar una entrada del usuario, y luego, debe utilizar algún mecanismo de
comunicación apropiado para enviar la entrada del usuario a los procesos restantes.
El proceso 2 verifica si el número es primo y reporta el resultado al proceso principal.
El proceso 3 verifica si el número es un año bisiesto y reporta el resultado al programa principal.
Ambos procesos deben reportar el resultado usando el mismo mecanismo de comunicación que usó el
programa principal.
El programa principal reporta si el número ingresado por el usuario es primo y/o año bisiesto.
Para leer una entrada del usuario en la CONSOLA y convertirlo en un número entero (las entradas en la
consola son “cadenas de texto”), aquí hay un código de ayuda:*/



#include <xinu.h>

int pid1,pid2,pid3;


void inicio(){

control(CONSOLE,TC_MODER,0,0);
pid1 =resume(create(principal,1024,20,"proceso 1",0));
pid2 =resume(create(bisiesto,1024,20,"proceso 2",0));
pid3 =resume(create(primo,1024,20,"proceso 3",0));



control(CONSOLE,TC_MODEC,0,0);

}

void principal(void){
int numero;

char buf[10];


printf("Ingrese el numero a verificar si es bisiesto o primo :)");

read(CONSOLE,buf,10);

numero = atoi(buf);

send(pid2,numero);
send(pid3,numero); 


int r1 = receive(); //0 es bisiesto, 1 no es bisiesto, 2 es primo, 3 no es primo
int r2 = receive();


switch(r1+r2){
case 2: printf("El numero es bisiesto y no es primo");
break;
case 3: //tiene dos casos
if(r1 == 1 || r2 == 1){ 
printf("El numero no es bisiesto y no es primo");

}else{ 
printf("El numero es bisiesto   es primo");}

case 4: pirntf("El numero es primo y no bisiesto");
break;



}



void bisiesto(void){

int n = receive(); //Recibe el numero a analizar


if(n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {

send(pid1,0);

}else{
send(pid1,1);



}

}


void primo(void){


int n = receive(); //Recibe el numero 


int i = 2, prim = 2; 


while(i < n && prim == 2){

if (i%n == 0){
prim = 3; 

}

i++;





}


send(pid1,prim);


}














