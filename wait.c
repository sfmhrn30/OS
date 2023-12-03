#define _POSIX_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    pid_t pid;
    time_t t;
    int status;
    if ((pid = fork()) < 0)
        perror("fork() error");
    else if (pid == 0)
    {
        time(&t);
        printf("child (pid %d) started at %s", (int)getpid(), ctime(&t));
        sleep(5);
        time(&t);
        printf("child exiting at %s", ctime(&t));
        exit(42);
    }
    else
    {
        printf("parent has forked child with pid of %d\n", (int)pid);
        time(&t);
        printf("parent is starting wait at %s", ctime(&t));
        if ((pid = wait(&status)) == -1)
            perror("wait() error");
        else
        {
            time(&t);
            printf("parent is done waiting at %s", ctime(&t));
            printf("the pid of the process that ended was %d\n", (int)pid);
            if (WIFEXITED(status))
                printf("child exited with status of %d\n", WEXITSTATUS(status));
            else if (WIFSIGNALED(status))
                printf("child was terminated by signal %d\n",
                       WTERMSIG(status));
            else if (WIFSTOPPED(status))
                printf("child was stopped by signal %d\n", WSTOPSIG(status));
            else
                puts("reason unknown for child termination");
        }
    }
}
