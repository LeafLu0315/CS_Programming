#include<stdio.h>
#include<string.h>

int main(){
    char set[100][1000],sign;
    int copyset[100][60]={0},num1,num2,i,j,n,m,ans[60],ok;
    scanf("%d%d\n",&n,&m);
    for(i=0;i<n;i++){
        gets(set[i]);
        for(j=0;j<strlen(set[i]);j++) copyset[i][set[i][j]-65]=1;
    }
    while(m--){
        scanf("%d %c %d",&num1,&sign,&num2);
        for(i=0;i<58;i++)
            if(sign=='*') ans[i]=(copyset[num1][i]&&copyset[num2][i]);
            else ans[i]=(copyset[num1][i] || copyset[num2][i]);
        ok=0;
        for(i=0;i<58;i++)
            if(ans[i]==1){
                printf("%c",i+65);
                ok=1;
            }
        if(!ok) printf("-1");
        puts("");
    }
    return 0;
}
