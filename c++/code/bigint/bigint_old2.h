#include <bits/stdc++.h>
using namespace std;
class bigint{
	int flag;
	vector<int> num;
	void jian(){	
		while(*num.rbegin()==0)
			num.pop_back();
		if(num.empty()){
			flag=1;
			num.push_back(0);
			return;
		}
		if(*num.rbegin()<0){
			flag=-1*flag;
			for(int i=0;i<num.size();i++)
				num[i]=num[i]*-1;
		}
		for(int i=0;i<num.size()-1;i++){
				num[i+1]+=num[i]/10;
				num[i]%=10;
				if(num[i]<0){
					num[i+1]--;
					num[i]+=10;
				}
		}
		if(*num.rbegin()==0)
			num.pop_back();
		while(*num.rbegin()>9){
			num.push_back(*num.rbegin()/10);
			*(++num.rbegin())%=10;
		}
	}
	void push_back(int a){
		num.push_back(a);
	}
	void pop_back(){
		num.pop_back();
	}
public:
//构造函数
	bigint(){
		flag=1;
		num.push_back(0);
	}
	bigint(int a){
		if(a<0){
			flag=-1;
			a=-a;
		}
		else
			flag=1;
		do{
			num.push_back(a%10);
			a/=10;
		}while(a!=0);
	}
	bigint(const char *s){
		int ed=0;
		if(s[0]=='-'){
			flag=-1;
			ed++;
		}
		else
			flag=1;
		for(int i=strlen(s)-1;i>=ed;--i)
			num.push_back(s[i]-'0');
	}
	bigint(const string &s){
		int ed=0;
		if(s[0]=='-'){
			flag=-1;
			ed++;
		}
		else
			flag=1;
		for(int i=s.length()-1;i>=ed;i--)
			num.push_back(s[i]-'0');
	}
//方法
	const size_t length() const {
		return num.size();
	}
	void print() const {
		cout<<"flag:"<<flag<<endl;
		cout<<"num:";
		for(int i:num)
			cout<<i<<" ";
		cout<<endl;
	}
//符号重载
	int& operator[](const int a) {
		return num[a];
	}
	const int& operator[](const int a) const {
		return num[a];
	}
	void operator=(const bigint &a){
		flag=a.flag;
		num=a.num;
	}
	void operator+=(const bigint &a){
		*this=*this+a;
	}
	void operator-=(const bigint &a){
		*this=*this-a;
	}
	// void operator*=(const bigint &a){
	// 	*this=*this*a;
	// }
	// void operator/=(const bigint &a){
	// 	*this=*this/a;
	// }
	// void operator%=(const bigint &a){
	// 	*this=*this%a;
	// }
	const bigint operator++(int){
		bigint t=*this;
		++*this;
		return t;
	}
	bigint operator++(){
		(*this)[0]+=this->flag;
		this->jian();
		return *this;
	}
	const bigint operator--(int){
		bigint a=*this;
		--*this;
		return a;
	}
	bigint operator--(){
		(*this)[0]-=this->flag;
		this->jian();
		return*this;
	}
	const bigint operator+(const bigint &a) const {
		bigint ans="";
		size_t i=0;
		if(this->length()>a.length()){
			for(;i<a.length();++i)
				ans.push_back((this->num[i]*this->flag)+a[i]*a.flag);
			for(;i<this->length();++i)
				ans.push_back(this->num[i]*this->flag);
		}
		else{
			for(;i<this->length();++i)
				ans.push_back((this->num[i]*this->flag)+a[i]*a.flag);
			for(;i<a.length();++i)
				ans.push_back(a[i]*a.flag);
		}
		ans.jian();
		return ans;
	}
	const bigint operator-() const {
		bigint ans=*this;
		ans.flag*=-1;
		return ans;
	}
	const bigint operator-(const bigint &a) const {
		return (*this)+(-a);
	}
	// const bigint operator*(const bigint &a) const {
	// 	bigint ans;
	// 	for(int i=0;i<a.length();i++){
	// 		bigint t=0;
	// 		for(int j=0;j<i;j++)
	// 			t.push_back(0);
	// 		for(int j=0;j<this->length();j++)
	// 			t.push_back(this->num[j]*a[i]);
	// 		ans+=t;
	// 	}
	// 	ans.flag=this->flag*a.flag;
	// 	ans.jian();
	// 	return ans;
	// }
	// bigint operator/(bigint a){
	// 	bigint t=*this,ans(0);
	// 	int f=this->flag*a.flag;
	// 	int fa=a.flag;
	// 	t.flag=1;
	// 	a.flag=1;
	// 	while((t>=a)){
	// 		t-=a;
	// 		++ans;
	// 	}
	// 	ans.flag=f;
	// 	a.flag=fa;
	// 	ans.jian();
	// 	return ans;
	// }
	// const bigint operator%(const bigint &a) const {
	// 	bigint ans=*this,ta=a;
	// 	ans.flag=1;
	// 	ta.flag=1;
	// 	while(tt>=ta)
	// 		t-=a;
	// 	ans=t;
	// 	ans.flag=this->flag;
	// 	ans.jian();
	// 	return ans;
	// }
	const bool operator==(const bigint &a) const {
		if(this->flag!=a.flag || this->length()!=a.length())
			return 0;
		for(int i=0;i<this->length();++i)
			if((*this)[i]!=a[i])
				return 0;
		return 1;
	}
	const bool operator<(const bigint &a) const {
		if(this->flag<a.flag)
			return 1;
		if(this->length()!=a.length())
			return (this->length()<a.length())*this->flag;
		for(int i=this->length();i>=0;--i)
			if((*this)[i]!=a[i])
				return ((*this)[i]<a[i])*this->flag;
		return 0;
	}
	const bool operator>(const bigint &a) const {
		return a<*this;
	}
	const bool operator<=(const bigint &a) const {
		return !(*this>a);
	}
	const bool operator>=(const bigint &a) const {
		return !(*this<a);
	}
	friend istream &operator>>(istream &in,bigint &a){
		string s;
		in>>s;
		a=s;
		return in;
	}
	friend ostream &operator<<(ostream &out,const bigint &a) {
		if(a.flag==-1)
			out<<"-";
		for(int i=a.length()-1;i>=0;--i)
			out<<a.num[i];
		return out;
	}
};