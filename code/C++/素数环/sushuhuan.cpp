#include <iostream>
#include <cstdio>
#include <cmath>
#define size 100
using namespace std;
FILE *out;
int a[size+1];
int total=0;
bool b[size+1];
void outa()
{
	int i;
	total++;
	fprintf(out,"<%d>:",total);
	for(i=1;i<=size;i++)
	{
		fprintf(out,"%d ",a[i]);
	}
	fprintf(out,"\n");
}
bool pd(int z)
{
	int i;
	for(i=2;i<=sqrt(z);i++)
	{
		if(z%i==0)
		{
			return false;
		}
	}
	return true;
}
void search(int n)
{
	int i;
	if(n==size)
	{
		for(i=2;i<=size;i++)
		{
			if(!b[i] && pd(a[n-1]+i) && pd(i+a[1]))
			{
				a[n]=i;
				b[i]=1;
				outa();
				b[i]=0;
			}
		}
	}
	else
	{
		for(i=2;i<=size;i++)
		{
			if(!b[i] && pd(a[n-1]+i))
			{
				a[n]=i;
				b[i]=1;
				search(n+1);
				b[i]=0;
			}
		}
	}
}
int main(int argc, char** argv)
{
	out=fopen("out.out","w");
	a[1]=1;
	b[1]=1;
	search(2);
	printf("total:%d",total);
	fprintf(out,"total:%d",total);
	return 0;
}