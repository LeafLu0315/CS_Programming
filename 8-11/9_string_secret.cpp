#include<cstdio>
#include<cctype>

int main(void){
    int c0;
    c0 = getchar();
    while(c0 != EOF){
        if(c0 >= 'a' && c0 <= 'z') c0 = toupper('a'+'z'-c0);
        else if(c0 >= 'A' && c0 <= 'Z') c0 = tolower('A'+'Z'-c0);
        else if(c0 >= '0' && c0 <= '8') c0++;
        else if(c0 == '9') c0 = '0';
        printf("%c",c0);
        c0 = getchar();
    }
    return 0;
}
