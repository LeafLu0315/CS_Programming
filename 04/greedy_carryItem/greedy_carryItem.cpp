#include<iostream>
#include<algorithm>
#define MAX 10000
using namespace std;
void sol();
int main(){
    int times;
    cin>>times;
    while(times--) sol();
    return 0;
}

void sol(){
    int items,students,paid=0,i,j,t=0;
    int wei[MAX],power[MAX];
    cin>>items>>students;
    for(i=0;i<items;i++) cin>>wei[i];
    for(i=0;i<students;i++) cin>>power[i];
    if(items>students) {cout<<-1<<endl; return;}
    sort(wei,wei+items);
    sort(power,power+students);
    for(i=0,j=0;i<students,j<items;i++) if(power[i]>=wei[j]){ paid+=power[i]; j++;}
    if(j != items) cout<<-1<<endl;
    else cout<<paid<<endl;
    return;
}
