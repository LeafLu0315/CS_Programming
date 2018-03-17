#include<iostream>
#include<algorithm>
#include<cstring>
#define N 1000
#define STRMAX 10000
using namespace std;
void sol();
int main(){
    int times;
    scanf("%d\n",&times);
    while(times--) sol();
    return 0;
}

void sol(){
    int X[N],Y[N],index=0,i;
    char str[STRMAX],*tok;
    double total=0;
    gets(str);
    tok=strtok(str," \0");
    while(tok!=NULL){
        X[index++]=atoi(tok);
        tok=strtok(NULL," \0");
    }
    index=0;
    gets(str);
    tok=strtok(str," \0");
    while(tok!=NULL){
        Y[index++]=atoi(tok);
        tok=strtok(NULL," \0");
    }
    for(i=0;i<index;i++) X[i]=abs(X[i]);
    for(i=0;i<index;i++) Y[i]=-abs(Y[i]);
    sort(X,X+index);
    sort(Y,Y+index);
    for(i=0;i<index;i++) total+=sqrt(X[i]*X[i]+Y[i]*Y[i]);
    cout<<(int)total<<endl;
    return;
}
