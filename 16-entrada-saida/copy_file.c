/* POSIX headers */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Standard C */
#include <stdio.h>

int main(int argc, char *argv[]) {
    char buf[10];

    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY, 0700);

    while (read(fd1, buf, 10) != 0) {
        write(fd2, buf, 10);
    }

    close(fd1);
    close(fd2);
    return 0;
}