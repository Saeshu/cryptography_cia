#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NGRAM 4
#define MAX_TEXT 1000

typedef struct
{
    char ngram[MAX_NGRAM + 1];
    int count;
} NGramEntry;

int find_ngram(NGramEntry *ngrams, int size, char *key)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(ngrams[i].ngram, key) == 0)
            return i;
    }
    return -1;
}

void count_ngrams(char *text, int n)
{
    NGramEntry ngrams[1000];
    int total = 0;

    int len = strlen(text);
    for (int i = 0; i <= len - n; i++)
    {
        char gram[MAX_NGRAM + 1] = {0};

        int valid = 1;
        for (int j = 0; j < n; j++)
        {
            if (!isalpha(text[i + j]))
            {
                valid = 0;
                break;
            }
            gram[j] = toupper(text[i + j]);
        }

        if (!valid)
            continue;

        int index = find_ngram(ngrams, total, gram);
        if (index >= 0)
        {
            ngrams[index].count++;
        }
        else
        {
            strcpy(ngrams[total].ngram, gram);
            ngrams[total].count = 1;
            total++;
        }
    }

    printf("Top %d-grams:\n", n);
    for (int i = 0; i < total; i++)
    {
        printf("%s: %d\n", ngrams[i].ngram, ngrams[i].count);
    }
}

int main()
{
    char text[MAX_TEXT] = "Hello There General";
    int n = 3;

    count_ngrams(text, n);
    return 0;
}
