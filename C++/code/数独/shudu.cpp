#include <iostream>
#include <cstdio>
using namespace std;
FILE *in,*out;
int total=0;
void shuru(int a[10][10]);
void shuchu(int a[10][10]);
void chuli(int a[10][10],bool b[10][10][10],int p,int q,int x,int y,int z);
int main(int argc, char** argv) 
{
	in=fopen("in.in","r");
	out=fopen("out.out","w");
	int a[10][10]={0};
	bool b[10][10][10]={0};
	shuru(a);
	for(int e=1;e<10;e++)
	{
		for(int f=1;f<10;f++)
		{
			if(a[e][f]!=0)
			{
				for(int i=1;i<10;i++)
				{
					b[e][i][a[e][f]]=1;
					b[i][f][a[e][f]]=1;
				}
				int c=(e-1)/3;
				int d=(f-1)/3;
				for(int m=3*c+1;m<=3*(c+1);m++)
				{
					for(int n=3*d+1;n<=3*(d+1);n++)
					{
						b[m][n][a[e][f]]=1;
					}
				}
				for(int i=1;i<10;i++)
				{
					b[e][f][i]=1;
				}
			}	
		}
	}
	chuli(a,b,1,1,0,0,0);
	if(total==0)
	{
		fprintf(out,"无解");
	}
	else
	{
		fprintf(out,"共%d种",total);
	}
	return 0;
}
void shuru(int a[10][10])
{
	for(int m=1;m<10;m++)
	{
		for(int n=1;n<10;n++)
		{
			fscanf(in,"%1d",&a[m][n]);
		}
	}
}
void shuchu(int a[10][10])
{
	total++;
	fprintf(out,"<%d>\n",total);
	for(int m=1;m<10;m++)
	{
		for(int n=1;n<10;n++)
		{
			fprintf(out,"%d ",a[m][n]);
		}
		fprintf(out,"\n");
	}
	fprintf(out,"\n");	
}
void chuli(int a[10][10],bool b[10][10][10],int p,int q,int x,int y,int z)
{
	int aa[10][10];
	bool bb[10][10][10];
	for(int c=1;c<10;c++)
	{
		for(int d=1;d<10;d++)
		{
			for(int e=1;e<10;e++)
			{
				aa[d][e]=a[d][e];
				bb[c][d][e]=b[c][d][e];
			}
		}
	}
	if(x!=0 && y!=0 && z!=0)
	{
		aa[x][y]=z;
		for(int i=1;i<10;i++)
		{
			bb[x][i][z]=1;
			bb[i][y][z]=1;
		}
		int c=(x-1)/3;
		int d=(y-1)/3;
		for(int m=3*c+1;m<=3*(c+1);m++)
		{
			for(int n=3*d+1;n<=3*(d+1);n++)
			{
				bb[m][n][z]=1;
			}
		}
		for(int i=1;i<10;i++)
		{
			bb[x][y][i]=1;
		}
	}
	if(aa[p][q]!=0)
	{
		if(q==9)
		{
			if(p==9)
			{
				shuchu(aa);
			}
			else
			{
				chuli(aa,bb,p+1,1,0,0,0);
			}
		}
		else
		{
			chuli(aa,bb,p,q+1,0,0,0);
		}
	}
	else
	{
		for(int i=1;i<10;i++)
		{
			if(bb[p][q][i]==0)
			{
				if(q==9)
				{
					if(p==9)
					{
						aa[9][9]=i;
						shuchu(aa);
						aa[9][9]=0;
					}
					else
					{
						chuli(aa,bb,p+1,1,p,q,i);
					}
				}
				else
				{
					chuli(aa,bb,p,q+1,p,q,i);
				}
			}
		}
	}
}