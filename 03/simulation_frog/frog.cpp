#include<iostream>
#define N 10000
using namespace std;

int main(){
    int n,act,pos,dir,situation,i,j,k,counter,loop;
    int cell[N],record[2][N];
    while(1){
        cin>>n>>act;
        if(!n) break;
        for(i=0;i<n;i++) cin>>cell[i];
        while(act--){
            counter=1; situation=loop=0;
            for(i=0;i<2;i++) for(j=0;j<n;j++) record[i][j]=0;
            cin>>pos>>dir;
            while(situation == 0){
                k=(dir>0) ? 1:0;
                if(record[k][pos]>0){
                    loop=counter-record[k][pos];
                    situation=3;
                    break;
                }
                record[k][pos]=counter++;
                if(cell[pos]<0) dir*=-1;
                if(cell[pos]<0) pos+=dir*(-cell[pos]);
                else pos+=dir*cell[pos];
                if(pos>=n) situation=1;
                else if(pos<0) situation=2;

            }
            if(situation == 1) cout<<"Forward"<<endl;
            else if(situation == 2) cout<<"Backward"<<endl;
            else if(situation == 3) cout<<"Cycle "<<loop<<endl;
        }
    }
    return 0;
}
