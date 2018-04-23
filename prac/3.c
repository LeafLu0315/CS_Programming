/*
a. 輸入一個分數，如果大於或等於 60 印出 pass，否則印出 fail
b. 加上for 迴圈讓它反覆執行 5 次
c. 改用while(1) 無窮迴圈讓它無限次反覆執行
d. 加上判斷輸入值是否為負數，如果負數則離開迴圈
(使用 break)
*/
#include<stdio.h>
void sol();
void dsol(int);
int main(){
    int times=5,i;
    //for(i=0;i<times;i++) sol(); b
    //while(1) sol(); c
    //d
    int score;
    while(scanf("%d",&score)){
        if(score<0) break;
        dsol(score);
    }
    return 0;
}

void sol(){
    int score;
    scanf("%d",&score);
    if(score>=60) printf("Pass\n");
    else printf("Fail\n");
    return;
}

void dsol(int score){
    if(score>=60) printf("Pass\n");
    else printf("Fail\n");
    return;
}
