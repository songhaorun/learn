#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int,bool> b;
    int n,a,mx=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a);
        mx=max(mx,a);
        if(!b[a]){
            ans+=5;
            b[a]=1;
        }
    }
    ans+=10*mx+n;
    printf("%d",ans);
    return 0;
}