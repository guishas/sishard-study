// Leia o PDF ou MD antes de iniciar este exercício!


// Faça os includes necessários aqui
// #include ...
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t sem1, sem2, sem3, sem4;

void *thread1(void *_arg) {
    printf("A\n");
    sem_post(&sem1);
    sem_post(&sem1);
    sem_post(&sem1);
    
    sem_wait(&sem2);
    sem_wait(&sem3);
    sem_wait(&sem4);
    printf("E\n");

    return NULL;
}

void *thread2(void *_arg) {
    sem_wait(&sem1);
    printf("B\n");
    sem_post(&sem2);
    return NULL;
}

void *thread3(void *_arg) {
    sem_wait(&sem1);
    printf("C\n");
    sem_post(&sem3);
    return NULL;
}

void *thread4(void *_arg) {
    sem_wait(&sem1);
    printf("D\n");
    sem_post(&sem4);
    return NULL;
}

int main(int argc, char *argv[]) {
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    sem_init(&sem4, 0, 0);

    // Crie TODAS as threads em um laço. Voce deve utilizar semaforos para sincronizacao.
    pthread_t tid1, tid2, tid3, tid4;
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_create(&tid3, NULL, thread3, NULL);
    pthread_create(&tid4, NULL, thread4, NULL);


    // Espere por TODAS as threads
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