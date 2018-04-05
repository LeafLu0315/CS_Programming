#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct EMAIL{
    char usrname[100],domain[100];
};
int judge(char []);
int illegal(char []);
void TLow(char []);
int main(){
    int n,act;
    char email[100];
    cin>>n;
    while(n--){
        gets(email);
        act=judge(email);
        cout<<email;
        if(!act) cout<<"OK!"<<endl;
        else{
            cout<<"INVAILD EMAIL :";
            switch(act){
                case 1:
                    cout<<" MISSING \'@\' !"<<endl;
                    break;
                case 2:
                    cout<<" MISSING \'.\' !"<<endl;
                    break;
                case 3:
                    cout<<" DUPLICATE \'@\' !"<<endl;
                    break;
                case 4:
                    cout<<" TWO DOTS ARE NEARBY !"<<endl;
                    break;
                case 5:
                    cout<<" USERNAME IS EMPTY !"<<endl;
                    break;
                case 6:
                    cout<<" DOMAIN IS EMPTY !"<<endl;
                    break;
                case 7:
                    cout<<" BEHIND THE DOT NEEDS A NAME !"<<endl;
                    break;
                case 8:
                    cout<<" USERNAME CONTAINS ILLEGAL CHARACTER !"<<endl;
                    break;
                case 9:
                    cout<<" DOMAIN CONTAINS ILLEGAL CHARACTER !"<<endl;
                    break;
            }
        }
    }
    return 0;
}

int judge(char email[]){
    /* Judge if Email has no @ or . or duplicate @ or . nearby*/
    if(!strstr(email,"@")) return 1;    //NO @
    if(!strstr(email,".")) return 2;    //NO .
    int leng=strlen(email),i,counter=0,atpos,dindex=0;
    int dotpos[10]={0};
    for(i=0;i<leng;i++) {
        if(email[i] == '@'){
            counter++;
            if(counter == 1) atpos=i;
        }
        if(counter>1) return 3; //DUPLICATE @
        if(email[i] == '.') dotpos[dindex++]=i;
    }
    for(i=0;i<dindex;i++) if(dotpos[i+1]=dotpos[i]+1 && dindex>1) return 4; //TWO DOTS BEHIND
    /* Judge Email*/
    EMAIL E;
    memset(E.usrname,'\0',sizeof(E.usrname));   //INITIALIZE
    memset(E.domain,'\0',sizeof(E.domain));     //INITIALIZE
    strncpy(E.usrname,email,atpos);     //GET USERNAME
    int ulen=strlen(E.usrname),dlen;
    if(ulen == 0) return 5;     //EMPTY USRNAME
    for(i=atpos+1,dlen=0;i<leng;i++) E.domain[dlen++]=email[i]; //GET DOMAIN
    TLow(E.domain);
    if(!(E.domain[0]>='a'&&E.domain[0]<='z')) return 6;     //EMPTY DOMAIN
    memset(dotpos,0,sizeof(dotpos)); counter=0; //INITIALIZE
    for(i=0;i<strlen(E.domain);i++) if(E.domain[i]=='.') dotpos[counter++]=i;
    for(i=0;i<counter;i++) if(!isalpha(E.domain[dotpos[i]+1])) return 7;    //NO WORD BEHIND DOTS
    if(illegal(E.usrname)) return 8;
    if(illegal(E.domain)) return 9;
    return 0;
}

void TLow(char c[]){
    for(int i=0;i<strlen(c);i++) if(c[i]>='A'&&c[i]<='Z') c[i]=c[i]-'A'+'a';
    return ;
}

int illegal(char s[]){
    string str="a-zA-Z0-9_";

}
