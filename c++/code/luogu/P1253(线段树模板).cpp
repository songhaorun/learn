#include <bits/stdc++.h>
using namespace std;
int a[1000001];
long long tree[4000001],lz[2][4000001];
bool tag[2][4000001];
void build(int p,int l,int r){
    if(l==r){
        tree[p]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(2*p,l,m);
    build(2*p+1,m+1,r);
    tree[p]=max(tree[2*p],tree[2*p+1]);
}
void updata(int p,int l,int r){
    if(tag[0][p]){
        tag[0][2*p]=tag[0][2*p+1]=1;
        tree[2*p]=tree[2*p+1]=lz[0][p];
        lz[0][2*p]=lz[0][2*p+1]=lz[0][p];
        lz[1][2*p]=lz[1][2*p+1]=0;
        lz[0][p]=0;
    }
    if(tag[1][p]){
        tag[1][2*p]=tag[1][2*p+1]=1;
        tree[2*p]+=lz[1][p];
        tree[2*p+1]+=lz[1][p];
        lz[1][2*p]+=lz[1][p];
        lz[1][2*p+1]+=lz[1][p];
        lz[1][p]=0;
    }
    tag[0][p]=tag[1][p]=0;
}
void setnode(int p,int l,int r,int fl,int fr,int x){
    if(fl<=l && r<=fr){
        tree[p]=x;
        tag[0][p]=1;
        lz[0][p]=x;
        lz[1][p]=0;
        return;
    }
    if(tag[0][p] || tag[1][p])
        updata(p,l,r);
    int m=(l+r)>>1;
    if(fl<=m)
        setnode(2*p,l,m,fl,fr,x);
    if(fr>m)
        setnode(2*p+1,m+1,r,fl,fr,x);
    tree[p]=max(tree[2*p],tree[2*p+1]);
}
void addnode(int p,int l,int r,int fl,int fr,int x){
    if(fl<=l && r<=fr){
        tree[p]+=x;
        tag[1][p]=1;
        lz[1][p]+=x;
        return;
    }
    if(tag[0][p] || tag[1][p])
        updata(p,l,r);
    int m=(l+r)>>1;
    if(fl<=m)
        addnode(2*p,l,m,fl,fr,x);
    if(fr>m)
        addnode(2*p+1,m+1,r,fl,fr,x);
    tree[p]=max(tree[2*p],tree[2*p+1]);
}
long long getmax(int p,int l,int r,int fl,int fr){
    if(fl<=l && r<=fr)
        return tree[p];
    if(tag[0][p] || tag[1][p])
        updata(p,l,r);
    int m=(l+r)>>1;
    long long ans=LONG_LONG_MIN;
    if(fl<=m)
        ans=max(ans,getmax(2*p,l,m,fl,fr));
    if(fr>m)
        ans=max(ans,getmax(2*p+1,m+1,r,fl,fr));
    return ans;
}
int main(){
    int n,q,op,l,r,x;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    build(1,1,n);
    for(;q>0;--q){
        scanf("%d %d %d",&op,&l,&r);
        switch (op){
        case 1:
            scanf("%d",&x);
            setnode(1,1,n,l,r,x);
            break;
        case 2:
            scanf("%d",&x);
            addnode(1,1,n,l,r,x);
            break;
        case 3:
            printf("%lld\n",getmax(1,1,n,l,r));
            break;
        }
    }
    return 0;
}