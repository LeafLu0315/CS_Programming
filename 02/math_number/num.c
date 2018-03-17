#include<stdio.h>
#include<string.h>
int main(){
    char find[3],sch[10];
    int i,ans,l=0;
    while(scanf("%s%s",find,sch)!=EOF){
        if(l++) printf("\n");
        ans=0;
        for(i=0;i<strlen(sch);i++) if(!strncmp(find,sch+i,strlen(find))) ans++;
        printf("%d",ans);
    }
    return 0;
}
