#include<bits/stdc++.h>
using namespace std;
struct baby{
    int left,right;
};
baby a[100];
bool cmp(baby b1,baby b2){
    return b1.left<b2.left;
}

int main(void){
    char buffer[254];
    int T,i=0;
    scanf("%d",&T);
    getchar();
    gets(buffer);
    while(T--){
        i=0;
        gets(buffer);
        while(buffer[0]!=0){
            sscanf(buffer,"%d%d",&a[i].left,&a[i].right);
            if(a[i].left>a[i].right) swap(a[i].left,a[i].right);
            i++;
            if(gets(buffer) == NULL) break;
        }
        sort(a,a+i,cmp);
        int p1=0,maximum=-1,ans=0;
        i=0;
        while(p1<200){
            for(;a[i].left<=p1;i++) if(a[i].right>maximum) maximum=a[i].right;
            p1=maximum+1;
            ans++;
        }
        cout<<ans;
        if(T) cout<<endl;
    }
    return 0;
}
