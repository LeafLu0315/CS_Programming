#include<stdio.h>
#include<stdlib.h>
int main(){
    int ncase,np,i,j;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&np);
        int X[np],Y[np];
        int max=0;
        for(i=0;i<np;i++) scanf("%d%d",&X[i],&Y[i]);
        for(i=0;i<np;i++) for(j=i+1;j<np;j++)
            if(abs(X[j]-X[i])*abs(Y[j]-Y[i])>max) max=abs(X[j]-X[i])*abs(Y[j]-Y[i]);
        printf("%d\n",max);
    }
    return 0;
}
