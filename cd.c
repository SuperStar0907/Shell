#include "header.h"

void cd(char *a, char *tok, char *initial, char *current)
{
    tok = strtok(NULL, " ");
    if (tok == NULL)
    {
        strcpy(current, initial);
        chdir(initial);
        return;
    }
    if (strlen(tok) == 1)
    {
        if (tok[0] == '~')
        {
            chdir(initial);
            getcwd(current, 1000);
        }
        if (tok[0] == '-')
        {
            tok[0] = '.';
            tok[1] = '.';
            tok[2] = '\0';
            chdir(tok);
            getcwd(current, 1000);
            printf("~%s\n", current+strlen(initial));
        }
        return;

    }
    if (tok[0] == '~')
    {
        char a[1000], b[1000];
        for (int i = 1; i < strlen(tok); i++)
        {
            a[i - 1] = tok[i];
        }
        strcpy(b, initial);
        strcat(b, a);
        if (chdir(b) < 0)
            printf("No such directory\n");
        getcwd(current, 1000);
        return;
    }
    if (chdir(tok) < 0)
        printf("No such directory\n");
    getcwd(current, 1000);
}