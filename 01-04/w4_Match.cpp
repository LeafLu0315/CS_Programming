#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int ncase;
    scanf("%d ",&ncase);
    for(int i=0;i<ncase;i++){
        char x[8000],y[8000];
        int n=0,absnum;
        double sum=0;
        vector<int> X,Y;
        cin.getline(x,8000);
        char *xtest=strtok(x," ");
        while(xtest != NULL){
            absnum=atoi(xtest)>0 ? atoi(xtest):atoi(xtest)*(-1);
            X.push_back(absnum);
            xtest=strtok(NULL," ");
            n++;
        }
        cin.getline(y,8000);
        char *ytest=strtok(y," ");
        while(ytest!=NULL){
            absnum=atoi(ytest)>0?atoi(ytest):atoi(ytest)*-1;
            Y.push_back(absnum);
            ytest=strtok(NULL," ");
        }
        sort(X.begin(),X.end());
        sort(Y.rbegin(),Y.rend());
        for(int j=0;j<n;j++) sum+=sqrt(X[j]*X[j]+Y[j]*Y[j]);
        cout<<(int)sum<<endl;
    }
    return 0;
}
