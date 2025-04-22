#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

void assign_key_order(char *key, int *order)
{
    int len = strlen(key);
    int idx = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        for (int i = 0; i < len; i++)
        {
            if (toupper(key[i]) == ch)
            {
                order[i] = idx;
                idx++;
            }
        }
    }
}

void myszkowski_encrypt(char *plaintext, char *key, char *ciphertext)
{
    int len = strlen(plaintext);
    int klen = strlen(key);
    int rows = (len + klen - 1) / klen;
    char matrix[rows][klen];
    int order[klen];

    int pos = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < klen; j++)
            matrix[i][j] = (pos < len) ? plaintext[pos++] : 'X';

    assign_key_order(key, order);

    int written = 0;
    for (int num = 0; num < klen; num++)
    {
        for (int i = 0; i < klen; i++)
        {
            if (order[i] == num)
            {
                for (int r = 0; r < rows; r++)
                {
                    ciphertext[written++] = matrix[r][i];
                }
            }
        }
    }
    ciphertext[written] = '\0';
}

int main()
{
    char plaintext[] = "WEAREDISCOVEREDFLEEATONCE";
    char key[] = "MYSZKHOWSKI"; // MYSZKOWSKI spelled wrong intenionally
    char ciphertext[MAX_LEN];

    myszkowski_encrypt(plaintext, key, ciphertext);

    printf("Plaintext:  %s\n", plaintext);
    printf("Keyword:    %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
