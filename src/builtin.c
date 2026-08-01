#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builtin.h"

int handle_builtin(char *args[])
{
    /*
     * exit closes our shell.
     */
    if (strcmp(args[0], "exit") == 0)
    {
        printf("Exiting my_shell.\n");
        exit(EXIT_SUCCESS);
    }

    /*
     * cd changes the current directory.
     */
    if (strcmp(args[0], "cd") == 0)
    {
        const char *directory = args[1];

        /*
         * If the user enters only cd,
         * go to the home directory.
         */
        if (directory == NULL)
        {
            directory = getenv("HOME");
        }

        if (directory == NULL || chdir(directory) != 0)
        {
            perror("cd");
        }

        return 1;
    }

    /*
     * pwd prints the current directory.
     */
    if (strcmp(args[0], "pwd") == 0)
    {
        char current_directory[4096];

        if (getcwd(current_directory, sizeof(current_directory)) == NULL)
        {
            perror("pwd");
        }
        else
        {
            printf("%s\n", current_directory);
        }

        return 1;
    }

    /*
     * help displays available built-in commands.
     */
    if (strcmp(args[0], "help") == 0)
    {
        printf("Available built-in commands:\n");
        printf("  cd <directory>  Change directory\n");
        printf("  pwd             Print current directory\n");
        printf("  help            Display this message\n");
        printf("  exit            Exit the shell\n");

        return 1;
    }

    /*
     * Returning 0 means the command is not built-in.
     */
    return 0;
}
