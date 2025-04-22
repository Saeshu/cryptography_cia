#include <stdio.h>
#include <string.h>
#include <ctype.h>

void route_cipher_encrypt(char *plaintext, int rows, int cols, char *ciphertext)
{
    int len = strlen(plaintext);
    char matrix[rows][cols];
    int k = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (k < len && plaintext[k] != '\0')
            {
                matrix[i][j] = plaintext[k++];
            }
            else
            {
                matrix[i][j] = 'X'; // Padding character
            }
        }
    }

    k = 0;
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            ciphertext[k++] = matrix[i][j];
        }
    }
    ciphertext[k] = '\0';
}

void route_cipher_decrypt(char *ciphertext, int rows, int cols, char *plaintext)
{
    int len = strlen(ciphertext);
    char matrix[rows][cols];
    int k = 0;

    // Fill matrix column by column
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (k < len && ciphertext[k] != '\0')
            {
                matrix[i][j] = ciphertext[k++];
            }
        }
    }

    k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            plaintext[k++] = matrix[i][j];
        }
    }
    plaintext[k] = '\0';
}

int main()
{
    char message[] = "WHICHROUTE";
    char encrypted[100], decrypted[100];
    int rows = 3, cols = 4;

    printf("Original: %s\n", message);
    route_cipher_encrypt(message, rows, cols, encrypted);
    printf("Encrypted: %s\n", encrypted);
    route_cipher_decrypt(encrypted, rows, cols, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
