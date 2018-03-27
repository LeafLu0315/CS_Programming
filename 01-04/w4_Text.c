#include<stdio.h>
#include<string.h>

int main(){
    int ncase,flag=1;
    scanf("%d",&ncase);
    while(ncase--){
        char c[100],tr[100],max=0;
        int i,count[123]={0};
        if(flag) gets(tr),flag=0;
        gets(c);
        for(i=0;i<strlen(c);i++){
            if(!isalpha(c[i])) continue;
            if(islower(c[i])) c[i]=toupper(c[i]);
            count[c[i]]++;
        }
        for(i=65;i<91;i++) if(count[i]>max) max=count[i];
        for(i=65;i<91;i++) if(count[i]==max) printf("%c",i);
        if(ncase!=0) printf("\n");
    }
    return 0;
}
