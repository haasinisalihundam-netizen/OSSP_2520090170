#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "executor.h"

int execute_command(char *args[])
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return -1;
    }

    if (pid == 0)
    {
        /* Child process */
        execvp(args[0], args);

        /* This executes only if execvp fails */
        perror(args[0]);
        _exit(127);
    }

    /* Parent process */
    int status;

    while (waitpid(pid, &status, 0) == -1)
    {
        if (errno != EINTR)
        {
            perror("waitpid");
            return -1;
        }
    }

    if (WIFEXITED(status))
    {
        return WEXITSTATUS(status);
    }

    if (WIFSIGNALED(status))
    {
        printf("Process terminated by signal %d\n", WTERMSIG(status));
    }

    return -1;
}
