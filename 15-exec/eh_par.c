#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 2 || atof(argv[1]) == 0) {
        printf("Erro!\n");
        return -2;
    }

    int num = (int) atol(argv[1]);

    if (num < 0) {
        return -1;
    } else if (num % 2 == 0) {
        return 1;
    } else if (num % 2 != 0) {
        return 0;
    } 

    return 0;
}
