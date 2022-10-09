#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024
int main(void){
    FILE *fp;
    int lines = 0;
    char name[128];
    char value[128];
    char user[128];
    char pid[128];
    char cpu[128];
    char mem[128];
    char vsz[128];
    char rss[128];
    char tty[128];
    char stat[128];
    char start[128];
    char time[128];
    char command[128];
    
    if((fp=fopen("/proc/1/status","r"))==NULL){
        return -1;
    }
    // if((fp=fopen("/opt/code/myproject/a.txt","r"))==NULL){
    //     return -1;
    // }
    printf("USER\tPID\tCPU\tMEM\tVSZ\tRSS\tTTY\tSTAT\tSTART\tTIME\tCOMMAND\n");
    int line = 0;
    while(fscanf(fp,"%s%s",name,value)==2){
        printf("%s\t%s\n",name,value);
        if(line++>40){
            break;
        }
        if(strcmp(name,"Name")==0){
            strcpy(command,value);
        }else if(strcmp(name,"Pid")==0){
            strcpy(pid,value);
        }else if(strcmp(name,"VmSize")==0){
            strcpy(vsz,value);
        }
        else if(strcmp(name,"VmRSS")==0){
            strcpy(rss,value);
        }
        else if(strcmp(name,"State")==0){
            strcpy(stat,value);
        }
    }
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",user,pid,cpu,mem,vsz,rss,tty,stat,start,time,command);
    return 0;
    
}

