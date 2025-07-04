#include <xinu.h>

void ejercicio_10(void){

control(CONSOLE,TC_MODER,0,0);

    int cantidadIntentos = 6;
    int intentosR = 0;
    int cantLetras =  8;
    int tamPalabra = 8;
    int letraC = 0;

    char palabra [] = "Mariposa";
    char estado [] = "________";    
    char letraIngresada;
  
    

    while(cantLetras != 0 && intentosR < cantidadIntentos){
    //Ingresa una letra
   
    kprintf("Ingresa una letra :)\n\r");

    letraIngresada = getc(CONSOLE);
    
    for(int i = 0; i < tamPalabra; i++){
    //Comparamos si existe alguna letra igual a la ingresada
        
      if( letraIngresada == palabra[i] && palabra[i] != '-'){ //LetraIngresada != de una letra que ya se adivinó. 
    //En este caso, debemos actualizar el estado 
        estado[i] = letraIngresada;
        palabra[i] = '-';
        //Resto uno a la cantidad de letras totales
        cantLetras = cantLetras-1;
        kprintf("La letra es correcta :)\n\r");

       if(letraC == 0){
    //Utilizo esto para ver si debo restar la cantidad de inte
        letraC = 1;
        }
            


       }

 

     }

    if(letraC == 0){
      kprintf("La letra es incorrecta. :(\n\r");
    intentosR = intentosR+1;
        }else{ 
        letraC = 0; }
 
 kprintf("Palabra: %s", estado);

}

if(intentosR == cantidadIntentos && cantLetras != 0 ){
    kprintf("No encontró la palabra ingresada! se quedó sin intentos :(\n\r");
}else { 
    kprintf("Encontró la palabra! :) La palabra es Mariposa ｡⋆｡˚ ʚɞ ˚｡⋆\n\r");
}



control(CONSOLE,TC_MODEC,0,0);
}
