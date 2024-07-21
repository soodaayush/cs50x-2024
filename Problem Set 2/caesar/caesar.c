#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string digits);
char rotate(char c, int n);

int main(int argc, char *argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    bool validDigits = only_digits(argv[1]);

    if (!validDigits)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plainText = get_string("Plaintext: ");
    int length = strlen(plainText);
    char cipherText[length + 1];

    for (int i = 0; i < length; i++)
    {
        cipherText[i] = rotate(plainText[i], key);
    }

    cipherText[length] = '\0';
    printf("Ciphertext: %s\n", cipherText);
    return 0;
}

bool only_digits(string digits)
{
    int length = strlen(digits);

    bool validDigits = true;

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(digits[i]))
            validDigits = false;
    }

    return validDigits;
}

char rotate(char c, int n)
{
    char pi;
    char nc;
    char ci;

    if (isupper(c))
    {
        pi = c - 65;
        ci = (pi + n) % 26;
        nc = ci + 65;
    }
    else if (islower(c))
    {
        pi = c - 97;
        ci = (pi + n) % 26;
        nc = ci + 97;
    }
    else
    {
        return c;
    }

    return nc;
}
