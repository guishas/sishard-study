#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t filho;
    int rodando = 1;
    int stat;

    filho = fork();

    if (filho == 0) {
        sleep(5);
        printf("Acabei filho\n");
        exit(0);
    } else {
        while (rodando) {
            printf("Esperando o filho acabar!\n");
            sleep(1);
            if (waitpid(filho, &stat, WNOHANG) > 0) {
                rodando = 0;
            }
        }
    }
    return 0;
}
