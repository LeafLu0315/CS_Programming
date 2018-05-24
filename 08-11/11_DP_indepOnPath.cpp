#include<bits/stdc++.h>
using namespace std;
int main(void){
    int num,max1,max2,t1,t2,k;
    while(1){
        cin>>num;
        if(num==0) break;
        max1=max2=t1=t2=0;
        for(int i=0;i<num;i++){
            cin>>k;
            t1=k+max2;
            t2=(max1>max2)?max1:max2;
            max1=t1;
            max2=t2;
        }
        cout<<((max1>max2)?max1:max2)<<endl;
    }
    return 0;
}
