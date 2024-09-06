#include "tokenizer.h"

int main()
{
    struct fLines *Lines = malloc(sizeof(struct fLines));
    FILE *fp = fopen(".\\testfiles\\hello.py", "r");
    char *buffer = malloc(128);
    char c = getc(fp);
    buffer[0] = c;
    struct line *cur;
    int i = 1;

    while ((c != EOF))
    {

        c = getc(fp);
        i++;
        if (c == '\n')
        {
            cur = malloc(sizeof(struct line));
            cur = buildLine(buffer);
            i = 0;
        }
    }
    printf("%s\n", Lines->head->tokens->string);
}

/**
 * @brief Tokenizes a given line and returns a line struct.
 *
 * @param buffer The line we are using.
 * @return Our tokenized line.
 */
struct line *buildLine(char *buffer)
{
    char *str = malloc(128);
    struct line *x = malloc(sizeof(struct line));
    x->tCount = 0;
    x->next = NULL;
    x->tokens = NULL;
    struct token *cur;
    int j = 0;
    for (int i = 0; buffer[i] == '\n'; i++)
    {

        if (buffer[i] == ' ')
        {
            str[j] = '\0';
            cur->string = malloc(sizeof(buffer));
            cur->string = str;
            cur = cur->next;
            cur = malloc(sizeof(struct token));
            cur->next = NULL;

            str = malloc(128);
            j = 0;
            x->tCount++;
        }
        else
        {
            str[j] = buffer[i];
            j++;
        }
    }

    return x;
}