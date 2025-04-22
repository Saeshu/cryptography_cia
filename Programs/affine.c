#include <stdio.h>
#include <ctype.h>

int mod_inverse(int a)
{
    for (int i = 1; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

void affine_encrypt(char *text, int a, int b)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];
        if (isupper(ch))
        {
            text[i] = ((a * (ch - 'A') + b) % 26) + 'A';
        }
        else if (islower(ch))
        {
            text[i] = ((a * (ch - 'a') + b) % 26) + 'a';
        }
    }
}

void affine_decrypt(char *text, int a, int b)
{
    int a_inv = mod_inverse(a);
    if (a_inv == -1)
    {
        printf("Invalid 'a': no modular inverse exists.\n");
        return;
    }

    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];
        if (isupper(ch))
        {
            text[i] = ((a_inv * ((ch - 'A') - b + 26)) % 26) + 'A';
        }
        else if (islower(ch))
        {
            text[i] = ((a_inv * ((ch - 'a') - b + 26)) % 26) + 'a';
        }
    }
}

int main()
{
    char text[] = "AffineCipher";
    int a = 5, b = 8; // a must be coprime with 26

    printf("Original: %s\n", text);
    affine_encrypt(text, a, b);
    printf("Encrypted: %s\n", text);
    affine_decrypt(text, a, b);
    printf("Decrypted: %s\n", text);

    return 0;
}
