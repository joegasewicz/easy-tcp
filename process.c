/**
 * Process:
 *  This is currently implementing separate PID's for the following:
 *      - Server
 *      - Client
 * */
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


void signal_handler(int signum)
{
    // Terminated child status
    int child_exit_status;
    pid_t child_pid;

    child_pid = wait(&child_exit_status);
}
