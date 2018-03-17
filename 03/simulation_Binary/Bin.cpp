#include<iostream>
#include<cstring>
#define N 32
using namespace std;
void add_to_arr(char [],int []);
void strrev(char []);
int arr_to_int(int []);

int main(){
    int counts,res[N],i;
    char bin[N];
    freopen("simulation_Binary.in","r",stdin);
    while(1){
        cin>>counts;
        if(!counts) break;
        for(i=0;i<N;i++) res[i]=0;
        while(counts--){
            cin>>bin;
            strrev(bin);
            add_to_arr(bin,res);
        }
        for(i=0;i<N;i++)
            if(res[i]>1){
                res[i+1]+=res[i]/2;
                res[i]%=2;
            }
        cout<<arr_to_int(res)<<endl;
    }
    return 0;
}

void strrev(char arr[]){
    int i,leng=strlen(arr);
    char tmp;
    for(i=0;i<leng/2;i++){
        tmp=arr[i];
        arr[i]=arr[leng-i-1];
        arr[leng-i-1]=tmp;
    }
    return;
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
