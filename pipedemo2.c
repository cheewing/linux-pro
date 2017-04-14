#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd[2];
    int childpid;
    char buf[80];

    pipe(fd);

    if ((childpid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (childpid == 0)
    {
        close(1);
        dup2(fd[1], 1);
        close(fd[0]);
        execlp("ls", "ls", NULL);
    }
    else
    {
        close(0);
        dup2(fd[0], 0);
        close(fd[1]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}
