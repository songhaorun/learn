#include<bits/stdc++.h>
using namespace std;
int main(){
    int h1,h2,m1,m2,t1,t2,n;
    scanf("%d:%d:%d",&h1,&m1,&t1);
    scanf("%d:%d:%d",&h2,&m2,&t2);
    scanf("%d",&n);
    long long ans=(long long)((h2-h1)*3600+(m2-m1)*60+t2-t1)*n;
    printf("%lld",ans);
    return 0;
}