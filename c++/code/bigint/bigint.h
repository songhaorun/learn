#include <bits/stdc++.h>
using namespace std;
class number // 正整数 低位在前高位在后
{
	vector<int> data;

public:
	// 构造函数

	number() {}
	number(int a)
	{
		do
		{
			this->push_back(a % 10);
			a /= 10;
		} while (a != 0);
	}
	number(const char *s)
	{
		for (size_t i = strlen(s); i >= 1; --i)
			this->push_back(s[i - 1] - '0');
	}
	number(const string &s)
	{
		for (size_t i = s.length(); i >= 1; i--)
			this->push_back(s[i - 1] - '0');
	}
	number(const number &a)
	{
		// cout << "ncopybuild" << endl;
		*this = a;
	}

	// 调试用打印值

	void print() const
	{
		cout << "data:";
		for (int i : this->data)
			cout << i << " ";
		cout << endl;
	}

	// 迭代器

	auto begin()
	{
		return this->data.begin();
	}
	auto begin() const
	{
		return this->data.cbegin();
	}
	auto end()
	{
		return this->data.end();
	}
	auto end() const
	{
		return this->data.cend();
	}

	// 获取长度

	size_t size() const
	{
		return this->data.size();
	}

	// 访问数字

	int &operator[](size_t i)
	{
		return this->data[i];
	}
	const int &operator[](size_t i) const
	{
		return this->data[i];
	}
	int &at(size_t i)
	{
		return this->data.at(i);
	}
	const int &at(size_t i) const
	{
		return this->data.at(i);
	}
	int &front()
	{
		return this->data.front();
	}
	const int &front() const
	{
		return this->data.front();
	}
	int &back()
	{
		return this->data.back();
	}
	const int &back() const
	{
		return this->data.back();
	}

	// 增删数字

	void push_back(int a)
	{
		this->data.emplace_back(a);
	}
	void pop_back()
	{
		this->data.pop_back();
	}
	void push_front(int a)
	{
		this->data.emplace(this->begin(), a);
	}
	void pop_front()
	{
		this->data.erase(this->begin());
	}

	// 清空

	void clear()
	{
		this->data.clear();
	}

	// 判空

	bool empty() const
	{
		return this->data.empty();
	}

	// 删除前导零

	void erase_frontzero()
	{
		while (this->back() == 0)
			this->pop_back();
		if (this->empty())
			this->push_back(0);
	}

	// 赋值

	number &operator=(const number &a)
	{
		// cout << "ncopy" << endl;
		this->data = a.data;
		return *this;
	}
	number &operator=(const number &&a)
	{
		// cout << "nmove" << endl;
		this->data = move(a.data);
		return *this;
	}
	number &operator+=(const number &a)
	{
		*this = *this + a;
		return *this;
	}
	number &operator-=(const number &a)
	{
		*this = *this - a;
		return *this;
	}
	number &operator*=(const number &a)
	{
		*this = *this * a;
		return *this;
	}
	number &operator/=(const number &a)
	{
		*this = *this / a;
		return *this;
	}
	number &operator%=(const number &a)
	{
		*this = *this % a;
		return *this;
	}

	// 比较大小

	friend bool operator==(const number &a, const number &b)
	{
		if (a.size() != b.size())
			return 0;
		for (size_t i = 0; i <= a.size(); ++i)
			if (a[i] != b[i])
				return 0;
		return 1;
	}
	friend bool operator!=(const number &a, const number &b)
	{
		return !(a == b);
	}
	friend bool operator<(const number &a, const number &b)
	{
		if (a.size() != b.size())
			return a.size() < b.size();
		for (size_t i = a.size() - 1; i >= 0; --i)
			if (a[i] != b[i])
				return a[i] < b[i];
		return 0;
	}
	friend bool operator>(const number &a, const number &b)
	{
		return b < a;
	}
	friend bool operator<=(const number &a, const number &b)
	{
		return !(a > b);
	}
	friend bool operator>=(const number &a, const number &b)
	{
		return !(a < b);
	}

	// 加 减 乘 除 取余

	static const number __add(const number &l, const number &s) // 长加短
	{
		number ans;
		bool jinwei = 0;
		for (size_t i = 0; i < l.size(); ++i)
		{
			ans.push_back(l[i] + (i < s.size() ? s[i] : 0) + jinwei);
			if (jinwei = ans.back() > 9)
				ans.back() -= 10;
		}
		if (jinwei)
			ans.push_back(1);
		return ans;
	}
	friend const number operator+(const number &a, const number &b)
	{
		if (a.size() < b.size())
			return __add(b, a);
		return __add(a, b);
	}
	friend const number operator-(const number &a, const number &b) // 大减小
	{
		number ans;
		bool jiewei = 0;
		for (size_t i = 0; i < a.size(); ++i)
		{
			ans.push_back(a[i] - (i < b.size() ? b[i] : 0) - jiewei);
			if (jiewei = ans.back() < 0)
				ans.back() += 10;
		}
		ans.erase_frontzero();
		return ans;
	}
	static const number __mul(const number &a, const number &b)
	{
		number ans = 0;
		for (size_t i = 0; i < b.size(); ++i)
		{
			number t;
			for (size_t j = 0; j < i; j++)
				t.push_back(0);
			int jinwei = 0;
			for (size_t j = 0; j < a.size(); j++)
			{
				t.push_back(a[j] * b[i] + jinwei);
				jinwei = t.back() / 10;
				t.back() %= 10;
			}
			if (jinwei)
				t.push_back(jinwei);
			ans += t;
		}
		return ans;
	}
	friend const number operator*(const number &a, const number &b) // 长乘短
	{
		if (a.size() < b.size())
			return __mul(b, a);
		return __mul(a, b);
	}
	static const pair<number, number> __div(const number &a, const number &b) // 有余数除法,返回pair<商,余数>,除数为0时返回<0,0>
	{
		if (a.size() < b.size())
			return make_pair(move(number(0)), a);
		if (b == 0)
			return make_pair(move(number(0)), move(number(0)));
		number ta = a, tb, ans;
		size_t t = a.size() - b.size();
		for (size_t i = 1; i <= t; ++i)
			tb.push_back(0);
		for (int i : b)
			tb.push_back(i);
		for (size_t i = 0; i <= t; ++i)
		{
			int tans = 0;
			while (ta >= tb)
			{
				ta -= tb;
				++tans;
			}
			ans.push_back(tans);
			tb.pop_front();
		}
		reverse(ans.begin(), ans.end());
		ans.erase_frontzero();
		return make_pair(move(ans), move(ta));
	}
	friend const number operator/(const number &a, const number &b)
	{
		return __div(a, b).first;
	}
	friend const number operator%(const number &a, const number &b)
	{
		return __div(a, b).second;
	}
};

class bigint // 整数
{
	int flag;
	number num;

public:
	// 构造函数

	bigint()
	{
		this->flag = 1;
		this->push_back(0);
	}
	bigint(int a)
	{
		if (a < 0)
		{
			this->flag = -1;
			a = -a;
		}
		else
			this->flag = 1;
		do
		{
			this->push_back(a % 10);
			a /= 10;
		} while (a != 0);
	}
	bigint(const char *s)
	{
		int ed = 1;
		if (s[0] == '-')
		{
			this->flag = -1;
			ed++;
		}
		else
			this->flag = 1;
		for (size_t i = strlen(s) ; i >= ed; --i)
			this->push_back(s[i-1] - '0');
	}
	bigint(const string &s)
	{
		int ed = 1;
		if (s[0] == '-')
		{
			this->flag = -1;
			ed++;
		}
		else
			this->flag = 1;
		for (size_t i = s.length() ; i >= ed; i--)
			this->push_back(s[i-1] - '0');
	}
	bigint(const bigint &a)
	{
		// cout << "bcopybuild" << endl;
		*this = a;
	}

	// 调试用打印值

	void print() const
	{
		cout << "flag:" << this->flag << endl;
		cout << "num:";
		for (int i : this->num)
			cout << i << " ";
		cout << endl;
	}

	// 迭代器

	auto begin()
	{
		return this->num.begin();
	}
	auto begin() const
	{
		return this->num.begin();
	}
	auto end()
	{
		return this->num.end();
	}
	auto end() const
	{
		return this->num.end();
	}

	// 获取长度

	size_t length() const
	{
		return num.size();
	}

	// 访问数字

	int &operator[](const size_t a)
	{
		return num[a];
	}
	const int &operator[](const size_t a) const
	{
		return num[a];
	}
	int &at(const size_t a)
	{
		return num.at(a);
	}
	const int &at(const size_t a) const
	{
		return num.at(a);
	}

	// 增删数字

	void push_back(int a)
	{
		this->num.push_back(a);
	}
	void pop_back()
	{
		this->num.pop_back();
	}

	// 赋值

	bigint &operator=(const bigint &a)
	{
		// cout << "bcopy" << endl;
		this->flag = a.flag;
		this->num = a.num;
		return *this;
	}
	bigint &operator=(const bigint &&a)
	{
		// cout << "bmove" << endl;
		this->flag = a.flag;
		this->num = move(a.num);
		return *this;
	}
	bigint &operator+=(const bigint &a)
	{
		*this = *this + a;
		return *this;
	}
	bigint &operator-=(const bigint &a)
	{
		*this = *this - a;
		return *this;
	}
	bigint &operator*=(const bigint &a)
	{
		*this = *this * a;
		return *this;
	}
	bigint &operator/=(const bigint &a)
	{
		*this = *this / a;
		return *this;
	}
	bigint &operator%=(const bigint &a)
	{
		*this = *this % a;
		return *this;
	}

	// 自增 自减

	const bigint operator++(int)
	{
		bigint t = *this;
		++(*this);
		return t;
	}
	bigint &operator++()
	{
		*this += 1;
		return *this;
	}
	const bigint operator--(int)
	{
		bigint t = *this;
		--(*this);
		return t;
	}
	bigint &operator--()
	{
		*this -= 1;
		return *this;
	}

	// 加 取相反数 减 乘 除 取余

	static const bigint __add(const bigint &a, const bigint &b, const int c)
	{
		bigint ans;
		if (a.flag == b.flag * c)
		{
			ans.flag = a.flag;
			ans.num = a.num + b.num;
		}
		else
		{
			if (a.num > b.num)
			{
				ans.flag = a.flag;
				ans.num = a.num - b.num;
			}
			else
			{
				ans.flag = b.flag;
				ans.num = b.num - a.num;
				if (ans.num.size() == 1 && ans.num[0] == 0)
					ans.flag = 1;
			}
		}
		return ans;
	}
	friend const bigint operator+(const bigint &a, const bigint &b)
	{
		return __add(a, b, 1);
	}
	const bigint operator-() const
	{
		bigint ans = *this;
		ans.flag *= -1;
		return ans;
	}
	friend const bigint operator-(const bigint &a, const bigint &b)
	{
		return __add(a, b, -1);
	}
	friend const bigint operator*(const bigint &a, const bigint &b)
	{
		bigint ans;
		ans.flag = a.flag * b.flag;
		ans.num = a.num * b.num;
		return ans;
	}
	friend const bigint operator/(const bigint &a, const bigint &b)
	{
		bigint ans;
		ans.flag = a.flag * b.flag;
		ans.num = a.num / b.num;
		return ans;
	}
	friend const bigint operator%(const bigint &a, const bigint &b) // 计算方式与c++相同
	{
		bigint ans;
		ans.flag = a.flag * b.flag;
		ans.num = a.num % b.num;
		return ans;
	}

	// 比较大小

	friend bool operator==(const bigint &a, const bigint &b)
	{
		if (a.flag != b.flag)
			return 0;
		return a.num == b.num;
	}
	friend bool operator!=(const bigint &a, const bigint &b)
	{
		return !(a == b);
	}
	friend bool operator<(const bigint &a, const bigint &b)
	{
		if (a.flag < b.flag)
			return 1;
		return a.num < b.num ^ a.flag == -1;
	}
	friend bool operator>(const bigint &a, const bigint &b)
	{
		return b < a;
	}
	friend bool operator<=(const bigint &a, const bigint &b)
	{
		return !(a > b);
	}
	friend bool operator>=(const bigint &a, const bigint &b)
	{
		return !(a < b);
	}

	// 输入输出

	friend istream &operator>>(istream &in, bigint &a)
	{
		string s;
		in >> s;
		a = move(bigint(s));
		return in;
	}
	friend ostream &operator<<(ostream &out, const bigint &a)
	{
		if (a.flag == -1)
			out << "-";
		for (auto i = a.end(); i != a.begin(); --i)
			out << *(i - 1);
		return out;
	}
};