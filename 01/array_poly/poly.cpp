#include<iostream>
#define SIZE 1025
using namespace std;
int mult(int [],int [],int);
int main(){
    int base[3],res[SIZE],d,n,i,highest;
    cin>>n;
    while(n--){
        for(i=2;i>=0;i--){
            cin>>base[i];
            res[i]=base[i];
        }
        cin>>d;
        highest=3;
        while(--d) highest=mult(base,res,highest);
        for(i=highest-1;i>0;i--) cout<<res[i]<<" ";
        cout<<res[i]<<endl;
    }
    return 0;
}

int mult(int base[], int res[], int highest){
    int tmp[SIZE]={0},i,j;
    for(i=0;i<3;i++) for(j=0;j<highest;j++) tmp[i+j]+=base[i]*res[j];
    for(i=0;i<SIZE;i++) res[i]=tmp[i];
    return highest+2;
}
