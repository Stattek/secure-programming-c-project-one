/**
 * Author: Waleed
 * Summary: In this example, the code explicitly compares integers to `0`,
 * booleans to `true` or `false`, and pointers to `NULL`.
 * This practice avoids ambiguity and potential bugs arising from implicit type conversions or
 * misunderstandings about how certain values evaluate in conditional contexts.
 */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int status_code = get_status();         // Assume this function returns an int status
    bool condition_met = check_condition(); // Assume this function returns a bool

    // Explicitly test integer for equality
    if (status_code == 0)
    {
        printf("Operation succeeded.\n");
    }
    else
    {
        printf("Operation failed with status code: %d\n", status_code);
    }

    // Explicitly test boolean value
    if (condition_met == true)
    {
        printf("Condition is met.\n");
    }
    else
    {
        printf("Condition is not met.\n");
    }

    // For pointers, explicitly compare to NULL
    char *data = get_data(); // Assume this function returns a pointer
    if (data != NULL)
    {
        printf("Data received: %s\n", data);
    }
    else
    {
        printf("No data received.\n");
    }

    return 0;
}

/**
 * @brief Get the status object
 *
 * @return int
 */
int get_status(void)
{
    return 0; // Simulate success
}

/**
 * @brief Check if a condition is met
 *
 * @return true
 * @return false
 */
bool check_condition(void)
{
    return false; // Simulate condition not met
}

/**
 * @brief Get the data object
 *
 * @return char*
 */
char *get_data(void)
{
    return NULL; // Simulate no data
}