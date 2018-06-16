#include<stdio.h>
#define N 2010
#define M 1000010
void sol(int);
int mark[N];
int main(void){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}

void sol(int n){
    int i,pos1,pos2,val=0,near=M,tmp,previous;
    for(i=0;i<N;i++) mark[i]=-1;
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        if(mark[tmp]==-1) mark[tmp]=i;
        else{
            previous = mark[tmp];
            mark[tmp]=i;
            if(i-previous<near){
                near = i-previous;
                pos1 = previous;
                pos2 = i;
                val = tmp;
            }
        }
    }
    if(near == M) printf("No solution\n");
    else printf("(%d,%d):%d\n",pos1,pos2,val);
}
