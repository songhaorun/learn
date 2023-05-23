#include <bits/stdc++.h>
using namespace std;
unsigned long long kuaisumi(unsigned long long a,unsigned long long n){
    if(n==1)
        return a;
	unsigned long long t=kuaisumi(a,n/2);
	return n&1?t*t*a:t*t;
}
int main(){
    unsigned long long x,n;
    cin>>x>>n;
    printf("%llu",kuaisumi(x+1,n));
    return 0;
}