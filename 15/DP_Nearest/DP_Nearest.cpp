#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
typedef pair<int,int> PII;
void sol(int);
bool cmp(PII,PII);
PII p[N];
int main(void){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}
/*
first is position
second is value
*/
void sol(int n){
    for(int i=0;i<n;i++){
        p[i].first = i;
        scanf("%d",&p[i].second);
    }
    sort(p,p+n,cmp);
    int near=N,pos1=p[0].second,pos2,val;
    for(int i=0;i<n-1;i++){
        if(p[i+1].first-p[i].first==near && pos1<p[i].first) continue;
        if(p[i].second == p[i+1].second && p[i+1].first-p[i].first<=near){
            near = p[i+1].first-p[i].first;
            pos1 = p[i].first;
            pos2 = p[i+1].first;
            val = p[i].second;
        }
    }
    if(near == N) printf("No solution\n");
    else printf("(%d,%d):%d\n",pos1,pos2,val);
    return;
}

bool cmp(PII a,PII b){
    if(a.second != b.second) return a.second<b.second;
    return a.first<b.first;
}
