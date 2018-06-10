#include<stdio.h>
#include<stdlib.h>
#define ERROR 1e-4
#define N 105
double det(int);
double twodet(double [3][3]);
double threedet(double [3][3]);
int detectErr(double);
void cpArr(int,double[3][3]);
void init(int);
void solve(int,double);
void swap(int,int,int);
double matrix[N][N]={0},x[N]={0};
/* Matrix position :  Sol:
    00 01 02 03....    0n
    10 11 12 13....    1n
    20 21 22 23....    2n */
int main(int argc,char *argv[]){
    int n,i,j;
    double determine;
    while(scanf("%d",&n)){
        if(!n) break;
        for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%lf",&matrix[i][j]);
        for(i=0;i<n;i++) scanf("%lf",&matrix[i][n]);
        init(n);
        int err = 0;
        double arr[3][3];
        if(n == 2){
            cpArr(n,arr);
            determine = twodet(arr);
            err = detectErr(determine);
        }
        else if(n == 3){
            cpArr(n,arr);
            determine = threedet(arr);
            err = detectErr(determine);
        }
        else printf("Not supported\n");
//        if(err) continue;
        solve(n,determine);
        printf("determine = %f\n",determine);
    }
    return 0;
}

void cpArr(int n, double arr[3][3]){
    int i,j;
    for(i=0;i<n;i++) for(j=0;j<n;j++) arr[i][j] = matrix[i][j];
    return;
}

int detectErr(double determine){
    if(abs(determine)<= ERROR){
        printf("There is no solution or infinite solution, determine of matrix is approximate to 0\n");
        return 1;
    }
    return 0;
}

void solve(int n,double determine){
    int i,j,k,size=0;
    if(n==2){
        double tmp[n][n];
        tmp[0][0] = matrix[1][1] ; tmp[0][1] = -matrix[0][1];
        tmp[1][0] = -matrix[1][0]; tmp[1][1] = matrix[0][0];
        for(i=0;i<n;i++) for(j=0;j<n;j++) x[i] += tmp[i][j]*matrix[j][n];
        printf("1\t0\t%f\n0\t1\t%f\n",x[0],x[1]);
        return;
    }
    if(n==3){

    }
}

void init(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) matrix[i][j]=0;
        x[i]=0;
    }
    return;
}

void swap(int row1,int row2,int n){
    int i;
    for(i=0;i<=n;i++){
        double tmp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = tmp;
    }
    return;
}

double twodet(double arr[3][3]){
    return arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
}
double threedet(double arr[3][3]){
    double a1 = arr[0][0] * (arr[1][1]*arr[2][2]-arr[2][1]*arr[1][2]);
    double a2 = arr[0][1] * (arr[1][2]*arr[2][0]-arr[2][2]*arr[1][0]);
    double a3 = arr[0][2] * (arr[1][0]*arr[2][1]-arr[2][0]*arr[1][1]);
    return a1+a2+a3;
}
