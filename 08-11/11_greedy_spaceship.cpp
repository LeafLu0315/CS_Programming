#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    while(scanf("%d",&n)){
        if(n==0) break;
        int tem1=1000,tem2=1000,ene1=0,ene2=0;
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            int tmp=min(ene1+abs(tem1-a),ene2+abs(tem2-a));
            ene2=min(ene1+abs(tem1-b),ene2+abs(tem2-b));
            ene1=tmp;
            tem1=a;
            tem2=b;
        }
        printf("%d\n",min(ene1,ene2));
    }
    return 0;
}
