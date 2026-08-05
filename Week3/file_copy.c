#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void)
{
    int source_fd;
    int destination_fd;

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    /*
     * Open File1.txt in read-only mode.
     */
    source_fd = open("File1.txt", O_RDONLY);

    if (source_fd == -1)
    {
        perror("Unable to open File1.txt");
        return EXIT_FAILURE;
    }

    /*
     * Open File2.txt for writing.
     *
     * O_WRONLY  -> open for writing
     * O_CREAT   -> create it if it does not exist
     * O_TRUNC   -> erase old contents if it exists
     *
     * 0644 gives:
     * owner       -> read and write
     * group       -> read
     * others      -> read
     */
    destination_fd = open(
        "File2.txt",
        O_WRONLY | O_CREAT | O_TRUNC,
        0644
    );

    if (destination_fd == -1)
    {
        perror("Unable to open File2.txt");
        close(source_fd);
        return EXIT_FAILURE;
    }

    /*
     * Read data from File1.txt repeatedly.
     *
     * read() returns:
     * greater than 0 -> number of bytes read
     * 0              -> end of file
     * -1             -> error
     */
    while ((bytes_read =
                read(source_fd, buffer, sizeof(buffer))) > 0)
    {
        /*
         * Write the bytes that were read into File2.txt.
         */
        ssize_t bytes_written =
            write(destination_fd, buffer, bytes_read);

        if (bytes_written != bytes_read)
        {
            perror("Unable to write to File2.txt");

            close(source_fd);
            close(destination_fd);

            return EXIT_FAILURE;
        }
    }

    if (bytes_read == -1)
    {
        perror("Unable to read File1.txt");

        close(source_fd);
        close(destination_fd);

        return EXIT_FAILURE;
    }

    /*
     * Close both files after copying.
     */
    close(source_fd);
    close(destination_fd);

    printf("File copied successfully from File1.txt to File2.txt.\n");

    return EXIT_SUCCESS;
}
