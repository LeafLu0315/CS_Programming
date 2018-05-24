#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
int main(void){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,*F=(int*)malloc(sizeof(int)*150000);
        scanf("%d",&n);
        int cnt=1,cnt1=1,l1,l2;
        for(int i=0;i<n;i++){
            int tmp,j;
            scanf("%d",&tmp);
            if(i==0) F[cnt++]=tmp;
            for(j=1;j<cnt;j++) if(tmp<=F[j]) break;
            F[j]=tmp;
            if(j==cnt) cnt++;
        }
        printf("%d\n",cnt-1);
    }
    return 0;
}
