#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int ncase;
    scanf("%d",&ncase);
    while(ncase--){
        int n;
        scanf("%d",&n);
        pair<int,int> p[n+5];
        for(int i=0;i<n;i++) scanf("%d",&p[i].second);
        for(int i=0;i<n;i++) scanf("%d",&p[i].first);
        sort(p,p+n);
        long long sum=0;
        bool yn=true;
        for(int i=0;i<n;i++){
            sum+=p[i].second;
            if(sum>p[i].first) yn=false;
        }
        if(yn) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
