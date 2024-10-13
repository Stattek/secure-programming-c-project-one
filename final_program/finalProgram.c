/**
 * Author: David Slay, Xavier Zamora
 * Summary: Final program for program one
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

#define BUFFER_SIZE 1024
#define MAX_CHOICE 2 // maximum number of choices

/**
 * Xavier Zamora
 * @brief Opens a file and retrieves file pointer.
 * 
 * Demonstration of rule MSC41-C, never hard code sensitive information.
 * We store the password in a separate file so no user can obtain this source code and access the password.
 * 
 * @param filename Name of file that contains the password.
 * @return FILE* Pointer to file.
 */
FILE* openPasswordFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error: Could not open password file.\n");
        exit(EXIT_FAILURE);
    }
    return file;
}

/**
 * Xavier Zamora
 * @brief Reads password from password file and read password.
 * 
 * @param password Pointer to buffer where password will be stored.
 * @param size Size of buffer to ensure password fits within buffer.
 * @param file Pointer to file.
 */
void readPasswordFromFile(char *password, size_t size, FILE *file)
{
    if (fgets(password, size, file) == NULL)
    {
        printf("Error: Failed to read password from file!\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
    password[strcspn(password, "\n")] = 0; // removing newline char
}

/**
 * Xavier Zamora
 * @brief Generates an unsigned integer from password ASCII data for authentication purposes and ensures the int does not wrap.
 * 
 * Demonstration of rule INT30-C, ensure that unsigned int operations do not wrap.
 * 
 * @param password Input password string.
 * @return unsigned int 
 */
unsigned int generateUnsignedNumberFromPassword(const char* password)
{
    unsigned int sum = 0;
    for (size_t i = 0; i < strlen(password); i++)
    {
        if (UINT_MAX - sum < (unsigned int)password[i])
        {
            printf("Unsigned integer wrapping occured.\n");
            return UINT_MAX;
        }
        sum += (unsigned int)password[i];
    }
    return sum;
}

/**
 * Xavier Zamora
 * @brief Generates a signed integer from password ASCII data for authentication purposes.
 * 
 * Demonstration of rule INT32-C, ensure that operations on signed ints do not result in overflow.
 * 
 * @param password Input password string.
 * @return signed int 
 */
int generateSignedNumberFromPassword(const char *password)
{
    int product = 1;
    for (size_t i = 0; i < strlen(password); i++)
    {
        product *= (int)password[i];

        if (product > INT_MAX || product < INT_MIN)
        {
            product %= INT_MAX;
        }
    }
    return product;
}

/**
 * Xavier Zamora
 * @brief Compares outputs from previous two functions with password input and returns true if equal, and false if not equal.
 * 
 * @param savedUnsigned Unsigned integer obtained from password.
 * @param savedSigned Signed integer obtained from password.
 * @param password Password to be authenticated.
 * @return true if equal
 * @return false if not equal
 */
bool authenticate(unsigned int savedUnsigned, int savedSigned, const char *password)
{
    unsigned int unsignedCheck = generateUnsignedNumberFromPassword(password);
    int signedCheck = generateSignedNumberFromPassword(password);

    return (unsignedCheck == savedUnsigned && signedCheck == savedSigned);
}

/**
 * @brief Does a typing test and prints the user input to a file along with results.
 *
 * @param dstFile The destination file to write to.
 * @param bufSize The buffer size for writing to file.
 *
 * @returns true on error, false otherwise.
 */
bool doTypingTest(FILE *dstFile, size_t bufSize)
{
    if (bufSize <= 0 || !dstFile)
    {
        // error
        return true;
    }

    // possible words to use for the typing test
    static const char *possibleWords[] = {
        "the",
        "an",
        "to",
        "help",
        "test",
        "know",
        "tell",
        "when",
        "program",
        "find",
        "time",
        "year",
        "back",
        "you",
        "because",
    };
    const int possibleWordsLen = sizeof(possibleWords) / sizeof(char *);

    /*
    Recommendation MEM05: Avoid large stack allocations.
    Done by putting curStr on the stack for writing to the file.
    */
    char *curStr = malloc(bufSize);
    if (!curStr)
    {
        fprintf(stderr, "Could not allocate string\n");
        return true;
    }

    int numWordsTyped = 0; // number of words correctly typed by user
    bool hasTypedIncorrectly = false;

    // start timer
    time_t startTime = time(NULL);
    do
    {
        // get random word
        const char *randWordStr = possibleWords[rand() % possibleWordsLen];
        printf("%s\n>> ", randWordStr);

        if (fgets(curStr, bufSize, stdin) == NULL)
        {
            fprintf(stderr, "Error reading user input\n");
            return true;
        }

        size_t curStrLen = strlen(curStr);

        bool printNewLine = false;
        if (curStr[curStrLen - 1] == '\n')
        {
            // set the newline character to the null-terminating character
            curStr[curStrLen - 1] = '\0';
            printNewLine = true; // we should print the new line character later
        }
        if (strncmp(curStr, randWordStr, bufSize) != 0)
        {
            // the word was typed incorrectly
            hasTypedIncorrectly = true;
        }
        else
        {
            // word typed correctly
            numWordsTyped++;
        }

        int writeErr;
        if (!hasTypedIncorrectly)
        {
            // write the string that we read
            writeErr = fputs(curStr, dstFile);
            if (writeErr == EOF)
            {
                fprintf(stderr, "Error writing to file\n");
                return true;
            }
        }
        else
        {
            // write the mistake that was made
            char mistakeOutput[BUFFER_SIZE] = "";
            snprintf(mistakeOutput, BUFFER_SIZE, "%s <--(Your mistake)", curStr);

            writeErr = fputs(mistakeOutput, dstFile);
            if (writeErr == EOF)
            {
                fprintf(stderr, "Error writing to file\n");
                return true;
            }
        }

        if (printNewLine)
        {
            // write the newline character if we removed it earlier
            writeErr = fputs("\n", dstFile);
            if (writeErr == EOF)
            {
                fprintf(stderr, "Error writing to file\n");
                return true;
            }
        }
    } while (!hasTypedIncorrectly);

    // get elapsed time
    time_t endTime = time(NULL);
    double secondsElapsed = difftime(endTime, startTime);

    // create formatted string
    char outputStr[BUFFER_SIZE] = "";
    snprintf(outputStr, BUFFER_SIZE, "You typed %d words in %lf seconds!", numWordsTyped, secondsElapsed);

    // write to file
    int writeErr = fputs(outputStr, dstFile);
    if (writeErr == EOF)
    {
        fprintf(stderr, "Error writing results to file\n");
        return true;
    }

    printf("Results written to file!\n");

    /*
    Rule MEM34: only free memory allocated dynamically.
    Done by only freeing curStr, which is on the heap.

    Recommendation MEM00: Allocate and free memory in the same module, at the same level of abstraction.
    Done by freeing curStr, which is created at the beginning of this function.
    */
    free(curStr);
    curStr = NULL;

    // if we get here, there is no error
    return false;
}

/**
 * @brief Checks that a string is valid and only contains characters in the
 * specified character string.
 *
 * @param targetStr The string to validate.
 * @param validCharacters The valid characters.
 */
bool isValidString(char *targetStr, const char *validCharacters)
{
    bool isValid = false;

    /*
    Rule STR38: Do not confuse narrow and wide character strings and functions.
    Done by using narrow character string functions on narrow strings in this function.
    */
    char *lastCharPtr = targetStr + strlen(targetStr) - 1; // find the last character of the string
    if (lastCharPtr && *lastCharPtr == '\n')
    {
        *lastCharPtr = '\0'; // make this the new end of the string if it's a newline char
    }

    // find the length of the string until we find a character that is invalid
    size_t numValidChars = strspn(targetStr, validCharacters);
    if (numValidChars == strlen(targetStr))
    {
        // if our input string is all correct characters then it is sanitized
        isValid = true;
    }

    return isValid;
}

/**
 * @brief Gets the name of the file from the user to write to.
 *
 * @param fileNameStr The name of the file to write to.
 * @param fileNameStrLen The length of fileNameStr
 */
void getFileName(char *fileNameStr, int fileNameStrLen)
{
    static const char VALID_CHARACTERS[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ/._-";

    printf("Enter the name of the file\n");

    /*
    Rule FIO38: Do not copy a FILE object.
    This is done by copying a pointer to stdin rather than taking a copy by-value.
     */
    FILE *my_stdin = stdin;
    bool isValid = false;
    do
    {
        printf(">> ");
        fgets(fileNameStr, fileNameStrLen, my_stdin);

        if (isValidString(fileNameStr, VALID_CHARACTERS))
        {
            isValid = true;
        }
    } while (!isValid);
}

/**
 * @brief Prompts the user and controls flow to the various functions
 * in the program.
 */
void promptUser(void)
{
    printf("Choose an option:\n\t1. Do typing test\n\t2. Password authentication.\n");

    // the valid characters we are reading
    static const char VALID_CHARACTERS[] = "0123456789";

    char buf[BUFFER_SIZE] = "";
    long int userInput = 0;

    bool isValidInput = false;
    do
    {
        printf(">> ");
        if (fgets(buf, BUFFER_SIZE, stdin) == NULL)
        {
            fprintf(stderr, "Error reading user input\n");
            return;
        }
        bool isNumStr = isValidString(buf, VALID_CHARACTERS);

        if (isNumStr)
        {
            /*
            Rule STR32: Do not pass a non-null-terminate character sequence to a library function that expects a string.

            This is done by passing a null-terminated string (since fgets always returns a null-terminated string at a max size of bufferSize-1)
            to the strlen() function, which expects a null-terminated string.
            */
            char *lastCharPtr = buf + strlen(buf) - 1; // find the last character of the string

            errno = 0;
            userInput = strtol(buf, &lastCharPtr, 10);
            if (errno == EINVAL || errno == ERANGE)
            {
                perror("User input value invalid or out of range\n");
            }

            if (userInput >= 1 && userInput <= MAX_CHOICE)
            {
                // this number is valid
                isValidInput = true;
            }
        }
    } while (!isValidInput);

    switch (userInput)
    {
    case 1:
    {
        /*
        Recommendation STR02: Sanitize data passed to complex subsystems.
        Done by using function getFileName that validates a user input file name before using it to open a file with fopen().
        */
        char fileName[BUFFER_SIZE] = "";
        getFileName(fileName, BUFFER_SIZE);

        FILE *dstFile = fopen(fileName, "w");
        if (!dstFile)
        {
            fprintf(stderr, "Error opening destination file\n");
            return;
        }

        doTypingTest(dstFile, BUFFER_SIZE);
        break;
    }
    case 2: // Xavier Zamora
    {
        FILE *file = openPasswordFile("password.txt");

        /*
        Rule STR31-C, ensure storage for strings has sufficient space for character data.
        It is highly unlikely for a password to exceed 100 characters.
        
        Recommendation ARR02-C, explicitly specify array bounds, even if implicitly defined by initializer.
        */
        char password[100];
        readPasswordFromFile(password, sizeof(password), file);

        // generating signed and unsigned ints
        unsigned int unsignedNum = generateUnsignedNumberFromPassword(password);
        int signedNum = generateSignedNumberFromPassword(password);

        // clearing password memory
        memset((void *)password, 0, strlen(password));

        printf("Desired Unsigned Authentication Code: %u\n", unsignedNum);
        printf("Desired Signed Authentication Code: %d\n", signedNum);

        // user password attempt
        char passwordAttempt[100];
        printf("Enter your password: \n");
        fgets(passwordAttempt, sizeof(passwordAttempt), stdin);
        passwordAttempt[strcspn(passwordAttempt, "\n")] = 0; // remove newline char
        unsigned int enteredUnsigned = generateUnsignedNumberFromPassword(passwordAttempt);
        int enteredSigned = generateSignedNumberFromPassword(passwordAttempt);

        /*
        Recommendation MSC01-C, strive for logical completeness.
        Ensuring if-else statement accounts for both True/False values.
        */
        if (authenticate(unsignedNum, signedNum, passwordAttempt))
        {
            printf("\nAuthentication succeeded!\n");
        }
        else
        {
            printf("\nAuthentication failed, your authentication values based on entered password:\n");
            printf("Generated Unsigned Integer: %u\n", enteredUnsigned);
            printf("Generated Signed Integer: %d\n", enteredSigned);
        }
        break;
    }
    default: // impossible
        fprintf(stderr, "User chose an invalid choice\n");
        break;
    }
}

int main(void)
{
    // seed random number generator
    srand(time(NULL));
    promptUser();

    return 0;
}