#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // immediately screen out any CLA not len(2)
    if (argc != 2)
    {
        printf("Usage: ./caesar key! Try Again.\n");
        return 1;
    }

    string s = argv[1];

    // call only digits
    bool only_digits(string s);

    if (only_digits(s) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (argc == 2)
    {
        // use modulo to get a 0 - 25 number
        int key = atoi(s) % 26;

        string plaintext = get_string("plaintext: ");

        // ciphertext output line before iterating through plaintext
        printf("ciphertext: ");
        for (int i = 0; plaintext[i] != '\0'; i++)
        {
            char ciphertext = rotate(plaintext[i], key);
            printf("%c", ciphertext);

        }
        printf("\n");
        return 0;
    }

}

bool only_digits(string s)
{
    for (int i = 0; i != strlen(s); i++)
    {
        char c = s[i];
        if (isdigit(c) == false)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    // no manipulation of non-alphabet characters
    if (isalpha(c))
    {
        // ASCII manipulation for lower case
        if (islower(c))
        {
            int ascii = c - 97;

            int cipherkey = ascii + key;
            if (cipherkey > 25)
            {
                cipherkey = cipherkey % 26;
            }
            cipherkey = cipherkey + 97;
            return cipherkey;
        }

        // ascii manipulation for upper case
        if (isupper(c))
        {
            int ascii = c - 65;

            int cipherkey = ascii + key;
            if (cipherkey > 25)
            {
                cipherkey = cipherkey % 26;
            }
            cipherkey = cipherkey + 65;
            return cipherkey;
        }
    }
    return c;
}