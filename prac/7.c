/*7. �Țd���T�B
�鍐 char word[64]; �Җב��A���I
�g�p scanf("%s", word) �җA����p����
�g�p if(strcmp("apple", word)==0) �Ҕ��ЗA���I�����ې� "apple"
�g�p while(1) {�p����珚��������s�B
�@�ʗA���I�����������L�C����o "�����ښʁH�W
�șҍl���ߏ�ۓI�͗�����҉��B*/
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
    else printf("�����ښ�\n");
    return ;
}
