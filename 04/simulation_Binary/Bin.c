#include<stdio.h>
#include<string.h>
int toInt(char []);
int main(){
    int ans,count;
    char str[40];
    while(1){
        ans=0;
        scanf("%d",&count);
        if(!count) break;
        while(count--){
            scanf("%s",str);
            ans+=toInt(str);
        }
        printf("%d\n",ans);
    }
    return 0;
}

int toInt(char bin[]){
    int a=0,i,b=1;
    for(i=strlen(bin)-1;i>=0;i--){
        if(bin[i] & 1) a+=b;
        b*=2;
    }
    return a;
}

