#include<stdio.h>
#define MAX 10
int main(){
    int n,y,p,i,j;
    int matrix[MAX][MAX]={{0},{0}};
    while(1){
        scanf("%d%d%d",&n,&y,&p);
        if(n==0) break;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++) scanf("%d",&matrix[i][j]);
    }
    return 0;
}
