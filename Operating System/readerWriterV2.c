#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int readerCount = 0, writerCount = 0;
sem_t rmutex, wmutex, readTry, resource;
int count = 0;

void *reader(void *temp)
{
    sem_wait(&readTry);
    sem_wait(&rmutex);
    readerCount++;
    if(readerCount == 1)
        sem_wait(&resource);
    sem_post(&rmutex);
    sem_post(&readTry);
    printf("counter value in reader %d\n",count);

    sem_wait(&rmutex);
    readerCount--;
    if(readerCount == 0)
        sem_post(&resource);
    sem_post(&rmutex);
    
}

void *writer(void *temp)
{
    sem_wait(&wmutex);
    writerCount++;
    if(writerCount == 1)
        sem_wait(&readTry);
    sem_post(&wmutex);

    sem_wait(&resource);
        count++;
        printf("writer changed value to %d\n",count);
    sem_post(&resource);
    
    sem_wait(&wmutex);
    writerCount--;
    if(writerCount == 0)
        sem_post(&readTry);
    sem_post(&wmutex);
}

int main()
{
    pthread_t t1[10],t2[10];
    sem_init(&rmutex, 0, 1);
    sem_init(&wmutex, 0, 1);
    sem_init(&resource, 0, 1);
    sem_init(&readTry, 0, 1);
    for(int i=0;i<10;i++) 
    {
        pthread_create(&t2[i],NULL,writer,NULL);
        pthread_create(&t1[i],NULL,reader,NULL);
    }
    for(int i=0;i<10;i++) 
    {
        pthread_join(t2[i],NULL);
        pthread_join(t1[i],NULL);
    }

    sem_destroy(&rmutex);
    sem_destroy(&wmutex);
    sem_destroy(&resource);
    sem_destroy(&readTry);

    return 0;
}
