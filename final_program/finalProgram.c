/**
 * Author: David Slay, Aayaan, Xavier Zamora, Colton Longstreth
 * Summary: Final program for program one
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#include <pthread.h>
#include <limits.h>
#include <stdint.h>

#define BUFFER_SIZE 1024
#define MAX_CHOICE 4 // maximum number of choices

/*
PRE02-C: Macro replacement lists should be parenthesized
by using parenthesis we ensure proper order of operations
PRE11-C: Do not conclude macro definitions with a semicolon
*/
#define MOD_ep(a, b) ((a) % (b))

// struct to pass arguments to threads for percentEven function
typedef struct
{
    char *filename;
    size_t startLine;
    size_t endLine;
    unsigned char *finalArrayMods;
    size_t *finalArrayModsIndex;
    pthread_mutex_t *mutex;
    size_t maxNumbers;
    size_t bufferSize;
} ThreadDataEp;

bool doTypingTest(FILE *dstFile, size_t bufSize);
bool isValidString(char *targetStr, const char *validCharacters);
void getFileName(char *fileNameStr, int fileNameStrLen);
void evenPercent(const char *filename);
void *processFileEp(void *arg);
// Recommendation DCL20-c: explicitly putting void in function when it takes no parameters
void promptUser(void);
FILE *openPasswordFile(const char *filename);
void readPasswordFromFile(char *password, size_t size, FILE *file);
unsigned int generateUnsignedNumberFromPassword(const char *password);
int generateSignedNumberFromPassword(const char *password);
bool authenticate(unsigned int savedUnsigned, int savedSigned, const char *password);
double subtractionCalculator(double currentValue);
double additionCalculator(double currentValue);
double multiplicationCalculator(double currentValue);
double divisionCalculator(double currentValue);

/**
 * @author Xavier Zamora
 * @brief Opens a file and retrieves file pointer.
 *
 * Demonstration of rule MSC41-C, never hard code sensitive information.
 * We store the password in a separate file so no user can obtain this source code and access the password.
 *
 * @param filename Name of file that contains the password.
 * @return FILE* Pointer to file.
 */
FILE *openPasswordFile(const char *filename)
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
 * @author Xavier Zamora
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
 * @author Xavier Zamora
 * @brief Generates an unsigned integer from password ASCII data for authentication purposes and ensures the int does not wrap.
 *
 * Demonstration of rule INT30-C, ensure that unsigned int operations do not wrap.
 *
 * @param password Input password string.
 * @return unsigned int
 */
unsigned int generateUnsignedNumberFromPassword(const char *password)
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
 * @author Xavier Zamora
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
 * @author Xavier Zamora
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
 * @author David Slay
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
 * @author Colton Longstreth
 * @brief a function that takes an initial value and subtracts from it based on input given
 * @param double of current value
 * @return double
 */
double subtractionCalculator(double currentValue)
{
    int numArguments;
    printf("How many times do you want to subtract from inital value?\n>> ");
    scanf("%d", &numArguments);

    double subtractVal;
    for (int i = 0; i < numArguments; i++)
    {
        printf("Enter number to subtract:\n>> ");
        scanf("%lf", &subtractVal);
        currentValue -= subtractVal;
    }
    return currentValue;
}

/**
 * @author Colton Longstreth
 * @brief a function that starts at an inital value and adds to it based on input given
 * @param double of current value
 * @return double
 */
double additionCalculator(double currentValue)
{
    int numArguments;
    printf("How many times do you want to add to the inital value?\n>> ");
    scanf("%d", &numArguments);

    double addVal;
    for (int i = 0; i < numArguments; i++)
    {
        printf("Enter number to add:\n>> ");
        scanf("%lf", &addVal);
        currentValue += addVal;
    }
    return currentValue;
}

/**
 * @author Colton Longstreth
 * @brief a function that takes an inital value and multiplies based on input given
 * @param double of current value
 * @return double
 */
double multiplicationCalculator(double currentValue)
{
    int numArguments;
    printf("How many times do you want to multiply?\n>> ");
    scanf("%d", &numArguments);

    double multiplyVal;
    for (int i = 0; i < numArguments; i++)
    {
        printf("Enter number to multiply by:\n>> ");
        scanf("%lf", &multiplyVal);
        currentValue *= multiplyVal;
    }
    return currentValue;
}

/**
 * @author Colton Longstreth
 * @brief a function that takes an inital value and divides based on input given
 * @param double of current value
 * @return double
 */
double divisionCalculator(double currentValue)
{
    // take user input for number of arguments wanted
    int numArguments;
    printf("How many times do you want to divide?\n>> ");
    scanf("%d", &numArguments);

    double divideVal;
    // Rule FLP30 do not use floats for loop counters
    for (int i = 0; i < numArguments; i++)
    {
        printf("Enter number to divide by:\n>> ");
        scanf(" %lf", &divideVal);
        // Rule INT33 Make sure division and remainder operations do not result in dividing by 0
        if (divideVal == 0)
        {
            printf("Error can not divide by zero\n");
        }
        else
        {
            currentValue = currentValue / divideVal;
        }
    }
    return currentValue;
}

/**
 * @author David Slay
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
 * @author David Slay
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
    FILE *myStdin = stdin;
    bool isValid = false;
    do
    {
        printf(">> ");
        fgets(fileNameStr, fileNameStrLen, myStdin);

        if (isValidString(fileNameStr, VALID_CHARACTERS))
        {
            isValid = true;
        }
    } while (!isValid);
}

/**
 * @author Aayaan Shaikh
 * @brief function to print the percent of even digits in the file
 * @param filename file to be processed
 */
void evenPercent(const char *filename)
{
    /*
    DCL01-C. Do not reuse variable names in subscopes
    no variable names are reused in subscope
    there are no loops in loops but if there were we would use j instead of i for the second iterator
    */

    /*
    DCL23-C: Guarantee that mutually visible identifiers are unique
    all mutually visible identifiers are unique
    no long variable names in program but if there were we would place the unique part on the front
    */

    const size_t MAX_NUMBERS_ep = 100;
    const size_t BUFFER_SIZE_ep = 256;

    pthread_t threads[4];
    ThreadDataEp theThreadDataEp[4];
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    /*
    RULE: MEM35-C: Allocate sufficient memory for an object
    REC: INT07-C: Use only explicitly signed or unsigned char type for numeric values
    here we allocate needed space using the max limit : INT07-C, we also store the numbers as unsigned ints: MEM35-C
    */
    unsigned char finalArrayMods[MAX_NUMBERS_ep];
    size_t finalArrayModsIndex = 0;

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        return;
    }

    size_t totalLines = 0;
    char buffer[BUFFER_SIZE_ep];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        totalLines++;
    }

    fclose(file);

    // divy up line between the threads
    size_t linesPerThread = totalLines / 4;

    for (int i = 0; i < 4; i++)
    {
        theThreadDataEp[i].filename = (char *)filename;
        theThreadDataEp[i].startLine = i * linesPerThread;
        theThreadDataEp[i].endLine = (i == 3) ? totalLines : (i + 1) * linesPerThread;
        theThreadDataEp[i].finalArrayMods = finalArrayMods;
        theThreadDataEp[i].finalArrayModsIndex = &finalArrayModsIndex;
        theThreadDataEp[i].mutex = &mutex;
        theThreadDataEp[i].maxNumbers = MAX_NUMBERS_ep;
        theThreadDataEp[i].bufferSize = BUFFER_SIZE_ep;
        pthread_create(&threads[i], NULL, processFileEp, &theThreadDataEp[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        // CON39-C: Do not join or detach a thread that was previously joined or detached
        // once the threads are joined once they are never detached or joined again
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    // calculate percentage even numbers and print
    int evenCount = 0;
    float percentEven = 0.0;

    unsigned char *ptr = finalArrayMods; // pointer to star of array

    // ARR39-C: Do not add or subtract a scaled integer to a pointer
    // here we comply with the rule by not scaling the int i when adding it to ptr as it is aalready scaled correctly
    for (size_t i = 0; i < finalArrayModsIndex; i++)
    {
        if (*(ptr + i) == 0)
        {
            evenCount++;
        }
    }
    percentEven = ((float)evenCount / finalArrayModsIndex) * 100;
    // FIO47-C: Use valid format strings
    // use $.2f to round to the hundreths and use a float
    printf("The percentage of even digits in the file is %.2f%%\n", percentEven);
}

/**
 * @author Aayaan Shaikh
 * @brief function that reads the digits from the file and adds them to finalArrayMods in evenPercent
 * @param *arg stream of text from file
 * @return void*
 */
void *processFileEp(void *arg)
{
    ThreadDataEp *data = (ThreadDataEp *)arg;

    FILE *file = fopen(data->filename, "r");
    if (!file)
    {
        perror("Error: Cannot open file");
        return NULL;
    }

    char buffer[data->bufferSize];
    size_t currentLine = 0;

    // RULE: MEM35-C: Allocate sufficient memory for an object
    // correctly size max number of chars to sizeof(buffer)
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (currentLine >= data->startLine && currentLine < data->endLine)
        {
            // check each char in the buffer for digit
            for (size_t i = 0; buffer[i] != '\0'; i++)
            {
                if (isdigit(buffer[i]))
                {

                    // digit converted into unsigned char then mod by 2 as the even check and then add to array

                    // CON32-C: Prevent data races when accessing bit-fields from multiple threads
                    // INT07-C: Use only explicitly signed or unsigned char type for numeric values
                    // use mutex to lock section in case they are adjacent and a part of the same element
                    // cast to unsigned char to be recommendation compliant
                    pthread_mutex_lock(data->mutex);
                    // EXP45-C: Do not perform assignments in selection statements
                    /*
                    here instead of placing the assignment in the if statement to check if it is valid we check..
                    max size to stay in bounds and assign seperately
                    */
                    if (*(data->finalArrayModsIndex) < data->maxNumbers)
                    {
                        // PRE02-C: Macro replacement lists should be parenthesized
                        // by using parenthesis we ensure proper order of operations
                        data->finalArrayMods[*(data->finalArrayModsIndex)] = MOD_ep((unsigned char)(buffer[i] - '0'), 2);

                        (*(data->finalArrayModsIndex))++;
                    }
                    pthread_mutex_unlock(data->mutex);
                }
            }
        }
        currentLine++;
    }

    fclose(file);
    return NULL;
}

/**
 * @author David Slay
 * @brief Prompts the user and controls flow to the various functions
 * in the program.
 */
void promptUser(void)
{
    printf("Choose an option:\n\t1. Do typing test\n\t2. Read and calculate percentage of even digits from file\n\t3. Password authentication.\n\t4. Calculator.\n");

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
    case 1: // David Slay
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
    case 2: // Aayan
    {
        char fileNameEp[BUFFER_SIZE] = "";
        getFileName(fileNameEp, BUFFER_SIZE);

        evenPercent(fileNameEp); // call to evenPercent to process the file
        break;
    }
    case 3: // Xavier Zamora
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
    case 4: // Colton
    {
        // Recommendation STR00-C: Represent characters using an appropriate type
        char operation[10];
        char continue_answer;

        double current_number = 0.0;
        printf("Enter number to start:\n>> ");
        scanf("%lf", &current_number);
        do
        {
            printf("Enter operation (-,+,*,/):\n>> ");
            scanf("%s", operation);
            if (strcmp(operation, "-") == 0)
            {
                current_number = subtractionCalculator(current_number);
            }
            else if (strcmp(operation, "+") == 0)
            {
                current_number = additionCalculator(current_number);
            }
            else if (strcmp(operation, "*") == 0)
            {
                current_number = multiplicationCalculator(current_number);
            }
            else if (strcmp(operation, "/") == 0)
            {
                current_number = divisionCalculator(current_number);
            }
            else
            {
                printf("Incorrect input try again.\n");
            }
            printf("Current number: %.2f\n", current_number);
            printf("Do you want to continue (Y/N)?:\n>> ");
            scanf(" %c", &continue_answer);
        } while (continue_answer != 'N' && continue_answer != 'n');
        printf("Final value is: %.2f\n", current_number);
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
