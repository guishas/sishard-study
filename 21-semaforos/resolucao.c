#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t sem1, sem2;

void *thread1(void *arg) {
    printf("A\n");
    sem_post(&sem1);
    sem_wait(&sem2);
    printf("C\n");
}

void *thread2(void *arg) {
    printf("B\n");
    sem_post(&sem2);
    sem_wait(&sem1);
    printf("D\n");
}

int main() {
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);

    return 0;
}