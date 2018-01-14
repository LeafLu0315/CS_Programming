#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000],s1[1000],digit[1000];
int i,j,k,ncases,x,y;
int main(){
    while(gets(s)!=NULL){
        for(i=0;s[i]!='\0';i=j){
            for(k=0,j=i;isdigit(s[j]);k++,j++) digit[k]=s[j];
            digit[k]='\0';
            x=atoi(digit);
            for(k=0;isalpha(s[j]);j++,k++) s1[k]=s[j];
            s1[k]='\0';
            while(x--) printf("%s",s1);
        }
        printf("\n");
    }
    return 0;
}
