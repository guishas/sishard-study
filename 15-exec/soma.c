#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double soma = 0;
    if (argc < 3) {
        printf("Erro!\n");
        return 0;
    } else {
        for (int i = 1; i < argc; i++) {
            soma += atof(argv[i]);
        }

        printf("Soma: %d\n", (int) soma);
    }
    
    return 0;
}
