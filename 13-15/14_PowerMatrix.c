#include<stdio.h>
#include<string.h>
#define N 5
void mul(int a[N][N],int b[N][N],int c[N][N],int n,int p){
    int i,j,k;
    long long t1,t2;
    for(i=0;i<n;i++) for(j=0;j<n;j++){
        t1=0;
        for(k=0;k<n;k++){
            t2=a[i][k];
            t2=(t2*b[k][j])%p;
            t1=(t1+t2)%p;
        }
        c[i][j]=(int)t1;
    }
}

void copy(int from[N][N],int to[N][N],int t){
    int i,j;
    for(i=0;i<t;i++) for(j=0;j<t;j++) to[i][j]=from[i][j];
}

void xyp(int a[N][N],int y,int n,int p){
    int i,j;
    int res[N][N],t1[N][N],t2[N][N];
    for(i=0;i<n;i++) for(j=0;j<n;j++) res[i][j]=0;
    for(i=0;i<n;i++) res[i][i]=1;
    copy(a,t1,n);
    while(y){
        if(y&1){
            mul(res,t1,t2,n,p);
            copy(t2,res,n);
        }
        y>>=1;
        mul(t1,t1,t2,n,p);
        copy(t2,t1,n);
    }
    copy(res,a,n);
}

int main(){
    int x[N][N],t[N][N];
    int i,j,d,y,p;
    while(1){
        scanf("%d%d%d",&d,&y,&p);
        if(d==0) break;
        for(i=0;i<d;i++) for(j=0;j<d;j++) scanf("%d",&x[i][j]);
        copy(x,t,d);
        xyp(t,y,d,p);
        for(i=0;i<d;i++){
            printf("%d",t[i][0]);
            for(j=1;j<d;j++) printf(" %d",t[i][j]);
            printf("\n");
        }
    }
    return 0;
}
