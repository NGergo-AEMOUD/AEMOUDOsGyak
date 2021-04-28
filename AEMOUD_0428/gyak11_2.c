#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
    //wait
    sem_wait(&mutex);
    printf("\nBelépés..\n");

    //critical section
    printf("child[2] --> pid = %d and ppid = %d\n", getpid(), getppid());
    //signal
    printf("Kilépés...\n");
    sem_post(&mutex);
}
// Driver code
int main()
{
    int pid, pid1, pid2;

    // variable pid will store the
    // value returned from fork() system call
    pid = fork();

    // If fork() returns zero then it
    // means it is child process.
    if (pid == 0) {

        // First child needs to be printed
        // later hence this process is made
        // to sleep for 3 seconds.
        sleep(3);

        // This is first child process
        // getpid() gives the process
        // id and getppid() gives the
        // parent id of that process.
        printf("\nchild[1] --> pid = %d and ppid = %d\n", getpid(), getppid());
        sem_destroy(&mutex);
    }

    else {
        pid1 = fork();
        if (pid1 == 0) {

        }
        else {
            pid2 = fork();
            if (pid2 == 0) {
                // This is third child which is
                // needed to be printed first.
                printf("child[3] --> pid = %d and ppid = %d\n", getpid(), getppid());

                sem_init(&mutex, 0, 1);
                pthread_t t1,t2;
                pthread_create(&t1,NULL,thread,NULL);
                sleep(2);
                pthread_create(&t2,NULL,thread,NULL);
                pthread_join(t1,NULL);
                pthread_join(t2,NULL);
            }

            // If value returned from fork()
            // in not zero and >0 that means
            // this is parent process.
            else {
                // This is asked to be printed at last
                // hence made to sleep for 3 seconds.
                sleep(3);
                printf("parent --> pid = %d\n", getpid());
            }
        }
    }

    return 0;
