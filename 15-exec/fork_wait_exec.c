#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char numstr[15];
    pid_t filho;
    int rodando = 1;
    while (rodando) {
        int num;
        printf("Digite um número inteiro: ");
        scanf("%d", &num);

        filho = fork();
        if (filho == 0) {
            sprintf(numstr, "%d", num);
            char *args[] = {"./parexec", numstr, NULL};
            execvp(args[0], args);
            printf("exec falhou\n");
        } else {
            int status;
            if (wait(&status) != 0) {
                int retorno = (char) WEXITSTATUS(status);
                printf("%d\n", retorno);
                if (retorno == -1) {
                    printf("Negativo!\n");
                    rodando = 0;
                } else if (retorno == 1) {
                    printf("Par!\n");
                } else {
                    printf("Ímpar!\n");
                }
            }
        }
    }
}