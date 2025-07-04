#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>

void funcionUno(void);
void funcionDos(void);

int main(void) {
    int pid = fork();

    if (pid == 0) {
        funcionDos();
    } else {
        funcionUno();
    }
    
    
    return 0;
}

void funcionUno(void) {
    for (int i = 1000; i <= 5000; i++) {
        int esPrimo = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                esPrimo = 0;
                break;
            }
        }
        if (esPrimo) {
            printf("El numero %d es primo\n", i);
        }
    }
}

void funcionDos(void) {
    printf("El 2 es primo\n");
    for (int i = 3; i <= 1000; i++) {
        int esPrimo = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                esPrimo = 0;
                break;
            }
        }
        if (esPrimo) {
            printf("El numero %d es primo\n", i);
        }
    }
    printf("FINALIZO MI PROCESO HIJO\n");
    exit(0);
}
