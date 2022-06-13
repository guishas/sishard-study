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
        printf("%d\n", getpid());
        return 1;
        while (1) {
            
        }
    } else {
        int status;
        int wstatus;
        sleep(10);
        
        if (waitpid(filho, &wstatus, WNOHANG) == 0) {
            kill(filho, SIGINT); // SIGINT = 2
        }

        if (wait(&status) == filho) {
            printf("Terminou normalmente - %d\n", WIFEXITED(status));
            printf("Terminou com sinal - %d\n", WIFSIGNALED(status));
            printf("%d - %s\n", WTERMSIG(status), strsignal(WTERMSIG(status)));
        }
    }

    return 0;
}