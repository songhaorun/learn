#include <bits/stdc++.h>
using namespace std;
class number{
	shared_ptr<vector<int>> data=make_shared<vector<int>>();
}
class bigint{
	int flag;
	shared_ptr<vector<int>> num=make_shared<vector<int>>();
private:
//绝对值比较

	friend bool operator==(const shared_ptr<vector<int>>& a,const shared_ptr<vector<int>>& b){
		if(a->size()!=b->size())
			return 0;
		for(int i=0;i<=a->size();++i)
			if((*a)[i]!=(*b)[i])
				return 0;
		return 1;
	}
	friend bool operator<(const shared_ptr<vector<int>>& a,const shared_ptr<vector<int>>& b){
		if(a->size()!=b->size())
			return a->size()<b->size();
		for(int i=a->size()-1;i>=0;--i)
			if((*a)[i]!=(*b)[i])
				return (*a)[i]<(*b)[i];
		return 0;
	}

//绝对值加 减 乘 除 取余

	friend const shared_ptr<vector<int>> __add(const shared_ptr<vector<int>>& l,const shared_ptr<vector<int>>& s){//长加短
		shared_ptr<vector<int>> ans=make_shared<vector<int>>();
		ans->push_back((*l)[1]+(*s)[1]);
		bool jinwei=0;
		for(size_t i=0;i<l->size();++i){
			ans->push_back((*l)[i]+(i<s->size()?(*s)[i]:0)+jinwei);
			if(jinwei=ans->back()>9)
				ans->back()-=10;
		}
		if(jinwei)
			ans->push_back(1);
		return ans;
	}
	friend const shared_ptr<vector<int>> operator+(const shared_ptr<vector<int>>& a,const shared_ptr<vector<int>>& b){
		if(a->size()<b->size())
			return __add(b,a);
		return __add(a,b);
	}
	friend const shared_ptr<vector<int>> operator-(const shared_ptr<vector<int>>& a,const shared_ptr<vector<int>>& b){//大减小
		shared_ptr<vector<int>> ans=make_shared<vector<int>>();
		bool jiewei=0;
		for(size_t i=0;i<b->size();++i){
			ans->push_back((*a)[i]-(*b)[i]-jiewei);
			if(jiewei=ans->back()<0)
				ans->back()+=10;
		}
		while(ans->back()==0)
			ans->pop_back();
		return ans;
	}
	friend const shared_ptr<vector<int>> operator*(const shared_ptr<vector<int>>& a,const shared_ptr<vector<int>>& b){
		return NULL;
	}
	friend const shared_ptr<vector<int>> operator/(const shared_ptr<vector<int>>& a,const shared_ptr<vector<int>>& b){
		return NULL;
	}
	friend const shared_ptr<vector<int>> operator%(const shared_ptr<vector<int>>& a,const shared_ptr<vector<int>>& b){
		return NULL;
	}

public:
//构造函数

	bigint(){
		this->flag=1;
		this->push_back(0);
	}
	bigint(int a){
		if(a<0){
			this->flag=-1;
			a=-a;
		}
		else
			this->flag=1;
		do{
			this->push_back(a%10);
			a/=10;
		}while(a!=0);
	}
	bigint(const char *s){
		int ed=0;
		if(s[0]=='-'){
			this->flag=-1;
			ed++;
		}
		else
			this->flag=1;
		for(int i=strlen(s)-1;i>=ed;--i)
			this->push_back(s[i]-'0');
	}
	bigint(const string &s){
		int ed=0;
		if(s[0]=='-'){
			this->flag=-1;
			ed++;
		}
		else
			this->flag=1;
		for(int i=s.length()-1;i>=ed;i--)
			this->push_back(s[i]-'0');
	}
	bigint(const bigint &a){
		this->flag=a.flag;
		*this->num=*a.num;
	}

//调试用打印值

	void print() const {
		cout<<"flag:"<<this->flag<<endl;
		cout<<"num:";
		if(num==NULL)
			cout<<"NULL";
		else
			for(int i:*this->num)
				cout<<i<<" ";
		cout<<endl;
	}

//增删数字

	void push_back(int a){
		num->push_back(a);
	}
	void pop_back(){
		num->pop_back();
	}

//访问数字

	int& operator[](const int a) {
		return (*num)[a];
	}
	const int& operator[](const int a) const {
		return (*num)[a];
	}
	int& at(const int a) {
		return num->at(a);
	}
	const int& at(const int a) const {
		return num->at(a);
	}

//获取长度

	size_t length() const {
		return num->size();
	}
	
//赋值

	bigint& operator=(const bigint &a){
		this->flag=a.flag;
		this->num=a.num;
		return *this;
	}
	bigint& operator+=(const bigint &a){
		*this=*this+a;
		return *this;
	}
	bigint& operator-=(const bigint &a){
		*this=*this-a;
		return *this;
	}
	bigint& operator*=(const bigint &a){
		*this=*this*a;
		return *this;
	}
	bigint& operator/=(const bigint &a){
		*this=*this/a;
		return *this;
	}
	bigint& operator%=(const bigint &a){
		*this=*this%a;
		return *this;
	}

//自增 自减

	const bigint operator++(int){
		bigint t=*this;
		(*this)++;
		return t;
	}
	bigint& operator++(){
		*this+=1;
		return *this;
	}
	const bigint operator--(int){
		bigint t=*this;
		(*this)--;
		return t;
	}
	bigint& operator--(){
		*this-=1;
		return *this;
	}

//加 取相反数 减 乘 除 取余

	friend const bigint operator+(const bigint &a,const bigint &b) {
		bigint ans;
		if(a.flag==b.flag){
			ans.flag=a.flag;
			ans.num=a.num+b.num;
		}
		else{
			if(a.num>b.num){
				ans.flag=a.flag;
				ans.num=a.num-b.num;
			}
			else{
				ans.flag=b.flag;
				ans.num=b.num-a.num;
				if(ans.num->size()==1&&(*ans.num)[0]==0)
					ans.flag=1;
			}
		}
		return ans;
	}
	const bigint operator-() const {
		bigint ans=*this;
		ans.flag*=-1;
		return ans;
	}
	friend const bigint operator-(const bigint &a,const bigint &b) {
		return a + -b;
	}
	friend const bigint operator*(const bigint &a,const bigint &b) {//TODO
		bigint ans;
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
		return ans;
	}
	friend const bigint operator/(const bigint &a,const bigint &b) {//TODO
		bigint ans;
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
		return ans;
	}
	friend const bigint operator%(const bigint &a,const bigint &b) {//TODO
		bigint ans;
	// 	ans.flag=1;
	// 	ta.flag=1;
	// 	while(tt>=ta)
	// 		t-=a;
	// 	ans=t;
	// 	ans.flag=this->flag;
	// 	ans.jian();
		return ans;
	}

//比较大小

	friend bool operator==(const bigint &a,const bigint &b) {
		if(a.flag!=b.flag)
			return 0;
		return a.num==b.num;
	}
	friend bool operator!=(const bigint &a,const bigint &b) {
		return !(a==b);
	}
	bool operator<(const bigint &a) const {
		if(this->flag<a.flag)
			return 1;
		return this->num<a.num ^ this->flag==-1;
	}
	bool operator>(const bigint &a) const {
		return a<*this;
	}
	bool operator<=(const bigint &a) const {
		return !(*this>a);
	}
	bool operator>=(const bigint &a) const {
		return !(*this<a);
	}
	
//输入输出

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
			out<<a[i];
		return out;
	}
};