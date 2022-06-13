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
        while (1) {
            
        }
    } else {
        int status;
        sleep(10);
        kill(filho, SIGINT); // SIGINT = 2
        if (wait(&status) == filho) {
            printf("%s\n", strsignal(WIFEXITED(status)));
            printf("%s\n", strsignal(WIFSIGNALED(status)));
            printf("%s\n", strsignal(WTERMSIG(status)));
        }
    }

    return 0;
}