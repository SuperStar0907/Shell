#include "header.h"

void echo(char *a,char* tok)
{
    tok=strtok(NULL," ");
    while (tok != NULL)
    {
        printf("%s ", tok);
        tok = strtok(NULL, " ");
    }
    printf("\n");
}