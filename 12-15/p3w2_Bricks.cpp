#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,t=1;
    while(scanf("%d",&n),n){
        int i,all=0;
        int num[n];
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
            all+=num[i];
        }
        int pin=all/n,sum=0;
        for(i=0;i<n;i++){
            if(num[i]>pin) sum+=num[i]-pin;
        }
        printf("Set #%d\n",t++);
        printf("The minimum number of moves is %d\n",sum);
    }
    return 0;
}
