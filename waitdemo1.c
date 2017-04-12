#include <stdio.h>

#define DELAY 2

main()
{
    int pid;
    void child_code(), parent_code();

    printf("before: my pid is %d\n", getpid());

    if((pid = fork()) == -1)
        perror("fork");
    else if (pid == 0)
        child_code(DELAY);
    else
        parent_code(pid);

    exit(0);
}

void child_code(int delay)
{
    printf("my pid is %d. will sleep %d seconds.\n", getpid(), delay);
    sleep(delay);
    printf("child done. about to exit\n");
    exit(17);
}

void parent_code(int pid)
{
    int wait_rv;
    wait_rv = wait(NULL);
    printf("done waiting for %d. Wait returned %d\n", pid, wait_rv);
}
