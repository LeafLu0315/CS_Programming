#include<stdio.h>

//define
#define N 64
typedef unsigned long long SET;
int Clique[N][N],ans,n;
SET ull;

//function
int inset(int,SET);
int set_size(SET);
void clique(SET,int);

int main(){
    int i,j;
    SET t;
    while(1){
        scanf("%d",&n);
        if(!n) break;
        for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&Clique[i][j]);
        t=ans=0;
        clique(t,0);
        printf("%d\n",ans);
    }
    return 0;
}

int inset(int i,SET s){
    if(s & (1uLL<<i)) return 1;
    return 0;
}

int set_size(SET s){
    int size=0,i;
    for(i=0;i<n;i++) if(inset(i,s)) size++;
    return size;
}

void clique(SET s,int num){
    SET tmp;
    int i,k;
    if(num==n) return ;
    k=set_size(s);
    for(i=0;i<num;i++) if(inset(i,s) && (Clique[i][num]==0)) break;
    if(i==num){
        tmp= s | ((1uLL)<<num);
        if((k=set_size(tmp))>ans){
            ans=k;
            ull=tmp;
        }
        clique(tmp,num+1);
    }
    tmp=s;
    clique(tmp,num+1);
    return ;
}
