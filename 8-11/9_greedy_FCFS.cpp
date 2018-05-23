#include<bits/stdc++.h>
using namespace std;
int mac[100010];
int contime(int n,int m){
    priority_queue<int> pq;
    int i,s;
    for(i=0;i<m;i++) pq.push(0);
    for(i=0;i<n;i++){
        s=pq.top()-mac[i];
        pq.pop();
        pq.push(s);
    }
    for(i=0;i<m-1;i++) pq.pop();
    s=-pq.top();
    pq.pop();
    return s;
}

int main(void){
    int sum,t,i,j,k,n,m,s,down,up,all;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=s=sum=0;i<n;i++){
            cin>>mac[i];
            sum+=mac[i];
            if(mac[i]>s) s=mac[i];
        }
        if(m<s){
            printf("-1\n");
            continue;
        }
        down=sum/m;
        up=n;
        while(down<up){
            s=(up+down)/2;
            k=contime(n,s);
            if(k<=m) up=s;
            else down=s+1;
        }
        printf("%d\n",up);
    }
    return 0;
}
