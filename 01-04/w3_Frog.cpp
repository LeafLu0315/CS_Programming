#include<iostream>
#define N 12000
using namespace std;

int main(){
    while(1){
        int ncell,m,cell[N],check[2][N],i,j,p,dire,ce;
        cin>>ncell>>m;
        if(!ncell) break;
        for(i=0;i<ncell;i++) cin>>cell[i];
        while(m--){
            cin>>p>>dire;
            for(i=0;i<2;i++) for(j=0;j<N;j++) check[i][j]=0;
            i=0;
            while(1){
                i++;
                if(check[(dire+1)/2][p]) break;
                if(cell[p]<0) dire=-dire;
                ce=(cell[p]<0)? -cell[p]:cell[p];
                p=p+dire*ce;
                if(p>=ncell || p<0) break;
            }
            if(p>=ncell) cout<<"Forward";
            else if(p<0) cout<<"Backward";
            else cout<<"Cycle "<<i-check[(dire+1)/2][p];
            cout<<endl;
        }
    }
    return 0;
}
