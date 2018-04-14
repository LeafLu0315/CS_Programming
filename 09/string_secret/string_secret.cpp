#include<iostream>
#include<cstring>
#define N 1000
using namespace std;
char trans(char);
void sol();
char str[N];
int main(){
    while(gets(str)!=NULL) sol();
    return 0;
}

char trans(char c){
    if(c >= 'A' && c <= 'Z') return ('z'-c+'A');
    if(c >= 'a' && c <= 'z') return ('Z'-c+'a');
    if(c >= '0' && c <= '8') return c+1;
    if(c == '9') return '0';
    return c;
}

void sol(){
    int i;
    for(i=0;i<strlen(str);i++) str[i]=trans(str[i]);
    cout<<str<<endl;
    return ;
}
