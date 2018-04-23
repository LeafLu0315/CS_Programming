/*5. —A“ü™_ŒÂ®ÉC—Ao‘¼˜ì‰ÁŒ¸˜©œ“IŒ‹‰Ê
—á”@F—A“ü 6 5
—Ao
6 + 5 == 11
6 - 5 == 1
6 * 5 == 30
6 / 5 == 1
*/
#include<stdio.h>
void sol();
int main(){
    sol();
    return 0;
}

void sol(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d + %d = %d\n",a,b,a+b);
    printf("%d - %d = %d\n",a,b,a-b);
    printf("%d * %d = %d\n",a,b,a*b);
    printf("%d / %d = %d\n",a,b,a/b);
    return;
}
