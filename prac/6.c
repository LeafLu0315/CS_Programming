/*6. �A������ɁC�A�o�����ۈו����ɁC
������ɐ��������ɓI���� ��@ 36 , 49, 64, ...*/
#include<stdio.h>
int sol();
int main(){
    if(sol()) printf("Yes\n");
    else printf("No");
    return 0;
}

int sol(){
    int a,i;
    scanf("%d",&a);
    for(i=1;i*i<=a;i++)
        if(i*i == a) return 1;
    return 0;
}
