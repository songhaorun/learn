#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int ans[26],mx=0;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=4;++i){
        getline(cin,s);
        for(size_t j=0;j<s.length();++j)
            if(s[j]!=' ')
                ++ans[s[j]-'A'];
    }
    for(int i=0;i<26;++i)
        mx=max(mx,ans[i]);
    for(int i=1;i<=mx;++i){
        for(int j=0;j<26;++j){
            if(ans[j]+i>mx)
                cout<<"*";
            else
                cout<<" ";
            if(j!=25)
                cout<<" ";
        }
        cout<<endl;
    }
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    return 0;
}