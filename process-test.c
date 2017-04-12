#include <stdio.h>
#include <unistd.h>

int g_a = 1;

int main()
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("child, pid = %d\n", getpid());
    }
    else 
    {
        printf("parent, pid = %d\n", getpid());
        sleep(2);
    }

    exit(0);
}
