#include <string.h>

#include "parser.h"

int parse_command(char *line, char *args[])
{
    int argument_count = 0;

    /*
     * strtok() divides the input using spaces, tabs and newlines.
     */
    char *token = strtok(line, " \t\r\n");

    while (token != NULL && argument_count < MAX_ARGS - 1)
    {
        args[argument_count] = token;
        argument_count++;

        token = strtok(NULL, " \t\r\n");
    }

    /*
     * execvp() requires the argument array to end with NULL.
     */
    args[argument_count] = NULL;

    return argument_count;
}
