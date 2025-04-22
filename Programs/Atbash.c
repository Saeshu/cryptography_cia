#include <stdio.h>
#include <ctype.h>

void atbash_cipher(char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if (isupper(ch))
            text[i] = 'Z' - (ch - 'A');
        else if (islower(ch))
            text[i] = 'z' - (ch - 'a');
    }
}

int main()
{
    char text[] = "BackandForth";

    printf("Original: %s\n", text);
    atbash_cipher(text);
    printf("Encrypted/Decrypted: %s\n", text);
    atbash_cipher(text);
    printf("Back to Original: %s\n", text);

    return 0;
}