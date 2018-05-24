#include<algorithm>
#include<cstdio>
#define N 50000
struct LINE{
    int left,right;
};
bool cmp(LINE,LINE);
void sol();
int main(){
    int n;
    scanf("%d\n",&n);
    while(n--) sol();
    return 0;
}

bool cmp(LINE p,LINE q){
    return p.left < q.left;
}

void sol(){
    char str[N];
    int n,x,y,ans=0;
    LINE l[N];
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        l[i].left = (a<b) ? a:b;
        l[i].right = (a>b) ? a:b;
    }
    std::sort(l,l+n,cmp);
    x = l[0].left;
    y = l[0].right;
    for(int i=1;i<n;i++){
        if(l[i].left > y){
            ans += y - x;
            x = l[i].left;
            y = l[i].right;
        }
        else if(l[i].right > y) y = l[i].right;
    }
    ans += y - x;
    printf("%d\n",ans);
    return;
}
