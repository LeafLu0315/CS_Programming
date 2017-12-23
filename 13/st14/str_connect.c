#include<stdio.h>
#include<string.h>
void connect(char [],char []);
int main(){
    int times,num,i;
//    freopen("ST14.in","r",stdin);
    char combine[3000],str[100];
    scanf("%d",&times);
    while(times--){
        scanf("%d",&num);
        scanf("%s",combine);
        while(--num){
            scanf("%s",str);
            connect(combine,str);
        }
        printf("%d\n%s\n",strlen(combine),combine);
    }
    return 0;
}

void connect(char c1[],char c2[]){
    int L1=strlen(c1),L2=strlen(c2),max_length=L1,i;
    if(L2>max_length) max_length=L2;
    while(1){
        if(strncmp(c1+L1-max_length,c2,max_length)==0){
            for(i=max_length;i<L2;i++) c1[L1++]=c2[i];
            c1[L1]='\0';
            break;
        }
        max_length--;
    }
    return ;
}
