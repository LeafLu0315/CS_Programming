#include<stdio.h>
#include<string.h>
int parsing(char []);
int main(){
    char str[300];
    while(gets(str)!=NULL) printf("%d\n",parsing(str));
    return 0;
}

int parsing(char str[]){
    char *del = ", ",*tok;
    int sum=0;
    tok=strtok(str,del);
    while(tok!=NULL){
        sum+=atoi(tok);
        tok=strtok(NULL, del);
    }
    return sum;
}
