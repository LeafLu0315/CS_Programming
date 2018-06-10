#include<stdio.h>
#include<memory.h>
#define MAXIMUM -1000000
#define N 25
typedef struct{
    int row,cost;
    short bd[N][N];
}BOARD;
void rec(BOARD);
void solve(int);
int ABS(int);
int MAX(int,int);
int MIN(int,int);
int NEGATIVE(int);
int ans,n;
int cell[N][N],val[N];
int main(){
    int ncase,i,j;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&n); //n*n board
        for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&cell[i][j]);  // input the information
        if(n <= 0 || n == 2 || n == 3) printf("-1 -1"); // if n x n board is negative or {0,2,3} then there is no solution
        else if(n>N) printf("Not supported");
        else if(n == 1) printf("%d %d",cell[0][0],cell[0][0]);
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
    ans=MAXIMUM;
    for(i=0;i<n;i++){
        val[i]=MAXIMUM;
        for(j=0;j<n;j++) val[i] = MAX(val[i],cell[i][j]); //find the maximum in n0 n1 n2...nn
    }
    for(i=n-2;i>=0;i--) val[i]+=val[i+1];     // calculate the values from down to top
    for(i=0;i<n;i++) for(j=0;j<n;j++) x.bd[i][j]=1; // all are 1s
    x.row=x.cost=0; //initialize
    rec(x);
    printf("%d",(act) ? -ans:ans);
}

void rec(BOARD x){
    if(x.row == n){     // find the max
        ans = MAX(ans,x.cost);
        return;
    }
    if(x.cost+val[x.row]<=ans) return;   //see whether down board have the best solution or not
    int i,j,k;
    BOARD t;
    for(i=0;i<n;i++){
        if(x.bd[x.row][i]){
            t=x;
            t.bd[t.row][i]=2;       //0 => markup 1 => where they can put 2 => put queen
            t.cost+= cell[t.row++][i];
            for(j=t.row;j<n;j++) t.bd[j][i]=0;  //mark the column
            j=t.row; k=i+1;
            while(j<n && k<n) t.bd[j++][k++]=0; //mark the diagonal 00 11 22 33....
            j=t.row; k=i-1;
            while(j<n && k>=0) t.bd[j++][k--]=0; // mark another side of diagonal
            rec(t); //keep the board and continue recursive
        }
    }
    return;
}

int MAX(int a,int b){
    return (a>b) ? a:b;
}
int MIN(int a,int b){
    return (a<b) ? a:b;
}
int ABS(int a){
    return (a>0) ? a:-a;
}
int NEGATIVE(int a){
    return (a<0) ? a:-a;
}
