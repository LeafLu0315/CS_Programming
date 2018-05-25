#include<cstdio>
int main(void){
    long long n,m;  // n = 10m + r -> n-m = 9m + r
    while(scanf("%lld",&n),n){
        int counter=0;
        for(int a=9;a>=0;a--) {
            if(!((n-a)%9)){
                m=(n-a)/9;
                if(counter++) printf(" ");
                printf("%lld",n+m);
            }
        }
        printf("\n");
    }
    return 0;
}
