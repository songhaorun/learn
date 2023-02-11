#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ans1=0,ans2=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(i==j)
                ans1+=(n-i+1)*(m-j+1);
            else
                ans2+=(n-i+1)*(m-j+1);
    cout<<ans1<<" "<<ans2;
    return 0;
}