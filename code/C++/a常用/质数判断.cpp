#include <bits/stdc++.h>
using namespace std;
bool pd(int a){
	if(a<2)
		return 0;
    for(int i=2;i*i<=a;i++)
        if(a%i==0)
            return 0;
    return 1;
}//判断一个数是否为质数