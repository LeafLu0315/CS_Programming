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
int main(void){
    int n;
    char white[STRSZE];
    scanf("%d",&n);
    getchar(); gets(white);
    while(n--) sol();
    return 0;
}

bool cmp(TIME a,TIME b){
    return a.left<b.left;
}

void sol(){
    TIME t[N];
    int n,sze=0,a,b,ans,right;
    char str[STRSZE];
    gets(str);
    while(str[0]!='\0'){
        sscanf(str,"%d %d",&a,&b);
        t[sze].left=min(a,b);
        t[sze++].right=max(a,b);
        if(gets(str)==NULL) break;
    }
    sort(t,t+sze,cmp);
    ans = a = 0;
    right = -100;
    while(a<200){
        for(int i=0;t[i].left<=a;i++) if(t[i].right>right) right = t[i].right;
        a = right + 1;
        ans++;
    }
    printf("%d\n",ans);
}
