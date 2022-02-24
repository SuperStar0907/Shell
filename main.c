#include "header.h"
int strio(char *string)
{
    int ans = 0;
    ;
    int neg = 0;
    if (string[0] == '-')
    {
        neg = 1;
    }
    for (int i = neg; i < strlen(string); i++)
    {
        ans = ans * 10 + string[i] - '0';
    }
    return ((neg == 1) ? -1 : 1) * ans;
}
int main()
{
    char init[1000], current[1000];
    getcwd(init, 1000);
    // char *history[20];
    // for(int i = 0; i < 20; i++){
    //     history[i] = malloc(100);
    // }
    // intche = 0;
    che = 0;
    pppp=0;

    while (1)
    {
        getcwd(current, 1000);
        prompt(init, current);
        char a[100];
        scanf(" %[^\n]s", a);
        ppp = 0;
        pp = 0;
    L1:
    if(pp<=count){
        ppp=0;
    }
        if(ppp==0){
            strcpy(history[(che++) % 20], a);
        }
        // strcpy(history[che++], a);
        char arg[100][100];
        char *token = strtok(a, ";");
        int i = 0;
        while (token != NULL)
        {
            strcpy(arg[i++], token);
            token = strtok(NULL, ";");
        }
        int length = i;
        for (i = 0; i < length; i++)
        {
            char *temporary;
            strcpy(temporary, arg[i]);
            int k, j = 0, flag = 1;
            for (k = 0; k < strlen(temporary); k++)
            {
                if (temporary[k] != ' ' && temporary[k] != '\t')
                {
                    arg[i][j++] = temporary[k];
                    flag = 0;
                }
                else
                {
                    if (flag == 0)
                    {
                        arg[i][j++] = ' ';
                        flag = 1;
                    }
                }
            }
            arg[i][j] = '\0';
            char *tok = strtok(arg[i], " ");
            if (!strcmp(arg[i], "echo"))
            {
                echo(arg[i], tok);
            }
            else if (!strcmp(arg[i], "ls") )
            {
                ls(tok, a,init);
            }
            else if (!strcmp(arg[i], "cd"))
            {
                cd(arg[i], tok, init, current);
            }
            else if (!strcmp(arg[i], "pwd"))
            {
                printf("%s\n", current);
            }
            else if (!strcmp(arg[i], "pinfo"))
            {
                tok = strtok(NULL, " ");
                pinfo(tok);
            }
            else if (!strcmp(arg[i], "history"))
            {
                tok = strtok(NULL, " ");
                if (tok == NULL)
                {
                    if (che < 20)
                    {
                        for (int i = 0; i < che; i++)
                        {
                            printf("%s\n", history[i]);
                        }
                    }
                    else
                    {
                        for (int i = (che % 20); i < 20; i++)
                        {
                            printf("%s\n", history[i]);
                        }
                        for (int i = 0; i < (che % 20); i++)
                        {
                            printf("%s\n", history[i]);
                        }
                    }
                }
                else
                {
                    int cont = strio(tok);

                    if (cont < 20)
                    {
                        for (int i = (che - cont); i < che; i++)
                        {
                            printf("%s\n", history[i]);
                        }
                    }
                    else
                    {
                        if ((che % 20) + cont < 20)
                        {
                            for (int i = (che % 20); i < (che % 20) + cont; i++)
                            {
                                printf("%s\n", history[i]);
                            }
                        }
                        else
                        {
                            for (int i = (che % 20); i < 20; i++)
                            {
                                printf("%s\n", history[i]);
                            }
                            for (int i = 0; i < cont + (che % 20) - 20; i++)
                            {
                                printf("%s\n", history[i]);
                            }
                        }
                    }
                }
            }
            else if (!strcmp(arg[i], "repeat"))
            {
                tok = strtok(NULL, " ");
                count = strio(tok);
                tok = strtok(NULL, " ");
                strcpy(a, tok);
                tok = strtok(NULL, " ");
                while (tok != NULL)
                {
                    strcat(a, " ");
                    strcat(a, tok);
                    tok = strtok(NULL, " ");
                }
                
            L2:
                ppp = 1;
                pp++;
                if (pp > count)
                {
                    pppp=4;
                    goto L3;
                }
                else{
                    ppp=1;
                    pppp = 2;
                    goto L1;
                }
                
            }

            
            L3:
            if (pp < count&&pppp==2)
            {
                ppp = 1;
                goto L2;
            }
            if (pp >= count)
            {
                pp = 0;
                ppp = 0;
            }
        }
    }
}
