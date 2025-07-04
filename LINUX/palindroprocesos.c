#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h> 
#include<sys/types.h>
#include <sys/wait.h>

int verificarPalindromo(char arreglo[20], int longitud); 
char arreglo [20];
int main (){ 
system("/bin/stty raw");

int i = 0, longitud, resultado = 1, pid1, pid2;
char letraI;


printf("Veamos si una palabra es o no capicua\n\r"); 
printf("Presione enter para terminar la palabra o número\n\r"); 


pid1 = fork(); 

if(pid1 == 0){ //EL proceso uno carga la palabra




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
printf("EL proceso uno duerme");
sleep(50);

}else {
waitpid(pid1,NULL,0);

if(i > 1){ 


longitud = i-1;

i =0;

printf("Primer caracter %c y ultimo %c \n\r",arreglo[i],arreglo[longitud]);



pid2 = fork(); 

printf("Soy el proceso dos");

if (pid2 == 0){


//Verificamos si es palindromo

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

printf("EL proceso dos duerme");

sleep(80);

}else{
waitpid(pid2,NULL,0);
printf("SOy el padreee");
kill(pid1,SIGKILL);
kill(pid2,SIGKILL);

if (resultado ==1){ 
printf("Es palindromo la pabalra o capicua el numero :) \n\r"); 


}else{ 
printf("NO es palindromo ni capicua\n\r"); 

}
}
}else{ 
waitpid(pid1,NULL,0);
printf("Hay un solo caracter y es palindromo");
printf("SOy el padreee");

}
}

system("/bin/stty sane erase ^?");
}













