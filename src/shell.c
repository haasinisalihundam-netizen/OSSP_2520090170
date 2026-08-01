#include <stdio.h>

#include "shell.h"
#include "parser.h"
#include "executor.h"
#include "builtin.h"

#define INPUT_SIZE 1024

int run_shell(void)
{
    char input[INPUT_SIZE];
    char *args[MAX_ARGS];

    while (1)
    {
        printf("my_shell> ");
        fflush(stdout);

        /*
         * fgets() reads one complete line from the keyboard.
         * If Ctrl+D is pressed, fgets() returns NULL.
         */
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        /*
         * parse_command() separates the command into arguments.
         * Example:
         *
         * Input:  ls -l docs
         *
         * args[0] = "ls"
         * args[1] = "-l"
         * args[2] = "docs"
         * args[3] = NULL
         */
        int argument_count = parse_command(input, args);

        if (argument_count == 0)
        {
            continue;
        }

        /*
         * Built-in commands such as cd and exit must be handled
         * directly by our shell.
         */
        if (handle_builtin(args))
        {
            continue;
        }

        /*
         * External commands are executed using fork() and execvp().
         */
        execute_command(args);
    }

    return 0;
}
