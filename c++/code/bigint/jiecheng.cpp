#include<bits/stdc++.h>
#include"bigint.h"
using namespace std;
bigint jiecheng(bigint n){
    if(n==1)
        return 1;
    return jiecheng(n-1)*n;
}
int main(){
    bigint n,ans;
    cin>>n;
    ans=jiecheng(n);
    cout<<ans;
    return 0;
}