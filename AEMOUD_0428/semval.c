#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 123456L


	int semid,nsems,rtn;
	int semflg;
	struct sembuf sembuf, *sop;
	int arg;
	int cmd;

main()
{


	nsems = 1;
	semflg = 00666 | IPC_CREAT;
	semid = semget (SEMKEY, nsems, semflg);
	if (semid < 0 ) {perror(" semget hiba"); exit(0);}
	else printf("\n semid: %d ",semid);
	printf ("\n");

	cmd = GETVAL;
	rtn = semctl(semid,0, cmd, NULL);

	printf("\n semval: %d ",rtn);
	printf("\n");

}
