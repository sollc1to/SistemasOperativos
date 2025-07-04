#include <stdio.h>
int main(){

printf("Tamaño long : %zu bytes \n",  sizeof(long));
printf("Tamaño double: %zu bytes\n", sizeof(double));

printf("Tamaño entero: %zu bytes\n", sizeof(int));
printf("Tamaño char: %zu bytes\n", sizeof(char));
printf("Tamaño char sin signo: %zu bytes\n", sizeof(unsigned char));
printf("Tamaño float: %zu bytes\n", sizeof(float));
printf("Tamaño long double: %zu bytes\n",sizeof(long double));
return 0;

}



