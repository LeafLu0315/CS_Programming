#include<iostream>
#include<cstdlib>
using namespace std;
int cmp(const void *a,const void b){
    return (*(long long int*)a-*(long long int*)b);
}

int main(){
    long long int n;
    cin>>n;
    while(n--){
        long long int N;
        cin>>N;
        long long int PTime[N];
        for(long long int i=0;i<N;i++) cin>>PTime[i];
        qsort(PTime,N,sizeof(long long int),cmp);
        long long int ans=0,j=1;
        for(int i=N-1;i>=0;i--){
            ans+=PTime[i]*j;
            j+=2;
        }
        cout<<ans<<endl;
    }

}
