#include <stdio.h>
#include <ctype.h>
#include <string.h>

void vigenere_encrypt(char *text, char *key)
{
    int text_len = strlen(text);
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; i < text_len; i++)
    {
        char ch = text[i];

        if (isalpha(ch))
        {
            char k = tolower(key[j % key_len]) - 'a';
            if (isupper(ch))
                text[i] = ((ch - 'A' + k) % 26) + 'A';
            else
                text[i] = ((ch - 'a' + k) % 26) + 'a';
            j++;
        }
    }
}

void vigenere_decrypt(char *text, char *key)
{
    int text_len = strlen(text);
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; i < text_len; i++)
    {
        char ch = text[i];

        if (isalpha(ch))
        {
            char k = tolower(key[j % key_len]) - 'a';
            if (isupper(ch))
                text[i] = ((ch - 'A' - k + 26) % 26) + 'A';
            else
                text[i] = ((ch - 'a' - k + 26) % 26) + 'a';
            j++;
        }
    }
}

int main()
{
    char text[] = "HiThereHello";
    char key[] = "WOW";

    printf("Original: %s\n", text);
    vigenere_encrypt(text, key);
    printf("Encrypted: %s\n", text);
    vigenere_decrypt(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}
