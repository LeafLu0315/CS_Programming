#include<stdio.h>
#define MAXIMUM -1000000
#define MAX(a,b)    ((a)>(b)) ? a:b
#define MIN(a,b)    ((a)<(b)) ? a:b
#define ABS(a)      ((a)>0)   ? a:-a
#define NEGATIVE(a) ((a) < 0) ? a:-a
#define N 25
typedef struct{
    int row,cost;
    short bd[N][N];
}BOARD;
void rec(BOARD);
void solve(int);
int max,n;
int cell[N][N],val[N];
int main(){
    int ncase,i,j;
    freopen("eq_16.in","r",stdin);
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&n); //n*n board
        for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&cell[i][j]);  // input the information
        if(n < 0 || n == 2 || n == 3) printf("-1 -1"); // if n x n board is negative or 2 or 3 then there is no solution
        else{ //else solve the problem 0 is max 1 is min
            solve(0);
            printf(" ");
            solve(1);
        }
        if(ncase) printf("\n");
    }
    return 0;
}

void solve(int act){
    BOARD x;
    int i,j;
    if(act) for(i=0;i<n;i++) for(j=0;j<n;j++) cell[i][j]=NEGATIVE(cell[i][j]);   //when all are being negative then find the max is the min
    else for(i=0;i<n;i++) for(j=0;j<n;j++) cell[i][j]=ABS(cell[i][j]);   //when all are being negative then find the max is the min
    /* Max */
    max=MAXIMUM;
    for(i=0;i<n;i++){
        val[i]=MAXIMUM;
        for(j=0;j<n;j++) val[i] = MAX(val[i],cell[i][j]); //find the maximum in n0 n1 n2...nn
    }
    for(i=n-2;i>=0;i--) val[i]+=val[i+1];     // calculate the values from down to top
    for(i=0;i<n;i++) for(j=0;j<n;j++) x.bd[i][j]=1; // all are 1s
    x.row=x.cost=0; //initialize
    rec(x);
    printf("%d",(act) ? -max:max);
}

void rec(BOARD b){
    int i,j,k;
    BOARD t;
    if(b.row == n){     // n queen is put then find the max
        max = MAX(max,b.cost);
        return;
    }
    if(b.cost+val[b.row]<=max) return;   //see whether down board have the best solution or not
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
