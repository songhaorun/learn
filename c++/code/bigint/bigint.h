#include <bits/stdc++.h>
using namespace std;
class bigint{
	int flag;
	vector<int> num;
	void jian(){	
		while(!num.empty()&&num[num.size()-1]==0)
			num.pop_back();
		if(num.empty()){
			flag=1;
			num.push_back(0);
			return;
		}
		if(num[num.size()-1]<0){
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
		if(num[num.size()-1]==0)
			num.pop_back();
		while(num[num.size()-1]>9){
			int t=num.size()-1;
			num.push_back(num[t]/10);
			num[t]%=10;
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
	bigint(const char s[]){
		int ed=0;
		if(s[0]=='-'){
			flag=-1;
			ed++;
		}
		else
			flag=1;
		for(int i=strlen(s)-1;i>=ed;i--)
			num.push_back(s[i]-'0');
	}
	bigint(string s){
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
	int length(){
		return num.size();
	}
	void print(){
		cout<<"flag:"<<flag<<endl;
		cout<<"num:";
		for(int i=0;i<num.size();i++)
			cout<<num[i]<<" ";
		cout<<endl;
	}
//符号重载
	void operator=(bigint a){
		flag=a.flag;
		num=a.num;
	}
	void operator+=(bigint a){
		*this=*this+a;
	}
	void operator-=(bigint a){
		*this=*this-a;
	}
	void operator*=(bigint a){
		*this=*this*a;
	}
	void operator/=(bigint a){
		*this=*this/a;
	}
	void operator%=(bigint a){
		*this=*this%a;
	}
	int operator[](int a){
		return num[a];
	}
	bigint operator++(int){
		bigint a=*this;
		*this+=1;
		return a;
	}
	bigint operator++(){
		*this+=1;
		return *this;
	}
	bigint operator--(int){
		bigint a=*this;
		*this-=1;
		return a;
	}
	bigint operator--(){
		*this-=1;
		return*this;
	}
	bigint operator+(bigint a){
		bigint b="";
		int i=0;
		if(this->length()>a.length()){
			for(;i<a.length();i++)
				b.push_back((this->num[i]*this->flag)+a[i]*a.flag);
			for(;i<this->length();i++)
				b.push_back(this->num[i]*this->flag);
		}
		else{
			for(;i<this->length();i++)
				b.push_back((this->num[i]*this->flag)+a[i]*a.flag);
			for(;i<a.length();i++)
				b.push_back(a[i]*a.flag);
		}
		b.jian();
		return b;
	}
	bigint operator-(){
		bigint a=(*this);
		a.flag*=-1;
		return a;
	}
	bigint operator-(bigint a){
		return (*this)+(-a);
	}
	bigint operator*(bigint a){
		bigint b;
		for(int i=0;i<a.length();i++){
			bigint t="";
			for(int j=0;j<i;j++)
				t.push_back(0);
			for(int j=0;j<this->length();j++)
				t.push_back(this->num[j]*a[i]);
			b+=t;
		}
		b.flag=this->flag*a.flag;
		b.jian();
		return b;
	}
	bigint operator/(bigint a){
		bigint t=*this,ans;
		int f=this->flag*a.flag;
		t.flag=1;
		a.flag=1;
		while((t>=a)){
			t-=a;
			++ans;
		}
		ans.flag=f;
		ans.jian();
		return ans;
	}
	bigint operator%(bigint a){
		bigint t=*this,ans;
		t.flag=1;
		a.flag=1;
		while(t>=a)
			t-=a;
		ans=t;
		ans.flag=this->flag;
		ans.jian();
		return ans;
		}
	bool operator==(bigint a){
		if(this->length()!=a.length())
			return 0;
		for(int i=0;i<this->length();i++)
			if(this->num[i]!=a[i])
				return 0;
		return 1;
	}
	bool operator>(bigint a){
		return (*this-a-1).flag==1?1:0;
	}
	bool operator<(bigint a){
		return (a-*this-1).flag==1?1:0;
	}
	bool operator>=(bigint a){
		return !(*this<a);
	}
	bool operator<=(bigint a){
		return !(*this>a);
	}
	friend istream &operator>>(istream &in,bigint &a){
		string s;
		in>>s;
		a=s;
		return in;
	}
	friend ostream &operator<<(ostream &out,bigint &a){
		if(a.flag==-1)
			out<<"-";
		for(int i=a.num.size()-1;i>=0;i--)
			out<<a.num[i];
		return out;
	}
};