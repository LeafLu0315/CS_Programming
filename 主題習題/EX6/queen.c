#include<stdio.h>
#define MAXIMUM 1000000
#define MAX(a,b) ((a)>(b)) ? a:b
#define MIN(a,b) ((a)<(b)) ? a:b
#define N 20
typedef struct{
    int row,cost;
    short bd[N][N];
}BOARD;
int total=0,max,min,n;
int cell[N][N],row_up[N];
void rec(BOARD);
int main(){
    int ncase,i,j;
//    freopen("eq_16.in","r",stdin);
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&n);
        BOARD x;
        for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&cell[i][j]);
        total = 0;
        max=-MAXIMUM; min = MAXIMUM;
        for(i=0;i<n;i++){
            row_up[i]=-MAXIMUM;
            for(j=0;j<n;j++) row_up[i] = MAX(row_up[i],cell[i][j]);
        }
        for(i=n-2;i>=0;i--) row_up[i]+=row_up[i+1];
        for(i=0;i<n;i++) for(j=0;j<n;j++) x.bd[i][j]=1;
        x.row=x.cost=0;
        rec(x);
        printf("%d %d",max,min);
        if(ncase) printf("\n");
    }
    return 0;
}

void rec(BOARD b){
    int i,j,k;
    BOARD t;
    if(b.row == n){
        total++;
        max = MAX(max,b.cost);
        min = MIN(min,b.cost);
        return;
    }
    if(b.cost+row_up[b.row]<=max && b.cost+row_up[b.row]<=min) return;
    for(i=0;i<n;i++){
        if(b.bd[b.row][i]){
            t=b;
            t.bd[t.row][i]=2;
            t.cost+= cell[t.row++][i];
            for(j=t.row;j<n;j++) t.bd[j][i]=0;
            j=t.row;
            k=i+1;
            while(j<n && k<n) t.bd[j++][k++]=0;
            j=t.row;
            k=i-1;
            while(j<n && k>=0) t.bd[j++][k--]=0;
            rec(t);
        }
    }
    return;
}
