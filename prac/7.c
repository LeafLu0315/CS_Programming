/*7. ČdTB
é char word[64]; Ņ×¶AüI
gp scanf("%s", word) ŅAüźĀp¶
gp if(strcmp("apple", word)==0) Ņ»ŠAüI„Ū„ "apple"
gp while(1) {p³ē½¢·sB
@ŹAüIö®”LC„óo "öŚŹHśW
ĀČŅlęźßćŪIĶįö®ŅüB*/
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
    else printf("öŚŹ\n");
    return ;
}
