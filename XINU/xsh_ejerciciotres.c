#include <xinu.h>
#include <stdio.h>
void	sndA(void), sndB(void); //Declaramos la funciòn 
pid32 pidA, pidB;

xsh_ejerciciotres(){

printf("Holaaaaaaa");

pidA = create(sndA, 8192, 20, "process 1", 0) ;
pidB = create(sndB, 8192, 20, "process 2", 0) ;


resume(pidA);
resume(pidB);

sleep(10);

kill( pidA);
kill(pidB );


}   

void	sndA(void)
{
	while( 1)
		putc(CONSOLE, 'A');
}

/*------------------------------------------------------------------------
 * sndB  --  repeatedly emit 'B' on the console without terminating
 *------------------------------------------------------------------------
 */
void	sndB(void)
{
	while( 1 )
		putc(CONSOLE, 'B');
}
