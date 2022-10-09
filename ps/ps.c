#include <stdio.h>
#include <string.h>
#define MAX_LINE 1024
int main(void){
    // "/proc/$pid/status"
    char buf[MAX_LINE];
    int len;
    //文件读写
    char a[20]="/proc/1/status";
    FILE *p = fopen(a,"r");
    if(p==NULL){
        return 0;
    }
    while(fgets(buf,MAX_LINE,p)!=NULL){
        len = strlen(buf);
        buf[len-1]='\0';
        printf("%s %d",buf,len-1);
        printf("\n");
    }
    return 0;
}

