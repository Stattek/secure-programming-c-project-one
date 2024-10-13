/**
 * @file rule_fio46.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief FIO46: Do not access a closed file
 * @version 1.0
 * @date 2024-10-12
 *
 */
#include <stdio.h>

/**
 * @brief Opens a file and returns it if opened properly.
 *
 * @param filename name of file to open
 * @param mode read, write, etc
 * @return Pointer to a file or NULL if there was an error opening it.
 */
FILE *openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        perror("failed to open file\n");
        return NULL;
    }

    return file;
}

/**
 * @brief read from a file and print its contents.
 *
 * @param file pointer to the file to read
 */
void readFile(FILE *file)
{
    char buffer[16];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }
    // print extra newline
    printf("\n");

    if (ferror(file))
    {
        perror("Error reading from file\n");
    }
}

int main(void)
{
    FILE *file = openFile("fio46_msc41_text.txt", "r");

    if (file == NULL)
    {
        return 1;
    }

    readFile(file);

    if (fclose(file) != 0)
    {
        perror("failed to close file\n");
        return 1;
    }

    return 0;
}