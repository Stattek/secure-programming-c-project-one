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
 * @param filename 
 * @param mode 
 * @return FILE* 
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

int main()
{
    FILE *file = openFile("fio46_text.txt", "r");

    if (file == NULL)
    {
        return 1;
    }

    char buffer[16];

    if (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("read: %s\n", buffer);
    }
    else
    {
        perror("error reading from file");
    }

    fclose(file);
    
    return 0;
}