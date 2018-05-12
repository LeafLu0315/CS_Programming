#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 50
#define STRSZE 20
using namespace std;
struct TIME{
    int left,right;
};
bool cmp(TIME a,TIME b);
void sol();
char str[STRSZE];
int main(void){
    int n;
    scanf("%d",&n);
    getchar(); gets(str);
    while(n--) sol();
    return 0;
}

bool cmp(TIME a,TIME b){
    return a.left<b.left;
}

void sol(){
    TIME t[N];
    int n=0,sze=0,ans=0,right=-1;
    gets(str);
    while(str[0]!='\0'){
        int a,b;
        sscanf(str,"%d %d",&a,&b);
        t[sze].left=min(a,b);
        t[sze++].right=max(a,b);
        if(gets(str)==NULL) break;
    }
    sort(t,t+sze,cmp);
    while(n<200){
        for(int i=0;t[i].left<=n;i++) if(t[i].right>right) right = t[i].right;
        n = right + 1;
        ans++;
    }
    printf("%d\n",ans);
}
