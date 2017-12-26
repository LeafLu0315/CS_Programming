#include<stdio.h>
#include<string.h>
#define MAX 200
int main(){
    int n,m,i,j,a,b;
    char str[MAX][MAX],c,res[MAX];
    scanf("%d %d\n",&n,&m);
    for(i=0;i<n;i++) scanf("%s",str[i]);
    while(m--){
        scanf("%d%c%d",&a,&c,&b);
        switch(c){
        case '+':

            break;
        case '*':

            break;
        default:
            printf("ERROR OPERATOR\n");
        }
    }
    return 0;
}
