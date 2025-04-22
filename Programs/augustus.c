#include <stdio.h>
#include <ctype.h>

void augustus_encrypt(char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if (isupper(ch))
            text[i] = ((ch - 'A' + 1) % 26) + 'A';
        else if (islower(ch))
            text[i] = ((ch - 'a' + 1) % 26) + 'a';
    }
}

void augustus_decrypt(char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if (isupper(ch))
            text[i] = ((ch - 'A' - 1 + 26) % 26) + 'A';
        else if (islower(ch))
            text[i] = ((ch - 'a' - 1 + 26) % 26) + 'a';
    }
}

int main()
{
    char text[] = "ThisIsAugustusCipher";

    printf("Original: %s\n", text);
    augustus_encrypt(text);
    printf("Encrypted: %s\n", text);
    augustus_decrypt(text);
    printf("Decrypted: %s\n", text);

    return 0;
}
