#include<cstdio>
#define N 101
int A,B,C;
int table[N][N][N];
int run(int,int,int,int);
int main(void){
    int n,a,b,c,d;
    freopen("recursion_witchcraft.in","r",stdin);
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d%d%d%d",&d,&a,&b,&c,&A,&B,&C);
        for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) for(int k=0;k<=c;k++) table[i][j][k]=-1;
        printf("%s\n",run(d,a,b,c)?"yes":"no");
    }
    return 0;
}

int run(int d,int a,int b,int c){
    if(!d) return 1;
    if(table[a][b][c]>=0) return table[a][b][c];
    table[a][b][c] = 0;
    if(d-A>=0 && a>0 && run(d-A,a-1,b,c)==1) table[a][b][c]=1;
    if(d-B>=0 && b>0 && run(d-B,a,b-1,c)==1) table[a][b][c]=1;
    if(d-C>=0 && c>0 && run(d-C,a,b,c-1)==1) table[a][b][c]=1;
    return table[a][b][c];
}
