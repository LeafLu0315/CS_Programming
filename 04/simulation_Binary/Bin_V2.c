#include<stdio.h>
#include<string.h>
#define N 32
void add_to_arr(char [],int []);
int arr_to_int(int []);
int main(){
    int count,res[N],i;
    char bin[N];
    freopen("simulation_Binary.in","r",stdin);
    while(1){
        scanf("%d",&count);
        if(!count) break;
        for(i=0;i<N;i++) res[i]=0;
        while(count--){
            scanf("%s",bin);
            strrev(bin);
            add_to_arr(bin,res);
        }
        for(i=0;i<N;i++)
            if(res[i]>1){
                res[i+1]+=res[i]/2;
                res[i]%=2;
            }
        printf("%d\n",arr_to_int(res));
    }
    return 0;
}

void add_to_arr(char bin[], int res[]){
    int i;
    for(i=0;i<strlen(bin);i++) res[i]+=bin[i]-'0';
    return;
}

int arr_to_int(int res[]){
    int i,b=1,ans=0;
    for(i=0;i<N;i++){
        if(res[i] & 1) ans+=b;
        b*=2;
    }
    return ans;
}
