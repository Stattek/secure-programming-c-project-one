/**
 * @file rule_fio46.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief FIO46: Do not access a closed file
 * @version 1.0
 * @date 2024-10-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

/**
 * @brief 
 * 
 * @param filename name of file to open
 * @param mode read, write, etc
 * @return FILE* return ptr to file
 */
FILE* openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        perror("failed to open file");
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

    if (ferror(file))
    {
        perror("Error reading from file");
    }
}

int main()
{
    FILE *file = openFile("fio46__msc41_text.txt", "r");

    if (file == NULL)
    {
        return 1;
    }

    readFile(file);

    if (fclose(file) != 0)
    {
        perror("failed to close file");
        return 1;
    }
    
    return 0;
}