#include<iostream>
#define MAXLENG 1000100
int duplicate[MAXLENG];
using namespace std;
int main(){
    int p,q,i,counter;
    while(1){
        cin>>p>>q;
        if(!q) break;
        counter=0;
        for(i=0;i<MAXLENG;i++) duplicate[i]=0;
        for(i=1;;i++){
            if(duplicate[p]){
                counter=i-duplicate[p];
                break;
            }
            duplicate[p]=i;
            p=(p*10)%q;
        }
        cout<<counter<<endl;
    }
    return 0;
}
