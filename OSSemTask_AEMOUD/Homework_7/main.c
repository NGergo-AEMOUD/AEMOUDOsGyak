#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{

    sem_wait(&mutex);
    printf("\nSzemafor megnyitva!\n");


    FILE *fp;
    fp = fopen ("AEMOUD.txt", "w+");
    fputs("AEMOUD\n", fp);
    fclose(fp);
    printf("File írása megtörtént!");
    sleep(3);


    printf("\nSzemafor lezárása...\n");
    sem_post(&mutex);
}


int main()
{

    sem_init(&mutex, 0, 1);
    pthread_t t1;
    pthread_create(&t1,NULL,thread,NULL);
    pthread_join(t1,NULL);
    sem_destroy(&mutex);

    return 0;
}

