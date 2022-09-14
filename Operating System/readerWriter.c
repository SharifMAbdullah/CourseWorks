#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int readerCount = 0;
sem_t rmutex, resource;
int count = 0;

void *reader(void *temp)
{
    sem_trywait(&rmutex);
    readerCount++;
    if(readerCount == 1)
        sem_trywait(&resource);
    sem_post(&rmutex);
    printf("counter value in reader %d\n",count);

    sem_trywait(&rmutex);
    readerCount--;
    if(readerCount == 0)
        sem_post(&resource);
    sem_post(&rmutex);
    
}

void *writer(void *temp)
{
   
    sem_trywait(&resource);
        count++;
        printf("writer changed value to %d\n",count);
    sem_post(&resource);
    
}

int main()
{
    pthread_t t1[10],t2[10];
     for(int i=0;i<10;i++) pthread_create(&t1[i],NULL,reader,NULL);
     for(int i=0;i<10;i++) pthread_create(&t2[i],NULL,writer,NULL);
     for(int i=0;i<10;i++) pthread_join(t1[i],NULL);
     for(int i=0;i<10;i++) pthread_join(t2[i],NULL);
}
