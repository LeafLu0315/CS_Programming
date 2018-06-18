#include<bits/stdc++.h>
using namespace std;
int M,m,weight[20][20],nn;
void place_queen(int i,int queen_pos[]){
    int conflict;
    if(i==nn){
        int sum=0;
        for(int j=0;j<nn;j++) sum+=weight[j][queen_pos[j]];
        if(sum>M) M=sum;
        if(sum<m) m=sum;
    }
    for(int k=0;k<nn;k++){
        conflict=0;
        for(int j=0;j<i&&!conflict;j++)
            if(queen_pos[j]==k || abs(k-queen_pos[j])==(i-j)) conflict=1;
        if(!conflict){
            queen_pos[i]=k;
            place_queen(i+1,queen_pos);
        }
    }
    return;
}

void sol(){
    M=INT_MIN;m=INT_MAX;
    memset(weight,0,sizeof(weight));
    scanf("%d",&nn);
    for(int i=0;i<nn;i++) for(int j=0;j<nn;j++) scanf("%d",&weight[i][j]);
    int queen_pos[nn];
    place_queen(0,queen_pos);
    if(M==INT_MIN && m == INT_MAX) printf("-1 -1\n");
    else printf("%d %d\n",M,m);
    return;
}

int main(void){
    int ncase;
    freopen("Branch_8Queen.in","r",stdin);
    scanf("%d",&ncase);
    while(ncase--) sol();
    return 0;
}
