#include<bits/stdc++.h>
#define N 0x3F3F3F3F
using namespace std;
void sol(int n){
    int l=0,r=N,val=N,tmp;
    map<int,int> num;
    map<int,int>::iterator it;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        it=num.find(tmp);
        if(it!=num.end()){
            tmp=i-it->second;
            if(tmp<r-l){
                l=it->second;
                r=i;
                val=it->first;
            }
            it->second=i;
        }
        else num.insert(make_pair(tmp,i));
    }
    if(r!=N) printf("(%d,%d):%d\n",l,r,val);
    else printf("No solution\n");
}
int main(void){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}

