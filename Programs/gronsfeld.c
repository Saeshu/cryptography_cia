#include <stdio.h>
#include <string.h>
#include <ctype.h>

void gronsfeld_encrypt(char *text, char *key)
{
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            int shift = key[j % key_len] - '0';

            if (isupper(text[i]))
                text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
            else
                text[i] = ((text[i] - 'a' + shift) % 26) + 'a';

            j++;
        }
    }
}

void gronsfeld_decrypt(char *text, char *key)
{
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            int shift = key[j % key_len] - '0';

            if (isupper(text[i]))
                text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
            else
                text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';

            j++;
        }
    }
}

int main()
{
    char text[] = "BreakmeifYouCan";
    char key[] = "3215"; // Numeric key only

    printf("Original: %s\n", text);
    gronsfeld_encrypt(text, key);
    printf("Encrypted: %s\n", text);
    gronsfeld_decrypt(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}
