#include<stdio.h>

int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    int num[N],i;
    num[0]=0;
    for(i=1;i<=N;i++)
        scanf("%d",&num[i]);
    while(K--){
        int left,right,sum1=0,sum2=0;
        scanf("%d%d",&left,&right);
        if(left>right){
            int t=left;
            left=right;
            right=t;
        }
        for(i=1;i<=left-1;i++) sum1+=num[i];
        for(i=1;i<=right;i++) sum2+=num[i];
        printf("%d\n",sum2-sum1);
    }
    return 0;
}
