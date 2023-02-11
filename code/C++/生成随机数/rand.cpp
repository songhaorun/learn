#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    int ma,mi,t;
    map<int,bool> mp;
    cout<<"输入最小值和最大值";
    cin>>mi>>ma;
    getchar();
    for(int i=mi;i<=ma;i++){
        do{
            t=rand()%(ma-mi+1)+mi;
        }while(mp[t]);
        cout<<t;
        mp[t]=1;
        getchar();
    }
    return 0;
}