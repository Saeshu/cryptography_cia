#include <stdio.h>
#include <ctype.h>

void caesar_encrypt(char *text, int shift)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if (isupper(ch))
            text[i] = ((ch - 'A' + shift) % 26) + 'A';
        else if (islower(ch))
            text[i] = ((ch - 'a' + shift) % 26) + 'a';
    }
}

void caesar_decrypt(char *text, int shift)
{
    caesar_encrypt(text, 26 - (shift % 26));
}

int main()
{
    char text[] = "ThisIsMyFirstCode";
    int shift = 3;

    printf("Original: %s\n", text);
    caesar_encrypt(text, shift);
    printf("Encrypted: %s\n", text);
    caesar_decrypt(text, shift);
    printf("Decrypted: %s\n", text);

    return 0;
}