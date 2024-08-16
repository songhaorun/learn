#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,string> mp={
        {"one","01"},
        {"two","04"},
        {"three","09"},
        {"four","16"},
        {"five","25"},
        {"six","36"},
        {"seven","49"},
        {"eight","64"},
        {"nine","81"},
        {"ten","00"},
        {"eleven","21"},
        {"twelve","44"},
        {"thirteen","69"},
        {"fourteen","96"},
        {"fifteen","25"},
        {"sixteen","56"},
        {"seventeen","89"},
        {"eighteen","24"},
        {"nineteen","61"},
        {"twenty","00"},
        {"a","01"},
        {"both","04"},
        {"another","01"},
        {"first","01"},
        {"second","04"},
        {"third","09"}};
    map<string,int> st;
    string t;
    for(int i=1;i<=6;++i){
        cin>>t;
        if(mp.find(t)!=mp.end())
            st[mp[t]]++;
    }
    if(st.empty())
        cout<<"0";
    else{
        string ans;
        for(auto i:st)
            for(int j=1;j<=i.second;++j)
                ans+=i.first;
        int i=0;
        while(ans[i]=='0')
            ++i;
        for(;i<ans.length();++i)
            cout<<ans[i];
    }
    return 0;
}