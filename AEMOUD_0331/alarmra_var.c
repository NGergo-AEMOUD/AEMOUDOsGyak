#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void do_nothing();


int main ()
{


	signal(SIGALRM, do_nothing);
	printf(" Varakozas...\n");
	pause();
    	printf("Jel megerkezett!\n");
}
void do_nothing(){ ;}
}
