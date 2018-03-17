#include<iostream>
#define N 10000
using namespace std;
void calc(int [],int [],int);
int main(){
    int n,i;
    int soldier[N],enemy[N];
    while(1){
        cin>>n;
        if(!n) break;
        for(i=0;i<n;i++) cin>>enemy[i];
        for(i=0;i<n;i++) cin>>soldier[i];
        calc(soldier,enemy,n);
    }
    return 0;
}

void calc(int soldier[],int enemy[],int quantity){
    int win=0,i,maxs,maxe,loop=quantity,spos=0,epos=0;
    int enemy_encounter[quantity],soldier_fight[quantity];
    for(i=0;i<quantity;i++) enemy_encounter[i]=soldier_fight[i]=1;
    while(loop--){
        maxs=0;maxe=0;
        for(i=0;i<quantity;i++){
            if(soldier[i]>maxs && soldier_fight[i]){
                maxs=soldier[i];
                spos=i;
            }
            if(enemy[i]>maxe && enemy_encounter[i]){
                maxe=enemy[i];
                epos=i;
            }
        }
        if(maxs>maxe){
            win++;
            soldier[spos]=0;
        }
        enemy_encounter[epos]=0;
    }
    cout<<win<<endl;
    return ;
}
