#include<stdio.h>
#include<string.h>
#define N 1024
void proc(char []);
int main(void){
    char str[N];
    while(gets(str)!=NULL) proc(str);
    return 0;
}

void proc(char str[]){
    char num[N],word[N];
    int i,j,pos,times;
    for(i=0;str[i]!='\0';i++){
        for(j=i,pos=0;isdigit(str[j]);j++,pos++) num[pos] = str[j];
        num[pos] = '\0';
        times = atoi(num);
        for(pos=0;isalpha(str[j]);j++,pos++) word[pos] = str[j];
        word[pos] = '\0';
        while(times--) printf("%s",word);
    }
    printf("\n");
}
