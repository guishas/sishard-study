#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("Eu sou o processo pai, pid=%d, meu id do programa é %d\n", getpid(), 0);

    for (int i = 1; i <= 8; i++) {
        pid_t filho = fork();
        if (filho == 0) {
            printf("Eu sou o processo filho, pid=%d, ppid=%d, meu id do programa é %d\n", 
                    getpid(), getppid(), i);
            return 0;
        } 
    }

    return 0;
}