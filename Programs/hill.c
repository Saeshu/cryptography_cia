#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 2

int mod_inverse(int a, int m)
{
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // No inverse exists
}

int determinant(int matrix[N][N])
{
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

int inverse_matrix(int matrix[N][N], int inverse[N][N])
{
    int det = determinant(matrix);
    int det_inv = mod_inverse(det, 26);

    if (det_inv == -1)
        return 0; // Inverse doesn't exist

    int temp = matrix[0][0];
    matrix[0][0] = matrix[1][1] * det_inv % 26;
    matrix[1][1] = temp * det_inv % 26;
    matrix[0][1] = -matrix[0][1] * det_inv % 26;
    matrix[1][0] = -matrix[1][0] * det_inv % 26;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] < 0)
                matrix[i][j] += 26;
            inverse[i][j] = matrix[i][j] % 26;
        }
    }

    return 1;
}

// Function to multiply two matrices
void multiply_matrices(int result[N], int matrix[N][N], int vector[N])
{
    for (int i = 0; i < N; i++)
    {
        result[i] = 0;
        for (int j = 0; j < N; j++)
        {
            result[i] += matrix[i][j] * vector[j];
        }
        result[i] = result[i] % 26;
    }
}

void hill_encrypt(char *text, int key[N][N])
{
    int len = strlen(text);
    int plaintext[N], ciphertext[N];

    for (int i = 0; i < len; i += N)
    {
        for (int j = 0; j < N; j++)
        {
            plaintext[j] = toupper(text[i + j]) - 'A';
        }
        multiply_matrices(ciphertext, key, plaintext);

        for (int j = 0; j < N; j++)
        {
            text[i + j] = ciphertext[j] + 'A';
        }
    }
}

void hill_decrypt(char *text, int key[N][N])
{
    int len = strlen(text);
    int plaintext[N], ciphertext[N];
    int inverse_key[N][N];

    if (!inverse_matrix(key, inverse_key))
    {
        printf("Inverse matrix doesn't exist.\n");
        return;
    }

    for (int i = 0; i < len; i += N)
    {
        for (int j = 0; j < N; j++)
        {
            ciphertext[j] = toupper(text[i + j]) - 'A';
        }
        multiply_matrices(plaintext, inverse_key, ciphertext);

        for (int j = 0; j < N; j++)
        {
            text[i + j] = plaintext[j] + 'A';
        }
    }
}

int main()
{
    char text[] = "HELLO";
    int key[N][N] = {{6, 15}, {8, 13}};

    printf("Original: %s\n", text);
    hill_encrypt(text, key);
    printf("Encrypted: %s\n", text);
    hill_decrypt(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}
