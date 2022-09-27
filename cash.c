#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents()
{
//asks the user for the numbers of cents, then if it's less than 0, the while loop
//restart asking for the number
    int cents;
    do
    {
        cents = get_int("Cents i Owe: ");
    }
    while (cents < 0);

    return cents;
}
//quarters starts at zero, when quartes equals to zero, then cents equal or greater than 25,
//cents minus 25 and gets 1 quarter
int calculate_quarters(int cents)
{
int quarters = 0;
while (cents >= 25)
{
    cents = cents - 25;
    quarters++;
}
return quarters;
}

//dimes starts at zero, when dimes equals to zero, then cents equal or greater than 10,
//cents minus 10 and gets 1 dime

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    return dimes;
}

//nickles starts at zero, when nickels equals to zero, then cents equal or greater than 5,
//cents minus 5 and gets 1 nickle

int calculate_nickels(int cents)
{
    int nickles = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickles++;
    }
    return nickles;
}

//pennies starts at zero, when pennies equals 0, then cents equal or greater than 1,
//cents minus 1 and gets 1 pennie

int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    return pennies;
}

