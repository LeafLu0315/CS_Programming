// vector::push_back
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;

// return true if p before q
bool cmp(LL p,LL q){
    return p>q ;
}
void sol() {
  vector<int> vec; // declare local, no need using .clear()
  int myint,j,k;

  for (int i=0;i<n;i++) {
    scanf("%d",&myint);
    vec.push_back (myint);
  }
  cout << "myvector stores " << int(vec.size()) << " numbers.\n";
  for (j=0;j<vec.size()-1;j++) // cannot use i, not declare
    printf("%d ",vec[j]);
  printf("%d\n",vec[j]); // using vector as array
  // c++ sort
  printf("Sorting\n");
  sort(vec.begin(),vec.end()); // range is [ x,y )
  for (j=0;j<vec.size()-1;j++) // cannot use i, not declare
    printf("%d ",vec[j]);
  printf("%d\n",vec[j]); // using vector as array
  LL arr[10];
  j=0;
  for (auto &p: vec) // for every element p in vector. note to use &p
    arr[j++]=p;
  sort(arr,arr+j,cmp); // soting using compare function
  for (int i=0;i<j;i++) printf("%lld%c",arr[i]," \n"[i==j-1]);

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
