#include<stdio.h>
int main(){
    int times,n;
//    freopen("array_transpose.in","r",stdin);
    scanf("%d",&times);
    while(times--){
        scanf("%d",&n);
        int Matrix[n][n],i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++) scanf("%d",&Matrix[i][j]);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++){
                int t=Matrix[i][j];
                Matrix[i][j]=Matrix[j][i];
                Matrix[j][i]=t;
            }
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++)
                printf("%d ",Matrix[i][j]);
            printf("%d\n",Matrix[i][j]);
        }
        if(times) printf("\n");
    }
    return 0;
}

