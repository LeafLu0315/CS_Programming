#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char findnum[3],sch[10];
    int i,ans,l=0;
    while(cin>>findnum>>sch){
        if(l++) cout<<"\n";
        ans=0;
        for(i=0;i<strlen(sch);i++) if(!strncmp(findnum,sch+i,strlen(findnum))) ans++;
        cout<<ans;
    }
    return 0;
}
