#include <bits/stdc++.h>
using namespace std;
int x[51],y[51],r[51];
bool pd(int xx,int yy,int n){
    return (x[n]-xx)*(x[n]-xx)+(y[n]-yy)*(y[n]-yy)<r[n]*r[n];
}
int main(){
    int n,x1,y1,x2,y2,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&x[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&y[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&r[i]);
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    for(int i=1;i<=n;++i){
        bool b1=pd(x1,y1,i),b2=pd(x2,y2,i);
        if((b1 && !b2)||(b2 && !b1))
            ++ans;
    }
    printf("%d",ans);
    return 0;
}