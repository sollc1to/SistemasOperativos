#include <xinu.h>
void ingresarPalabra(void);
void verificarPalindromo(void); 

char arreglo [20];
int resultado =1;
int longitud =0;


int  palindromoXinu(){ 
int pid1, pid2; 
control(CONSOLE,TC_MODER, 0,0);

resume(create(ingresarPalabra,1024,20,"Proceso1",0)); 

receive(); 

resume(create(verificarPalindromo,1024,20,"Proceso2",0)); 


receive(); 


if (resultado ==1){ 
printf("Es palindromo la pabalra o capicua el numero :) \n\r"); 


}else{ 
printf("NO es palindromo ni capicua\n\r"); 

}

exit();


control(CONSOLE,TC_MODEC, 0,0);
}




void ingresarPalabra(void){
int i = 0, resultado = 1;
char letraI;


printf("Veamos si una palabra es o no capicua\n\r"); 


printf("Presione enter para terminar la palabra o número\n\r"); 


while( i < 20){

printf("Ingrese la letra :)\n\r"); 

letraI = getchar();

if(letraI == 13){
break;
}else{



arreglo[i] = letraI; 
i++; 
}
}

longitud = i-1;

}

void verificarPalindromo (void){ 
int i = 0;

while(resultado && i != longitud){
printf("Primer caracter %c y ultimo %c\n\r",arreglo[i],arreglo[longitud]);

if (arreglo[i] != arreglo[longitud]){ 
resultado =0;
break;

}else{ 
i = i+1; 
longitud--;
}

}

}















