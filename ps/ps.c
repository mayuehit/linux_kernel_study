#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024
int main(void){
    FILE *fp;
    int lines = 0;
    char name[128];
    char value[128];
    // if((fp=fopen("/proc/1/statuss","r"))==NULL){
    //     return -1;
    // }
    if((fp=fopen("/opt/code/myproject/a.txt","r"))==NULL){
        return -1;
    }
    printf("USER\tPID\tCPU\tMEM\tVSZ\tRSS\tTTY\tSTAT\tSTART\tTIME\tCOMMAND\n");
    while(fscanf(fp,"%s%s",name,value)==2){
        printf("%s\t%s\n",name,value);
    }

    return 0;
    
}

