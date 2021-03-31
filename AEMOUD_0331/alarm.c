#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#define SECOND 1

void do_nothing();
void do_int();

int main ()
{
	int i;
	unsigned sec=1;

	signal(SIGINT, do_int);

for (i=1;i<100;i++) {
	alarm(sec);
	signal(SIGALRM, do_nothing);
	printf("  %d Varakozas...\n",i);
	pause();
    }
}
void do_nothing(){ ;}

void do_int() {
	printf(" int jott ");
	signal(SIGINT,SIG_IGN);
}
