#include<stdio.h>
#include<stdlib.h>
#define ZERO 1e-4
#define N 110
void swap(int row1,int row2,int n);
int correct(int);
void det(int n,double *determine);
void findans(int n);
void printMat(int,double,FILE*);
void solve(int n, double determine);
double mat[N][N],sol[N];
/* Matrix =
    00 01 02 03..
    10 11 12 13..
    20 21 22 23..*/
int main(int argc,char *argv[]){
    int n,i,j,c=0;
    FILE *fin,*fout;
    if(!argv[1] || !argv[2]){   // judge if there are two file names
        printf("Please input two files\n");
        return -1;
    }
    fin = fopen(argv[1],"r");
    fout = fopen(argv[2],"w");
    if(fin==NULL){
        printf("can't read the file\n");
        return -1;
    }
    if(fout==NULL){
        printf("can't write the file\n");
        return -1;
    }
    while(fscanf(fin,"%d",&n)){
        fprintf(fout,"============>Case %d <===========\n",c++);
        if(!n) break;
        int swapping = 0;
        for(i=0;i<n;i++) for(j=0;j<n;j++) fscanf(fin,"%lf",&mat[i][j]);
        for(i=0;i<n;i++) fscanf(fin,"%lf",&mat[i][n]);
        for(i=0;i<n;i++){
            if(abs(mat[i][i])<=ZERO){
                for(j=0;j<n;j++){
                    if(i == j) continue;
                    if(abs(mat[j][i])>=ZERO){
                        swap(i,j,n);
                        swapping++; //determine * -1 or not
                    }
                }
            }
        }
        double determine = (swapping%2)? -1:1;
        det(n,&determine);  //calculate determine
        if(abs(determine)<=ZERO) fprintf(fout,"There is no solution or infinite solution, determine of matrix is approximate to 0\n");
        solve(n,determine); //solve the matrix
        findans(n); //find x,y,z,....
        printMat(n,determine,fout); //print the matrix
        if(correct(n)) fprintf(fout,"Answer is correct\n"); //judge the ans is correct or not
        else if(determine>=ZERO) fprintf(fout,"Answer is not correct\n");
    }
    return 0;
}

void det(int n,double *determine){
    if(n==2){
        *determine = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        return ;
    }
    if(n==3){
        double a1 = mat[0][0] * (mat[1][1]*mat[2][2]-mat[2][1]*mat[1][2]);
        double a2 = mat[0][1] * (mat[1][2]*mat[2][0]-mat[2][2]*mat[1][0]);
        double a3 = mat[0][2] * (mat[1][0]*mat[2][1]-mat[2][0]*mat[1][1]);
        *determine = a1+a2+a3;
        return;
    }
}

void swap(int row1,int row2,int n){
    double tmp;
    int i,j;
    for(i=0;i<n;i++){
        tmp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = tmp;
    }
    return;
}

void solve(int n,double determine){
    int i,j,k;
    for(i=0;i<n;i++){
        double target = mat[i][i];
        for(j=0;j<=n;j++) mat[i][j] /= target;  // let all divide by [i][i]
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k=0;k<=n;k++){
                mat[j][k] += (-1)*(mat[j][i]/mat[i][i]);
            }
        }
    }
    return ;
}

void findans(int n){
    int i,j;
    int flag = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) continue;
            if(mat[i][j]>ZERO) flag=1;
        }
        if(!flag) sol[i] = mat[i][n];
    }
    return ;
}

void printMat(int n,double determine,FILE *fout){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++) fprintf(fout,"%f\t",mat[i][j]);
        fprintf(fout,"\n");
    }
    fprintf(fout,"determine = %f\n",determine);
    for(i=0;i<n;i++) fprintf(fout,"%f\t",sol[i]);
    fprintf(fout,"\n");
    return;
}

int correct(int n){
    int i,j;
    for(i=0;i<n;i++){
        double a = 0;
        for(j=0;j<n;j++) a+=mat[i][j]*sol[i];
        if(a != mat[i][n]) return 0;
    }
    return 1;
}
