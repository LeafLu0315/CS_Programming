#include<iostream>
using namespace std;
typedef struct{
    long long mat[3][3];
}MAT;
MAT mult(MAT,MAT,long long);
void calc(long long,long long);
MAT M={{{0,0,0},{1,0,0},{0,1,0}}};
int main(){
    long long n,p;
    while(cin>>n>>p>>M.mat[0][0]>>M.mat[0][1]>>M.mat[0][2]){
        if(n<=3) cout<<1<<endl;
        else calc(n,p);
    }
    return 0;
}

MAT mult(MAT a,MAT b,long long p){
    int i,j,k;
    long long t;
    MAT res={{{0}}};
    for(i=0;i<3;i++) for(j=0;j<3;j++){
        t=0;
        for(k=0;k<3;k++) t=(t+(a.mat[i][k]*b.mat[k][j])%p)%p;
        res.mat[i][j]=t;
    }
    return res;
}

void calc(long long n, long long p){
    int y=n-3;
    long long res;
    MAT t={{{1,0,0},{0,1,0},{0,0,1}}},xi,t2;
    xi=M;
    while(y){
        if(y&1) t=mult(t,xi,p);
        xi=mult(xi,xi,p);
        y>>=1;
    }
    res=(t.mat[0][0]+t.mat[0][1]+t.mat[0][2])%p;
    cout<<(int)res<<endl;
    return ;
}
