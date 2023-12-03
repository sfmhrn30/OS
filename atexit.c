#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// File Discriptors
int fd1;
int fd2;

void functionA()
{ // Exit Handler
    close(fd1);
    printf("We are in  functionA and closed the file \n");
}

void functionB()
{ // Exit Handler
    close(fd2);
    printf("We are in  functionB and closed the file \n");
}

int main()
{
    /* register the termination function */
    char buf[10];
    fd1 = open("kk.txt", O_RDONLY, 742); // kk.txt should present in current folder
    fd2 = open("kk1.txt", O_RDONLY, S_IRWXU | S_IRGRP | S_IXOTH);

    read(fd1, buf, 10);
    write(1, buf, 10);
    printf("\nCompleted the operation A \n");
    atexit(functionA);

    read(fd2, buf, 10);
    write(1, buf, 10);
    printf("\nCompleted the operation B \n");
    atexit(functionB);

    printf("Starting  main Program...\n");

    printf("Exiting main Program...\n");

    return (0);
}
