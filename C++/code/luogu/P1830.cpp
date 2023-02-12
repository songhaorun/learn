#include<bits/stdc++.h>
using namespace std;
int ans[101][101][2];
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    for(int i=1;i<=x;++i){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1;j<=x2;++j)
            for(int k=y1;k<=y2;++k){
                ans[j][k][0]++;
                ans[j][k][1]=i;
            }
    }
    for(int i=1;i<=y;++i){
        int xx,yy;
        cin>>xx>>yy;
        if(ans[xx][yy][0])
            printf("Y %d %d\n",ans[xx][yy][0],ans[xx][yy][1]);
        else
            cout<<"N\n";
    }
    return 0;
}