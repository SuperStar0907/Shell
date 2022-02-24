#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
// #include <sys/sysmacros.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/utsname.h>
#include "echo.h"
#include "prompt.h"
#include "ls.h"
#include "cd.h"
#include "pinfo.h"

char history[20][100];
int che,ppp,pp,count,pppp ;

int strio(char *string);
