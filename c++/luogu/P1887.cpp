#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int t1=n/m,t2=n%m;
    for(int i=1;i<=m-t2;++i)
        cout<<t1<<" ";
    for(int i=1;i<=t2;++i)
        cout<<t1+1<<" ";
    return 0;
}