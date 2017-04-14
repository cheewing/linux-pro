#include <stdio.h>

#define DELAY 2

int main()
{
    int newpid;

    newpid = fork();

    if (newpid == -1)
    {
        perror("fork");
        exit(1);
    } 
    else if (newpid == 0)
        child_code(DELAY);
    else
        parent_code();
    
    exit(0);
}

void child_code(int delay)
{
    printf("child\n");
    sleep(delay);
}

void parent_code()
{
    printf("parent\n");
}
