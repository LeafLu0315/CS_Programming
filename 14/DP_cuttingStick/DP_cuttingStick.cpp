#include<iostream>
#include<cstdio>
#define N 1000
#define MAX 100000000
using namespace std;
void sol(int);
void init(int);
int cost(int,int);
int point[N];
int table[N][N];
int main(void){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}

void sol(int n){
    int m;
    scanf("%d",&m);
    point[0]=0; point[m+1]=n;
    for(int i=1;i<=m;i++) scanf("%d",&point[i]);
    init(m+2);
    int ans = cost(0,m+1);
    printf("The minimum cutting is %d.\n",ans);
}

void init(int n){
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) table[i][j]=-1;
}

int cost(int a,int b){
    if(b <= a+1) return 0;
    if(table[a][b] >= 0) return table[a][b];
    int mincost = MAX;
    for(int i=a+1;i<b;i++){
        int t=cost(a,i)+cost(i,b);
        mincost=min(mincost,t);
    }
    mincost += point[b]-point[a];
    table[a][b]=mincost;
    return mincost;
}
