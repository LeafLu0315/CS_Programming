#include<stdio.h>
#include<string.h>

int main(){
    int n,nfirst=0,i;
    scanf("%d",&n);
    while(n--){
        if(nfirst) printf("\n");
        char p[1000]={0},q[50]={0},r[50]={0};
        gets(p); gets(q); gets(r);
        for(i=0;i<strlen(p);i++){
            if(!(strncmp(p+i,q,strlen(q)))){
                printf("%s",r);
                i+=strlen(q)-1;
            }
            else printf("%c",p[i]);
        }
        nfirst=1;
    }
    return 0;
}
