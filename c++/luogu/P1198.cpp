#include<bits/stdc++.h>
using namespace std;
long long D,t=0;
vector<long long> a;
int main(){
    long long m,n;
    char c;
    cin>>m>>D;
    for(;m>0;--m){
        cin>>c>>n;
        if(c=='A'){
            a.push_back((n+t)%D);
            for(int i=a.size()-1;i>0;i--){
                if(a[i-1]>=a[i])
                    break;
                a[i-1]=a[i];
            }
        }
        else{
            t=a[a.size()-n];
            printf("%lld\n",t);
        }
    }
    return 0;
}