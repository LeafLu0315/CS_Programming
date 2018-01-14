#include<stdio.h>
#define MAX 10
void mult(int [][MAX],int [][MAX],int [][MAX],int,int);
void Copy(int [][MAX],int [][MAX],int);
void Calculate(int [][MAX],int,int,int);
int main(){
    int n,y,p,i,j;
    int matrix[MAX][MAX],Result[MAX][MAX];
    while(1){
        scanf("%d%d%d",&n,&y,&p);
        if(n==0) break;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++) scanf("%d",&matrix[i][j]);
        Copy(matrix,Result,n);
        Calculate(Result,y,n,p);
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++)
                printf("%d ",Result[i][j]);
            printf("%d\n",Result[i][j]);
        }
    }
    return 0;
}

void mult(int a[][MAX],int b[][MAX],int result[][MAX],int n,int p){
    int i,j,k;
    long long int tmp,tmp2;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            tmp=0;
            for(k=0;k<n;k++){
                tmp2=a[i][k];
                tmp2=(tmp2*b[k][j])%p;
                tmp=(tmp+tmp2)%p;
            }
            result[i][j]=(int)tmp;
        }
    return ;
}

void Copy(int from[][MAX],int to[][MAX],int size){
    int i,j;
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            to[i][j]=from[i][j];
    return;
}

void Calculate(int arr[][MAX],int y,int n,int p){
    int i,j;
    int result[MAX][MAX]={{0},{0}},t[MAX][MAX],t2[MAX][MAX];
    for(i=0;i<n;i++) result[i][i]=1;
    Copy(arr,t,n);
    while(y){
        if(y&1){
            mult(result,t,t2,n,p);
            Copy(t2,result,n);
        }
        y>>=1;
        mult(t,t,t2,n,p);
        Copy(t2,t,n);
    }
    Copy(result,arr,n);
    return ;
}
