#include<cstdio>
#define N 10000
using namespace std;
void sol();
int t[N];
bool flag[N];
int main(){
    int n;
    scanf("%d",&n);
    while(n--) sol();
    return 0;
}

void sol(){
    int spies,i,mini=0;
    scanf("%d",&spies);
    for(i=1;i<spies;i++) scanf("%d",&t[i]);
    for(i=0;i<spies;i++) flag[i]=false;
    for(i=spies-1;i>0;i--){
        if(!flag[i]) flag[t[i]]=true;
        else mini++;
    }
    if(flag[0]) mini++;
    printf("%d\n",mini);
    return;
}
