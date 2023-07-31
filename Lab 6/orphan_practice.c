#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{

    pid_t my_pid, parent_pid, child_pid;

    child_pid = fork();

    if (child_pid == 0)
    {
        printf("[CHILD]This is the child process.\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[CHILD] My PID = %d\n", my_pid);
        printf("[CHILD] Parent's PID = %d\n", parent_pid);
        printf("[CHILD] Sleeping for 10 seconds\n");
        sleep(10);
        printf("\n[CHILD] My parent has ended, so I am an orphan process, adopted by init process\n");
    }
    else if (child_pid > 0)
    {
        printf("[PARENT]This is the parent process.\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[PARENT] My PID = %d\n", my_pid);
        printf("[PARENT] Parent's PID = %d\n", parent_pid);
        printf("[PARENT] Exiting\n");
        return;
    }
}