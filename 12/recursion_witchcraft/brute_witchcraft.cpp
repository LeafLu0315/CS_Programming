#include<cstdio>
bool sol();
int main(void){
    int n;
    bool able;
    scanf("%d",&n);
    while(n--){
        able = sol();
        printf("%s\n",able ? "yes":"no");
    }
    return 0;
}

bool sol(){
   int d,a,b,c,A,B,C,sum;
   scanf("%d%d%d%d%d%d%d",&d,&a,&b,&c,&A,&B,&C);
   if(!d) return true;
   for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) for(int k=0;k<=c;k++){
        sum = i * A + j * B + k * C;
        if(sum == d) return true;
   }
   return false;
}
