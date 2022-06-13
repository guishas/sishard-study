#include <pthread.h>
#include <stdio.h>

void *thread1(void *arg) {
    printf("Hello thread 1!\n");
    return NULL;
}

void *thread2(void *arg) {
    printf("Hello thread 2!\n");
    return NULL;
}

void *thread3(void *arg) {
    printf("Hello thread 3!\n");
    return NULL;
}

void *thread4(void *arg) {
    printf("Hello thread 4!\n");
    return NULL;
}


int main() {
    pthread_t tid;
    
    int error1 = pthread_create(&tid, NULL, thread1, NULL);

    int error2 = pthread_create(&tid, NULL, thread2, NULL);

    int error3 = pthread_create(&tid, NULL, thread3, NULL);

    int error4 = pthread_create(&tid, NULL, thread4, NULL);

    

    printf("Hello main\n");
    
    return 0;
}
