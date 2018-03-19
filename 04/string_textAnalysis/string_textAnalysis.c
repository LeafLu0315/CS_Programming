#include<stdio.h>
#include<string.h>
int main(){
    int times,i,maximum;
    int ascii[26];
    scanf("%d\n",&times);
    char c[100]={0};
    while(times--){
        scanf(" %[^\n]s",c);
        for(i=0;i<26;i++) ascii[i]=0;
        maximum=0;
        for(i=0;i<strlen(c);i++){
            if(c[i]>='A' && c[i]<='Z') ascii[c[i]-'A']++;
            if(c[i]>='a' && c[i]<='z') ascii[c[i]-'a']++;
        }
        for(i=0;i<26;i++) if(ascii[i]>maximum) maximum=ascii[i];
        for(i=0;i<26;i++) if(ascii[i]==maximum) printf("%c",i+'A');
        printf("\n");
    }
    return 0;
}
