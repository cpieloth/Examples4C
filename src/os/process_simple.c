#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> // pid_t
#include <sys/wait.h>
#include <unistd.h> // usleep, sleep

static int count = 0;

void child_process()
{
    const pid_t pid = getpid();
    printf("Child PID=%d\n", pid);
    printf("[%d] Count=%d\n", pid, count);
    sleep(2);
    printf("[%d] Count=%d\n", pid, count);
}

int main()
{
    const pid_t ppid = getpid();
    const int n_processes = 3;
    pid_t cpid;
    printf("Parent PID=%d\n", ppid);
    while (count < n_processes)
    {
        switch (cpid = fork())
        {
        case -1:
            perror("Fork error");
            break;
        case 0:
            child_process();
            exit(EXIT_SUCCESS);
        default:
            printf("Process forked.\n");
            ++count;
            printf("[%d] Count=%d\n", ppid, count);
            usleep((__useconds_t) 100e3);
            break;
        }  // switch
    }  // while

    while ((cpid = wait(NULL)) >= 0)
    {
        fprintf(stdout, "Waited for [%d]: %s\n", cpid, strerror(errno));
    }
    return EXIT_SUCCESS;
}
