// vector::push_back
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;

struct EDGE {
    LL v,w; //
    bool operator <(const EDGE &p) const {
        return w > (p.w);
    }
};

struct compare
 {
   bool operator()(const EDGE& p, const EDGE& q)
   {
       return p.v < q.v;
   }
 };

void sol() {
  vector<EDGE> vec; // declare local, no need using .clear()
  int myint,j,k,x,y;

  for (int i=0;i<n;i++) {
    x=rand()%10+1; y=rand()%10+1;
    vec.push_back ({x,y});
  }
  cout << "myvector stores " << int(vec.size()) << " numbers.\n";
  for (j=0;j<vec.size();j++) // cannot use i, not declare
    printf("(%lld,%lld) ",vec[j].v,vec[j].w);
  printf("\n"); // using vector as array
  // c++ sort
  priority_queue<EDGE> pq;
  for (j=0;j<vec.size();j++) pq.push(vec[j]);
  while (pq.size()) {
    EDGE p=pq.top();
    pq.pop();
    printf("(%lld,%lld) ",p.v,p.w);
  }
  printf("\n"); // using vector as array
  priority_queue<EDGE,vector<EDGE>,compare> pq2;
  for (auto &p:vec) pq2.push(p);
  EDGE p;
  while (pq2.size()) {
    p=pq2.top();
    pq2.pop();
    printf("(%lld,%lld) ",p.v,p.w);
  }
printf("\nLazy method\n");
    // compare first and then second
  priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>> > pq3;
  for (auto &p:vec) pq3.push({p.w,p.v});
  while (pq3.size()) {
    pair<LL,LL> p=pq3.top();
    pq3.pop();
    printf("(%lld,%lld) ",p.second,p.first);
  }
printf("\nVery Lazy method\n");
  priority_queue<pair<LL,LL>> pq4;
  for (auto &p:vec) pq4.push({-p.w,p.v});
  while (pq4.size()) {
    pair<LL,LL> p=pq4.top();
    pq4.pop();
    printf("(%lld,%lld) ",p.second,-p.first);
  }

  cout<<endl<<"End of demo\n";

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
