#include<bits/stdc++.h>
using namespace std;
int n,m,c,f,vc,vf;
int you[1001][1001],xia[1001][1001];
long long sumyou[1001][1001],sumxia[1001][1001];
char a[1001][1001];
void init(){
    vc=0;
    vf=0;
    scanf("%d%d%d%d",&n,&m,&c,&f);
    getchar();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m+1;++j)
            a[i][j]=getchar();
    for(int i=n;i>=1;--i)
        for(int j=m;j>=1;--j)
            if(a[i][j]=='1'){
                you[i][j]=-1;
                xia[i][j]=-1;
                sumyou[i][j]=0;
                sumxia[i][j]=0;
            }
            else{
                you[i][j]=j==m?0:you[i][j+1]+1;
                xia[i][j]=i==n?0:xia[i+1][j]+1;
                sumyou[i][j]=(i==n?0:sumyou[i+1][j])+you[i][j];
                sumxia[i][j]=i==n?0:sumxia[i+1][j]+you[i][j]*xia[i][j];
            }
}
void fun(int x,int y){
    if(xia[x][y]<2||you[x][y]==0)
        return;
    if(c)
        vc=(you[x][y]*sumyou[x+2][y]+vc)%998244353;
    if(f)
        vf=(you[x][y]*sumxia[x+2][y]+vf)%998244353;
}
int main(){
    // freopen("in.in","r",stdin);
    // freopen("out.out","w",stdout);
    int T,id;
    scanf("%d %d",&T,&id);
    for(;T>=1;--T){
        init();
        for(int i=1;i<n-1;++i)
            for(int j=1;j<m;++j)
                fun(i,j);
        printf("%d %d\n",vc,vf);
    }
    return 0;
}