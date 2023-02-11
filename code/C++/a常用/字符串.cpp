#include <bits/stdc++.h>
using namespace std;
int zhuan(string s){
    int t=0;
    for(int i=0;i<s.length();i++){
        t*=10;
        t+=s[i]-'0';
    }
    return t;
}//数字字符串转整形