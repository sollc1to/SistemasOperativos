#include <stdio.h> 
#include <stdlib.h> 

int verificarCaracteres(void);
char [] arreglo = char [20];

int longitud;

int main (){ 
int i = 0;
char letraI;


printf("Veamos si una palabra es o no capicua"); 


printf("Presione enter para terminar la palabra o número"); 

while(letraI != 13 && i < 20){

printff("Ingrese la letra :)"); 

letraI = getchar();

arreglo[i] = letraI; 
i++; 
}

longitud = i+1;

i = verificarCaracter(); 

if (i ==1){ 
printf("Es palindromo la pabalra o capicua el numero :) "); 


}else{ 
printf("NO es palindromo ni capicua"); 

}

}


int verificarCaracter(){

int resultado = 1, i =0;


while(resultado == 1 && arreglo[i] == arreglo[longitud]){
printf("Primer caracter %c y ultimo %c",arreglo[i],arreglo[longitud]);

if (arreglo[i] != arreglo[longitud]){ 

resultado = 0;
}else{ 
i = i+1; 
longiutd--;

}





return resultado;






}

}
















