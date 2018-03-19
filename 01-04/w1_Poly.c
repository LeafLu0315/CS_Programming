#include<stdio.h>
int main(){
    int a,b,c;
    int ncase,exp,aim_exp;
    scanf("%d",&ncase);
    while(ncase--){
        int poly[20][40]={1};
        scanf("%d%d%d",&poly[1][2],&poly[1][1],&poly[1][0]);
        for(a=2;a<=10;a++)
            for(b=0;b<21;b++)
                for(c=0;c<3;c++)
                    poly[a][b+c]+=poly[1][c]*poly[a-1][b];
        scanf("%d",&exp);
        for(aim_exp=2*exp;aim_exp>=0;aim_exp--){
            printf("%d",poly[exp][aim_exp]);
            if(aim_exp) printf(" ");
        }
        if(ncase) printf("\n");
    }
    return 0;
}
