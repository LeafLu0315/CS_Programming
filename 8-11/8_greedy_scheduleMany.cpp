#include<bits/stdc++.h>
using namespace std;

int main(void){
    int i,ncase,job,machine,consume,maximum;
    priority_queue<int> pq;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d%d",&job,&machine);
        for(i=0;i<machine;i++) pq.push(0);
        while(job--){
            scanf("%d",&consume);
            maximum = pq.top();
            pq.pop();
            pq.push(maximum-consume);
        }
        for(i=0;i<machine-1;i++) pq.pop();
        printf("%d\n",-pq.top());
        pq.pop();
    }
    return 0;
}
