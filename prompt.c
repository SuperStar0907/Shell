#include "header.h"

void prompt(char *init, char *current)
{
    char x[1000], y[1000];
    int check = gethostname(y, 25);
    getlogin_r(x, 1024);
    printf("<%s@%s:", x, y);
    char curr_dir[10000];
    int i = 0;
    char arg[100][100];
    int k = 0;
    if(strlen(current) < strlen(init)){
        printf("%s>",current);
        return;
    }
    printf("~");
    if(strlen(current) >= strlen(init))
    {
        for (i = strlen(init); i < strlen(current); i++)
        {
            strncat(curr_dir,current+i,1);
        }
    }
    else{
        strcpy(curr_dir,current);
    }
    printf("%s>",curr_dir);
    strcpy(curr_dir,"");
}
