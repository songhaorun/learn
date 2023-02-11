#include<bits/stdc++.h>
using namespace std;
int n,m,c,f,vc,vf;
int you[1001][1001],xia[1001][1001];
void init(){
    vc=0;
    vf=0;
    char s[1002];
    scanf("%d%d%d%d",&n,&m,&c,&f);
    getchar();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m+1;++j)
            s[j]=getchar();
        for(int j=m,t=m;j>=1;--j)
            if(s[j]=='1'){
                you[i][j]=-1;
                t=j-1;
            }
            else
                you[i][j]=t;
    }
    for(int j=1;j<=m;++j){
        for(int i=n,t=n;i>=1;--i)
            if(you[i][j]==-1){
                xia[i][j]=-1;
                t=i-1;
            }
            else
                xia[i][j]=t;
    }
}
void fun(int x,int y){
    if(you[x][y]==-1||you[x][y]==y||xia[x][y]-x<2)
        return;
    int ls=you[x][y]-y;
    for(int i=x+2;i<=xia[x][y];++i){
        int lx=you[i][y]-y;
        if(lx){
            int nc=(you[x][y]-y)*(you[i][y]-y);
            if(c)
                vc=(vc+nc)%998244353;
            if(f)
                vf=(vf+(xia[x][y]-i)*nc)%998244353;
        }
    }
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