#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[500010];

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}

int main(void){
    int T;
    freopen("greedy_lineSegment.in","r",stdin);
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&a[i].first,&a[i].second);
        sort(a,a+n,cmp);
        int l=a[0].first,r=a[0].second;
        int rang=r-1;
        for(int i=1;i<n;i++){
            if((a[i].first>r)&&(a[i].second>r)) rang+=(a[i].second-a[i].first);
            if((a[i].first<=r)&&(a[i].second>r)){
                rang+=a[i].second-r;
                r=a[i].second;
            }
        }
        cout<<rang<<endl;
    }
    return 0;
}
