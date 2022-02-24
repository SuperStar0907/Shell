#include "header.h"
void ls(char *tok, char *a, char *initial)
{
    int ll = 0, aa = 0;
    int flag = 1;
    if (strcmp(a, tok) != 0)
        tok = strtok(NULL, " ");
    else
        flag = 0;
    int j = 0;
    char dir[1000][1000];
    while (tok != NULL && flag == 1)
    {
        if (strlen(tok) > 1)
        {
            if (strcmp(tok, "-l") == 0)
            {
                ll = 1;
            }
            else if (strcmp(tok, "-a") == 0)
            {
                aa = 1;
            }
            else if (strcmp(tok, "-la") == 0)
            {
                ll = 1;
                aa = 1;
            }
            else if (strcmp(tok, "-al") == 0)
            {
                ll = 1;
                aa = 1;
            }
            else if (strlen(tok))
                strcpy(dir[j++], tok);
        }
        else if (strlen(tok))
            strcpy(dir[j++], tok);
        tok = strtok(NULL, " ");
    }
    int length = j;

    if (aa != 0||(aa+ll)==0)
    {
        if (length == 0)
        {

            struct dirent *dir_no;
            DIR *dir_t = opendir(".");
            while ((dir_no = readdir(dir_t)) != NULL)
            {
                if (dir_no->d_name[0] != '.')
                    printf("%s \n", dir_no->d_name);
                else if (aa == 1)
                {
                    printf("%s \n", dir_no->d_name);
                }
            }
            closedir(dir_t);
        }
        else if (length == 1)
        {
            if (!strcmp(dir[0], "~"))
            {
                printf("%s \n", initial);
                strcpy(dir[0], initial);
                struct dirent *dir_no;
                DIR *dir_t = opendir(dir[0]);
                while ((dir_no = readdir(dir_t)) != NULL)
                {
                    if (dir_no->d_name[0] != '.')
                        printf("%s \n", dir_no->d_name);
                    else if (aa == 1)
                    {
                        printf("%s \n", dir_no->d_name);
                    }
                }
            }
            struct dirent *dir_no;
            if (open(dir[0], O_DIRECTORY) < 0)
            {
                printf("This directory doesn't exist\n");
                return;
            }
            DIR *dir_t = opendir(dir[0]);
            while ((dir_no = readdir(dir_t)) != NULL)
            {
                if (dir_no->d_name[0] != '.')
                    printf("%s \n", dir_no->d_name);
                else if (aa == 1)
                {
                    printf("%s \n", dir_no->d_name);
                }
            }
            closedir(dir_t);
        }
        else
        {
            for (j = 0; j < length; j++)
            {
                struct dirent *dir_no;
                if (open(dir[j], O_DIRECTORY) < 0)
                {
                    printf("This directory doesn't exist\n");
                    continue;
                }
                printf("%s:\n", dir[j]);
                DIR *dir_t = opendir(dir[j]);
                while ((dir_no = readdir(dir_t)) != NULL)
                {
                    if (dir_no->d_name[0] != '.')
                        printf("%s \n", dir_no->d_name);
                    else if (aa == 1)
                    {
                        printf("%s \n", dir_no->d_name);
                    }
                }
                if (j != length - 1)
                    printf("\n");
                closedir(dir_t);
            }
        }
    }
    
}