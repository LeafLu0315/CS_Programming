#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,j,m,k,s;
    cin>>n;
    while(n--){
        cin>>j>>m;
        priority_queue<int> pq;
        while(m--) pq.push(0);
        while(j--){
            cin>>k;
            s = pq.top();
            pq.pop();
            pq.push(s-k);
        }
        while(!pq.empty()){
            k = pq.top();
            pq.pop();
        }
        cout<<0-k<<endl;
    }
    return 0;
}
