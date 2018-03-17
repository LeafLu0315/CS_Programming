#include<iostream>
#define MAX 50
using namespace std;
int absolute(int);
int main(){
    int times,n,i,j,len,wid;
    int arr[MAX][2],maximum;
    cin>>times;
    while(times--){
        cin>>n;
        maximum=0;
        for(i=0;i<n;i++) for(j=0;j<2;j++) cin>>arr[i][j];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                len=absolute(arr[j][0]-arr[i][0]);
                wid=absolute(arr[j][1]-arr[i][1]);
                if(len*wid>maximum) maximum=len*wid;
            }
        }
        cout<<maximum<<endl;
    }
    return 0;
}

int absolute(int a){
    if(a>0) return a;
    return -a;
}

