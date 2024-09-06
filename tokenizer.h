#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token
{
    char *string;
    struct token *next;
};

struct line
{
    int tCount;
    struct token *tokens;
    struct line *next;
};

struct fLines
{
    struct line *head;
};

struct line *buildLine(char *buffer);