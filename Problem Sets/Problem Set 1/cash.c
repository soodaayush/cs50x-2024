#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int changeOwed;

    do
    {
        changeOwed = get_int("Change owed: ");
    }
    while (changeOwed < 1);

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    int quartersOwed = 0;
    int dimesOwed = 0;
    int nickelsOwed = 0;
    int penniesOwed = 0;
    int totalCoins = 0;

    quartersOwed = changeOwed / quarter;
    changeOwed = changeOwed - quartersOwed * quarter;

    dimesOwed = changeOwed / dime;
    changeOwed = changeOwed - dimesOwed * dime;

    nickelsOwed = changeOwed / nickel;
    changeOwed = changeOwed - nickelsOwed * nickel;

    penniesOwed = changeOwed / penny;
    changeOwed = changeOwed - penniesOwed * penny;

    totalCoins = quartersOwed + dimesOwed + nickelsOwed + penniesOwed;

    printf("%i\n", totalCoins);
}
