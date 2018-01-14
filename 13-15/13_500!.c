#include<stdio.h>
int num[1001][3000];
int main(){
    int sch,a,b,k;
    num[1][1]=1;
    for(a=2;a<1001;a++)
        for(b=1;b<3000;b++){
            num[a][b]+=num[a-1][b]*a;
            if(num[a][b]>9){
                num[a][b+1]+=num[a][b]/10;
                num[a][b]%=10;
            }
        }
    while(scanf("%d",&sch)!=EOF){
        for(k=2999;num[sch][k]==0;) k--;
        printf("%d!\n",sch);
        for(;k;k--) printf("%d",num[sch][k]);
        printf("\n");
    }
    return 0;
}
