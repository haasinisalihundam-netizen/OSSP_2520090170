#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    char command[100];

    /*
     * Read one Linux command from the user.
     *
     * Examples:
     * ls
     * pwd
     * date
     * whoami
     */
    printf("Enter a Linux command: ");

    if (scanf("%99s", command) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    /*
     * fork() creates a new process.
     */
    pid_t pid = fork();

    if (pid < 0)
    {
        /*
         * A negative value means the child
         * process could not be created.
         */
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        /*
         * This block runs inside the child process.
         */
        printf("\nChild Process\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
        printf("Executing command: %s\n\n", command);

        /*
         * Print the messages before exec replaces
         * the child program.
         */
        fflush(stdout);

        /*
         * Replace the child process with the
         * Linux command entered by the user.
         */
        execlp(command, command, (char *)NULL);

        /*
         * execlp() returns only if execution fails.
         */
        perror("Execution failed");
        _exit(EXIT_FAILURE);
    }
    else
    {
        /*
         * This block runs inside the parent process.
         */
        printf("\nParent Process\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        /*
         * Wait until the child process finishes.
         */
        wait(NULL);

        printf("\nChild process completed.\n");
    }

    return 0;
}
