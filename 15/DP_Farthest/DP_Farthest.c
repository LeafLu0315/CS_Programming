#include<stdio.h>
#define N 2010
void sol(int);
int mark[N];
int main(void){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}

void sol(int n){
    int i,pos1,pos2,val,far=0,tmp;
    for(i=0;i<N;i++) mark[i]=-1;
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        if(mark[tmp]==-1) mark[tmp]=i;
        else if(i-mark[tmp]>far){
            far = i-mark[tmp];
            pos1 = mark[tmp];
            pos2 = i;
            val = tmp;
        }
    }
    if(!far) printf("No solution\n");
    else printf("(%d,%d):%d\n",pos1,pos2,val);
}
