#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int fd[2];
    char *str = "hello world\n";
    char buf[80];
    int pid;

    pipe(fd);

    if ((pid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        close(fd[0]);
        write(fd[1], str, strlen(str));
        exit(0);
    }
    else
    {
        read(fd[0], buf, sizeof(buf));
        printf("%s", buf);
        return 0;
    }

    return 0;
}
