#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

int main() {
    pid_t filho;

    filho = fork();
    if (filho == 0) {
        printf("Meu pid: %d\n", getpid());
        int i = 10;
        while (1) {
            printf("Vou morrer em %d\n", i);
            sleep(1);
            i--;
        }
    } else {
        int status;
        int wstatus;
        sleep(10);
        
        if (waitpid(filho, &wstatus, WNOHANG) == 0) {
            printf("Ainda está executando! Vou matar...\n");
            kill(filho, SIGKILL); // SIGINT = 2
        }

        if (wait(&status) == filho) {
            printf("Terminou normalmente - %d\n", WIFEXITED(status));
            printf("Terminou com sinal - %d\n", WIFSIGNALED(status));
            printf("Finalizado com o sinal - %d\n", WTERMSIG(status));
            printf("Erro - %s\n", strsignal(WTERMSIG(status)));
        }
    }

    return 0;
}