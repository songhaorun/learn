#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m=0;
    double l=10;
    cin>>n;
    for(;n;--n){
        double x;
        int a;
        cin>>x>>a;
        if(l<=x)
            break;
        l=min(l-x,10.0);
        m+=a;
    }
    int a=floor(log2(m+1)),b;
    b=m-pow(2,a)+1;
    cout<<a<<" "<<b;
    return 0;
}