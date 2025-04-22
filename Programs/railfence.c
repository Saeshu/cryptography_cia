#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void rail_fence_encrypt(char *text, int rails, char *ciphertext)
{
    int len = strlen(text);
    char rail[rails][len];

    // Initialize rail array with ' ' (spaces)
    for (int i = 0; i < rails; i++)
    {
        for (int j = 0; j < len; j++)
        {
            rail[i][j] = ' ';
        }
    }

    int row = 0;
    int dir = 1; // 1: down, -1: up

    // Create the zig-zag pattern
    for (int i = 0; i < len; i++)
    {
        rail[row][i] = text[i];

        if (row == 0)
            dir = 1; // Change direction to down
        else if (row == rails - 1)
            dir = -1; // Change direction to up

        row += dir;
    }

    // Read off the ciphertext row by row
    int idx = 0;
    for (int i = 0; i < rails; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (rail[i][j] != ' ')
            {
                ciphertext[idx++] = rail[i][j];
            }
        }
    }
    ciphertext[idx] = '\0'; // Null-terminate the ciphertext
}

void rail_fence_decrypt(char *ciphertext, int rails, char *plaintext)
{
    int len = strlen(ciphertext);
    char rail[rails][len];

    // Initialize rail array with ' ' (spaces)
    for (int i = 0; i < rails; i++)
    {
        for (int j = 0; j < len; j++)
        {
            rail[i][j] = ' ';
        }
    }

    int row = 0;
    int dir = 1; // 1: down, -1: up
    int idx = 0;

    for (int i = 0; i < len; i++)
    {
        rail[row][i] = '*';

        if (row == 0)
            dir = 1; // Change direction to down
        else if (row == rails - 1)
            dir = -1; // Change direction to up

        row += dir;
    }

    for (int i = 0; i < rails; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (rail[i][j] == '*' && idx < len)
            {
                rail[i][j] = ciphertext[idx++];
            }
        }
    }

    idx = 0;
    row = 0;
    dir = 1;
    for (int i = 0; i < len; i++)
    {
        plaintext[i] = rail[row][i];

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }
    plaintext[len] = '\0';
}

int main()
{
    char text[] = "RailwayStation";
    char encrypted[100];
    char decrypted[100];
    int rails = 3;

    printf("Original: %s\n", text);
    rail_fence_encrypt(text, rails, encrypted);
    printf("Encrypted: %s\n", encrypted);
    rail_fence_decrypt(encrypted, rails, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
