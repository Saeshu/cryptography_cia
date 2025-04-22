#include <stdio.h>
#include <string.h>
#include <ctype.h>

void beaufort_cipher(char *text, char *key)
{
    int text_len = strlen(text);
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; i < text_len; i++)
    {
        char ch = text[i];

        if (isalpha(ch))
        {
            int p = isupper(ch) ? ch - 'A' : ch - 'a';
            int k = tolower(key[j % key_len]) - 'a';

            int c = (k - p + 26) % 26;

            text[i] = isupper(ch) ? (c + 'A') : (c + 'a');
            j++;
        }
    }
}

int main()
{
    char text[] = "ThisIsaCipher";
    char key[] = "BREAK";

    printf("Original: %s\n", text);
    beaufort_cipher(text, key);
    printf("Encrypted: %s\n", text);
    beaufort_cipher(text, key); // Same function decrypts
    printf("Decrypted: %s\n", text);

    return 0;
}
