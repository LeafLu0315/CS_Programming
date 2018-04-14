#include<iostream>
#include<algorithm>
#define N 100
using namespace std;
void sol();
struct HW{
    int work;
    int deadline;
};
bool compare(HW,HW);
HW homework[2*N];
int main(){
    int n;
    cin>>n;
    while(n--) sol();
    return 0;
}

void sol(){
    int n,i,time=0,flag=1;
    cin>>n;
    for(i=0;i<n;i++) cin>>homework[i].work;
    for(i=0;i<n;i++) cin>>homework[i].deadline;
    sort(homework,homework+n,compare);
    for(i=0;i<n;i++){
        time+=homework[i].work;
        if(time>homework[i].deadline){
            flag=0;
            break;
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return ;
}

bool compare(HW a,HW b){
    if(a.deadline != b.deadline) return (a.deadline<b.deadline);
    return a.work<b.work;
}
