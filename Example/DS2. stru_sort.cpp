// sort struct
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;

struct FRAC {
    LL x,y; // x/y
    bool operator <(FRAC &p) {
        return x*(p.y) < y*(p.x);
    }
};

// return true if p before q
bool cmp(FRAC p,FRAC q){
    return p.x*q.y > q.x*p.y ;
}
void sol() {
  vector<FRAC> vec; // declare local, no need using .clear()
  int myint,j,k,x,y;

  for (int i=0;i<n;i++) {
    x=rand()%10+1; y=rand()%10+1;
    vec.push_back ({x,y});
  }
  cout << "myvector stores " << int(vec.size()) << " numbers.\n";
  for (j=0;j<vec.size();j++) // cannot use i, not declare
    printf("%lld/%lld ",vec[j].x,vec[j].y);
  printf("\n"); // using vector as array
  // c++ sort
  printf("Sorting\n");
  sort(vec.begin(),vec.end()); // range is [ x,y )
  for (j=0;j<vec.size();j++) // cannot use i, not declare
    printf("%lld/%lld ",vec[j].x,vec[j].y);
  printf("\nDecreasing\n"); // using vector as array
  sort(vec.begin(),vec.end(),cmp); // soting using compare function
  for (int i=0;i<vec.size();i++)
    printf("%lld/%lld%c",vec[i].x,vec[i].y," \n"[i==j-1]);

  cout<<"\nbinary search, current data is:"<<endl;
  int arr[10];
  j=0;
  for (auto &p:vec) arr[j++]=p.x;
  sort(arr,arr+j);
  for (int i=0;i<j;i++)
    printf("%d%c",arr[i]," \n"[i==j-1]);
  while (1) {
    cout<<"what to search (-1 for quit):";
    cin>>x;
    if (x==-1) break;
    int *p,*q;
    p=lower_bound(arr,arr+j,x);
    q=upper_bound(arr,arr+j,x);
    printf("Lower_bound: arr[%d]=%d\n",p-arr,*p);
    printf("Upper_bound: arr[%d]=%d\n",q-arr,*q);
  }


  cout<<"End of demo\n";

  return;
}


int main ()
{
    while (1) {
        cout << "Please enter how many numbers to be input (enter 0 to end):\n";
        cin>>n;
        if (n==0) break;
        sol();
    }
    return 0;
}
