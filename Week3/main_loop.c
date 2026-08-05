#include <stdio.h>
#include <string.h>
#define INPUT_SIZE 1024
int main(void) {
 char input[INPUT_SIZE];

    /*
     * The while loop keeps the shell running.
     * It stops only when the user enters "exit"
     * or presses Ctrl+D.
     */
    while (1)
    {
        /*
         * Display the shell prompt.
         */
        printf("my_shell> ");
        fflush(stdout);

        /*
         * Read one complete line from the user.
         *
         * fgets() returns NULL when the user
         * presses Ctrl+D.
         */
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\nExiting shell.\n");
            break;
        }

        /*
         * Remove the newline character inserted
         * when the user presses Enter.
         */
        input[strcspn(input, "\n")] = '\0';

        /*
         * Ignore an empty command.
         */
        if (strlen(input) == 0)
        {
            continue;
        }

        /*
         * Stop the loop when the user enters exit.
         */
        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting shell.\n");
            break;
        }

        /*
         * For now, display the command entered.
         * Command execution can be added later.
         */
        printf("You entered: %s\n", input);
    }

    return 0;
}
