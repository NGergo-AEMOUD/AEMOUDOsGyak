#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <unistd.h>
#define SEMKEY 123456L

	int semid,
	    nsems,
	    semnum,
	    rtn;

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
	printf ("\n kerem a semval erteket ");

	semnum = 0;

	cmd = SETVAL;
	scanf("%d",&arg);
	rtn = semctl(semid,semnum, cmd, arg);

	printf("\n set  rtn: %d ,semval: %d ",rtn,arg);
	printf("\n");

}
