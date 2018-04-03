#include<iostream>
#include<cstring>
using namespace std;
int contains(char [],char);
void BigAdd(char [],int [],int);
void StrRev(char []);
int main(int argc,char *argv[]){
    int i,flag=0;
    for(i=1;i<argc;i++){
        if(contains(argv[i],'.')) flag=1;   //when it contains float number
        if(strlen(argv[i])>=20) flag=2;     //adding big number if the digits are more than 19
    }
    if(flag == 0){
        long long sum=0;
        for(i=1;i<argc;i++) sum+=atoll(argv[i]);    //convert string to long long
        cout<<sum<<endl;
    }
    if(flag == 1){
        double s=0;
        for(i=1;i<argc;i++) s+=atof(argv[i]);       //convert string to double
        cout<<s<<endl;
    }
    if(flag == 2){
        int pos=0,msize=1000;       //initialize the big number are at most 1000 digits
        int ans[msize];
        memset(ans,0,sizeof(ans));
        for(i=1;i<argc;i++) BigAdd(argv[i],ans,msize);
        for(i=msize-1;i>=0;i--)     //find the non-zero position
            if(ans[i]>0){
                pos=i;
                break;
            }
        for(i=pos;i>=0;i--) cout<<ans[i];   //print out the number
        cout<<endl;
    }
    return 0;
}

int contains(char str[],char c){
    for(int i=0;i<strlen(str);i++) if(str[i] == c) return 1;    //if the string contains a specific character
    return 0;
}

void BigAdd(char str[],int ans[],int msize){
    StrRev(str);    //string reverse
    for(int i=0;i<strlen(str);i++) ans[i]+=str[i]-'0';
    for(int i=0;i<msize;i++){
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    return ;
}

void StrRev(char str[]){    //string reverse
    char c;
    int i,len=strlen(str);
    for(i=0;i<len/2;i++){
        c=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=c;
    }
    return ;
}
