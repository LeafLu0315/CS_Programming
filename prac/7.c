/*7. 簡單字典。
宣告 char word[64]; 來儲存輸入的
使用 scanf("%s", word) 來輸入一個英文字
使用 if(strcmp("apple", word)==0) 來判斷輸入的字是否是 "apple"
使用 while(1) {｝無窮迴圈反覆執行。
如果輸入的字程式裡沒有，則印出 "李公蝦毀？＂
可以參考第一節上課的範例程式來改。*/
#include<stdio.h>
#include<string.h>
void sol();
int main(){
    while(1) sol();
    return 0;
}

void sol(){
    char word[64];
    scanf("%s",word);
    if(!strcmp("apple",word)) printf("Is apple\n");
    else printf("李公蝦毀\n");
    return ;
}
