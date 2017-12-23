#include<stdio.h>
#include<string.h>
int prime(int);
int counting(char);
int main(){
    char c[40];
    int i,sum;
    while(scanf("%s",c)!=EOF){
        sum=0;
        for(i=0;i<strlen(c);i++)
            sum+=counting(c[i]);
        if(prime(sum)) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}

int prime(int a){
    int i;
    if(a==1) return 0;
    for(i=2;i*i<=a;i++)
        if(a%i==0) return 0;
    return 1;
}

int counting(char c){
    if(c>='a'&&c<='z') return c-'a'+1;
    if(c>='A'&&c<='Z') return c-'A'+27;
    return 0;
}
