#include<iostream>
#include<queue>
using namespace std;
void sol();
int main(){
    int n;
    cin>>n;
    while(n--) sol();
    return 0;
}

void sol(){
    int time,machine,i,t,s;
    priority_queue<int> pq;
    cin>>time>>machine;
    for(i=0;i<machine;i++) pq.push(0);
    for(i=0;i<time;i++){
        cin>>t;
        s=pq.top();
        pq.pop();
        pq.push(s-t);
    }
    for(i=0;i<machine-1;i++) pq.pop();
    cout<<-pq.top()<<endl;
    pq.pop();
    return ;
}
