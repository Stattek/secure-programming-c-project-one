/**
 * @file rule_msc41.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief MSC41: never hard code sensitive information
 * @version 1.0
 * @date 2024-10-13
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief reads the password from a file and stores it in buffer
 *
 * @param filename name of password file
 * @param password buffer to store password
 * @param size size of password buffer
 * @return 0 if successful, 1 if error
 */
int readPasswordFromFile(const char *filename, char *password, size_t size)
{
    FILE *file = fopen("fio46_msc41_text.txt", "r");
    if (file == NULL)
    {
        printf("could not open file");
        return 1;
    }

    if (fgets(password, size, file) == NULL)
    {
        printf("could not read password from file");
        fclose(file);
        return 1;
    }

    fclose(file);
    // removing newline character
    password[strcspn(password, "\n")] = 0;
    return 0;
}

/**
 * @brief prompts user to input a password attempt
 *
 * @param passwordAttempt buffer to store user input
 * @param size size of password attempt buffer
 */
void getPasswordAttempt(char *passwordAttempt, size_t size)
{
    printf("password attempt:\n");
    fgets(passwordAttempt, size, stdin);
    // removing newline character
    passwordAttempt[strcspn(passwordAttempt, "\n")] = 0;
}

/**
 * @brief compares password attempt with actual password
 *
 * @param password correct password
 * @param passwordAttempt password attempt
 * @return 0 if match, 1 if not mach
 */
int comparePasswords(const char *password, const char *passwordAttempt)
{
    int result = strcmp(passwordAttempt, password);

    // ensuring that password is not stored
    memset((void *)passwordAttempt, 0, strlen(passwordAttempt));

    return result;
}

int main(void)
{
    char password[100];

    if (readPasswordFromFile("password.txt", password, sizeof(password)) != 0)
    {
        return 1;
    }

    char passwordAttempt[strlen(password) + 1];
    getPasswordAttempt(passwordAttempt, sizeof(passwordAttempt));

    if (comparePasswords(password, passwordAttempt) == 0)
    {
        printf("correct password yippee\n");
        return 0;
    }
    else
    {
        printf("wrong password go away\n");
        return 1;
    }
}