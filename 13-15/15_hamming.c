#include<stdio.h>
#include<string.h>
#define N 1010

int ham(int s,int h){
    int x=s^h,d=0;
    while(x){
        if(x&1) d++;
        x>>=1;
    }
    return d;
}

int main(){
    int t,i,j,k=0,f,mal,n,l;
    int q[N];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++) scanf("%d",q+j);
        mal=0;
        for(j=0;j<n;j++) for(l=j+1;l<n;l++)
            if((f=ham(q[j],q[l]))>mal) mal=f;
        printf("%d\n",mal);
    }
    return 0;
}
