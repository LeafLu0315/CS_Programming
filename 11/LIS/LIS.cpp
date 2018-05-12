#include<cstdio>
#include<vector>
using namespace std;
void sol();
int main(void){
    int n;
    scanf("%d",&n);
    while(n--) sol();
    return 0;
}

void sol(){
    int n;
    vector<int> v;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        vector<int>::iterator vi = lower_bound(v.begin(),v.end(),tmp);
        if(vi == v.end()) v.push_back(tmp);
        else *vi = tmp;
    }
    printf("%d\n",v.size());
}
