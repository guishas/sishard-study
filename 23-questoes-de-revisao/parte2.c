// linha de compilação: 

/* declarar tarefas aqui e lançar no main */
/* cada bloco na figura deverá ser representado por um print com sua letra */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t sem1, sem2, sem3, sem4;

void *thread1(void *arg) {
    printf("A\n");
    sem_post(&sem1);
    sem_wait(&sem2);
    printf("C\n");
}

void *thread2(void *arg) {
    printf("B\n");
    sem_post(&sem2);
    sem_post(&sem2);
    sem_post(&sem2);
    sem_wait(&sem1);
    sem_wait(&sem3);
    sem_wait(&sem4);
    printf("D\n");
}

void *thread3(void *arg) {
    printf("E\n");
    sem_post(&sem3);
    sem_post(&sem3);
    sem_wait(&sem2);
    sem_wait(&sem4);
    printf("F\n");
}

void *thread4(void *arg) {
    printf("G\n");
    sem_post(&sem4);
    sem_post(&sem4);
    sem_wait(&sem2);
    sem_wait(&sem3);
    printf("H\n");
}

int main(void) {
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    sem_init(&sem4, 0, 0);

    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;

    int erro1 = pthread_create(&tid1, NULL, thread1, NULL);
    int erro2 = pthread_create(&tid2, NULL, thread2, NULL);
    int erro3 = pthread_create(&tid3, NULL, thread3, NULL);
    int erro4 = pthread_create(&tid4, NULL, thread4, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);
    sem_destroy(&sem4);

    return 0;
}
