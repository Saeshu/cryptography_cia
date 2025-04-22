#include <stdio.h>
#include <string.h>
#include <ctype.h>

void autoclave_encrypt(char *text, char *key)
{
    int text_len = strlen(text);
    char full_key[1000] = {0};
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; i < key_len; i++)
        full_key[i] = tolower(key[i]);
    for (int i = key_len; i < text_len; i++)
        full_key[i] = tolower(text[i - key_len]);

    for (int i = 0; i < text_len; i++)
    {
        if (isalpha(text[i]))
        {
            int p = tolower(text[i]) - 'a';
            int k = full_key[i] - 'a';
            int c = (p + k) % 26;

            text[i] = isupper(text[i]) ? (c + 'A') : (c + 'a');
        }
    }
}

void autoclave_decrypt(char *text, char *key)
{
    int text_len = strlen(text);
    char full_key[1000] = {0};
    int key_len = strlen(key);

    // Fill initial key
    for (int i = 0; i < key_len; i++)
        full_key[i] = tolower(key[i]);

    for (int i = 0; i < text_len; i++)
    {
        if (isalpha(text[i]))
        {
            int k = full_key[i] - 'a';
            int c = tolower(text[i]) - 'a';
            int p = (c - k + 26) % 26;

            char decrypted_char = isupper(text[i]) ? (p + 'A') : (p + 'a');
            full_key[i + key_len] = tolower(decrypted_char);

            text[i] = decrypted_char;
        }
    }
}

int main()
{
    char text[] = "ThisIsRunningKeyCipher";
    char key[] = "KEY";

    printf("Original: %s\n", text);
    autoclave_encrypt(text, key);
    printf("Encrypted: %s\n", text);
    autoclave_decrypt(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}
