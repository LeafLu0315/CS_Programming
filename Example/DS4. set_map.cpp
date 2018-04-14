// map
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;

struct FRAC {
    int x,y; // x/y
    bool operator <(const FRAC &p) const {
        return x*(p.y) < y*(p.x);
    }
};

// return true if p before q
bool cmp(FRAC p,FRAC q){
    return p.x*q.y > q.x*p.y ;
}
void sol() {
  map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( pair<char,int>('a',100) );
  mymap.insert ( pair<char,int>('z',200) );

  pair<map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( pair<char,int>('z',500) );
  if (ret.second==false) {
    cout << "element 'z' already existed";
    cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
  cout<<" can also modify and insert by [ ]"<<endl;
  mymap['p']=123;
  mymap['c']=432;
  for (auto &p:mymap)
    cout << p.first << " => " << p.second << '\n';

  cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    cout << it->first << " => " << it->second << '\n';

  return;
}

void sol2() {
    map<FRAC,int> mymap;
    int x,y,w;
    for (int i=0;i<n;i++) {
        x=rand()%10+1;
        y=rand()%10+1;
        w=rand()%10+1;
        mymap.insert({{x,y},w});
    }
  for (auto it=mymap.begin(); it!=mymap.end(); ++it)
    printf("( %d/%d, %d) ",it->first.x,it->first.y,it->second);
  cout<<endl;
  for (auto &p:mymap) {
    printf("( %d/%d, %d) ",p.first.x,p.first.y,p.second);
  }
  while (1) {
    cout<<"\nWhat to search? (x/y)";    cin>>x>>y;
    if (x==0 && y==0) break;
    auto it=mymap.lower_bound({x,y}),it2=mymap.upper_bound({x,y});
    printf("lower_bound: ( %d/%d, %d)\n",it->first.x,it->first.y,it->second);
    printf("upper_bound: ( %d/%d, %d)\n",it2->first.x,it2->first.y,it2->second);
  }
  while (1) {
    cout<<"\nTry insertion and modification. Enter key x and y and w:";
    cin>>x>>y>>w;
    if (x==0 && y==0) break;
    mymap[{x,y}]=w;
    for (auto &p:mymap) {
      printf("( %d/%d, %d) ",p.first.x,p.first.y,p.second);
    }
  }

  return ;
}

int main ()
{
    sol();
    while (1) {
        cout << "Please enter how many numbers to be input (enter 0 to end):\n";
        cin>>n;
        if (n==0) break;
        sol2();
    }
    return 0;
}
