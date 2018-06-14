#include<stdio.h>

int main(void){
    int n,a,b,c,A,B,C,D;
    int i,j,k,check;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d%d%d%d",&D,&a,&b,&c,&A,&B,&C);
        check=0;
        for(i=a;i>=0&&check==0;i--)
            for(j=b;j>=0&&check==0;j--)
                for(k=c;k>=0&&check==0;k--)
                    if(A*i+B*j+C*k==D){
                        printf("yes\n");
                        check=1;
                    }
        if(check==0) printf("no\n");
    }
    return 0;
}
