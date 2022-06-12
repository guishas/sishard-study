#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char *proxima_linha(int fd) {
    int maxLineLength = 15;
    char *lineBuffer = malloc(sizeof(char) * maxLineLength);
    char buffer[1];

    if (lineBuffer == NULL) {
        printf("Falha ao alocar buffer.\n");
        exit(1);
    }

    int counter = 0;
    while (read(fd, buffer, 1) != 0 && buffer[0] != '\n') {
        
        if (counter == maxLineLength) {
            maxLineLength += 15;
            lineBuffer = realloc(lineBuffer, sizeof(char) * maxLineLength);

            if (lineBuffer == NULL) {
                printf("Erro ao realocar buffer.\n");
                exit(1);
            }
        }

        lineBuffer[counter] = (char) buffer[0];
        counter++;
    }

    if (counter == 0) {
        return NULL;
    }

    lineBuffer[counter] = '\0';

    return lineBuffer;
}


int main(int argc, char *argv[]) {

    char *nome = argv[1];
    int fd = open(nome, O_RDONLY);

    char *linha;
    int isNull = 0;
    while (!isNull) {
        linha = proxima_linha(fd);
        
        if (linha != NULL) {
            if (isupper(linha[0])) {
                printf("%s\n", linha);
                fflush(stdout);
            }
        } else {
            isNull = 1;
        }
    }

    free(linha);

    close(fd);

    return 0;
}
