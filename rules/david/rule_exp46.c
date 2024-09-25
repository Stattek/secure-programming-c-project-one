/**
 * Author: David Slay
 * Summary: Rule EXP46-C example working code
 */
#include <stdio.h>
#include <stdbool.h>

typedef struct Player
{
    const char *name;
    int level;
    bool isAlive;
} Player;

int main()
{
    Player thePlayer = {.name = "Player1", .level = 25, .isAlive = true};

    // compliant code uses the && operator for logical operation
    if (thePlayer.isAlive && thePlayer.level > 10)
    {
        printf("%s is at least level 10 and meets the requirements.\n", thePlayer.name);
    }
    else
    {
        printf("%s is not at least level 10 and does not meet the requirements.\n", thePlayer.name);
    }

    return 0;
}
