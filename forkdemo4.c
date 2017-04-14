#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("child process\n");
        execv("/bin/ls", "./");
        exit(127);
    }
    else 
    {
        wait(NULL);
        printf("parent process\n");
    }
    return 0;
}
