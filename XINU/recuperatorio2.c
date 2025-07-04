
#include <xinu.h>

int total = 0;
#define MAX 500000
void  encontrar_primos(int from, int to);



void recuperatoriodos(void){

encontrar_primos(1,MAX);
printf("Total: %d\n", total);


}

void encontrar_primos(int from, int to)
 {
         int i, n, primo;
         printf( "\n   " );

          for ( i = from ; i <= to ; i++ ) {
                  primo = 1;
                  n = 2;

                   while ( n <= i / 2 && primo ) {
                           if ( i % n == 0 )
                                   primo = 0;

                            n++;
                   }

                   if ( primo )
                           printf( "%d \n", i );
          }

          total++;
 }


