#include<cstdio>
#include<cstdlib>
#define INIT 1000
void sol(int);
int ABS(int);
int mini(int,int);
int main(){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}

void sol(int n){
    int *k1 = (int*) malloc(sizeof(int)*n);
    int *k2 = (int*) malloc(sizeof(int)*n);
    int a,b,c,d;
    for(int i=0;i<n;i++) scanf("%d %d",&k1[i],&k2[i]);
    int min1=ABS(k1[0]-INIT),min2=ABS(k2[0]-INIT);
    for(int i=1;i<n;i++){
        a = min1 + ABS(k1[i]-k1[i-1]);
        b = min2 + ABS(k1[i]-k2[i-1]);
        c = min1 + ABS(k2[i]-k1[i-1]);
        d = min2 + ABS(k2[i]-k2[i-1]);
        min1 = mini(a,b);
        min2 = mini(c,d);
    }
    printf("%d\n",mini(min1,min2));
    free(k1);
    free(k2);
}

int ABS(int a){
    if(a<0) return -a;
    return a;
}

int mini(int a,int b){
    return (a<b)? a:b;
}
