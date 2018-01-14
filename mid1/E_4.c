#include<stdio.h>
int absolute(int,int);

int main(){
    int input;
//    freopen("D_4.txt","r",stdin);
    while(scanf("%d",&input)!=EOF){
        int temp=0,odd=0,even=0;
        while(input){
            if(temp%2) odd+=input%10;
            else even+=input%10;
            temp++;
            input/=10;
        }
        printf("%d\n",absolute(odd,even));
    }
    return 0;
}

int absolute(int a,int b){
    if(a-b>0) return a-b;
    return b-a;
}
