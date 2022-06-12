// Leia o PDF ou MD antes de iniciar este exercício!

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    char *origem;
    char *destino;
    char *valor;

    origem = argv[1];
    destino = argv[2];
    valor = argv[3];

    pid_t filho;
    int acabou = 0;
    while (!acabou) {
        filho = fork();
        if (filho == 0) {
            char *args[] = {"./siscoin", origem, destino, valor, NULL};
            execvp(args[0], args);
        } else {
            int wst;
            wait(&wst);
            int retorno = (char) WEXITSTATUS(wst);
            printf("%d\n", retorno);
            if (retorno == 0) {
                acabou = 1;
            } 
        }
    }

    printf("Transferencia realizada!\n");

    return 0;
}