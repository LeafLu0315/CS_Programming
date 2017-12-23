#include<stdio.h>
#include<string.h>
int Abs(int);
int main(void){
    char c[1001];
    int odd,even,i;
    while(scanf("%s",c)!=EOF){
        odd=0;
        even=0;
        for(i=0;i<strlen(c);i++){
            if(i%2) odd+=c[i]-'0';
            else even+=c[i]-'0';
        }
        printf("%d\n",Abs(odd-even));
    }
    return 0;
}

int Abs(int a){
    if(a>0) return a;
    return -a;
}
