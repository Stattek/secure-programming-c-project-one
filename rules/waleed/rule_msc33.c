/**
 * Author: Waleed
 * Summary: The `time_info` structure is properly initialized using `localtime()` before being passed to `asctime()`.
 */
#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);

    if (time_info != NULL)
    {
        char *time_str = asctime(time_info);
        if (time_str != NULL)
        {
            printf("Current time: %s", time_str);
        }
        else
        {
            fprintf(stderr, "Error converting time to string.\n");
        }
    }
    else
    {
        fprintf(stderr, "Error obtaining local time.\n");
    }

    return 0;
}