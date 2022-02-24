#include "header.h"
void pinfo(char * tok){
    int pid=(tok==NULL)?getpid():strio(tok);
    char loc[1000]="/proc/",proce[1000],execute[1000]="/proc/",status[1000],primary[1000],print_status[1000],print_size[1000],print_path[1000];
    sprintf(proce,"%d",pid);
    strcat(loc,proce);
    strcat(loc,"/status");
    strcat(execute, "/exe");
    FILE * fp=fopen(loc,"r");
    if(fp==NULL){
        printf("Process %d does not exist\n",pid);
    }
    while(fgets(status,1000,fp)!=NULL){
        if(strstr(status,"State:")!=NULL){
            strcpy(print_status,status);
        }
        if(strstr(status,"VmSize:")!=NULL){
            strcpy(print_size,status);
        }
    }
    fclose(fp);
	readlink(execute, print_path, 1024);
    printf("pid -- %d\n", pid);
    printf("Process Status -- %s\n", print_status);
    printf("Memory(in kB) -- %s\n", print_size);
    printf("Executable Path -- %s\n", print_path);
}