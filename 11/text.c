#include<stdio.h>
#include<string.h>
int main(){
    int times,loop=0;
    scanf("%d",&times);
    char c[100]={0};
    while(1){
        if(loop++==times) break;
        scanf(" %[^\n]s",c);
        int i,ascii[26]={0};
        for(i=0;i<strlen(c);i++){
            if(c[i]>=65 && c[i]<=90)
                ascii[c[i]-65]++;
            if(c[i]>=97 && c[i]<=122)
                ascii[c[i]-97]++;
        }
        int maximum=0;
        for(i=0;i<26;i++)
            if(ascii[i]>maximum) maximum=ascii[i];
        for(i=0;i<26;i++)
            if(ascii[i]==maximum) printf("%c",i+65);
        printf("\n");
    }
    return 0;
}
