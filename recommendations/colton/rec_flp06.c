/**
 * Author: Colton Longstreth
 * Summary: Rule FLP06-C example working code
 */

#include <stdio.h>

int main(void)
{

    int account_amount;
    // takes number of dollars in bank account
    printf("Enter dollar amount in account: ");
    scanf("%d", &account_amount);
    // takes tax rate to be paid
    int tax_rate;
    printf("Enter tax rate %%: ");
    scanf("%d", &tax_rate);

    double tax_total = (double)account_amount * tax_rate / 100;
    // prints total amount of taxes paid
    printf("Total paid in taxes: %.2f\n", tax_total);

    return 0;
}
