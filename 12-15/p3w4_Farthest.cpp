#include<bits/stdc++.h>
#define range 2010
using namespace std;
int main(void){
    int n,i;
    while(scanf("%d",&n),n){
        int tmp,place[range],maximum=0,imax=-1,amax=-1;
        for(i=0;i<range;i++) place[i]=-1;
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            if(place[tmp]==-1) place[tmp]=i;
            else if(i-place[tmp]>maximum){
                maximum = i-place[tmp];
                imax=place[tmp];
                amax=tmp;
            }
        }
        if(imax==-1) printf("No solution\n");
        else printf("(%d,%d):%d\n",imax,imax+maximum,amax);
    }
    return 0;
}

