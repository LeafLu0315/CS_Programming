#include<stdio.h>
int main(){
    int times,row,col;
//    freopen("array_matrix.in","r",stdin);
    scanf("%d",&times);
    while(times--){
        scanf("%d%d",&row,&col);
        int Matrix[row][col],Vector[col],Result[row];
        int i,j;
        for(i=0;i<row;i++) Result[i]=0;
        for(i=0;i<row;i++)
            for(j=0;j<col;j++) scanf("%d",&Matrix[i][j]);
        for(i=0;i<col;i++) scanf("%d",&Vector[i]);
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                Result[i]+=Matrix[i][j]*Vector[j];
        for(i=0;i<row-1;i++) printf("%d ",Result[i]);
        printf("%d\n",Result[i]);
    }
    return 0;
}
