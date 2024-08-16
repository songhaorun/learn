#include <bits/stdc++.h>
using namespace std;
int duiying[9][9];
FILE *in,*out;
int a[9][9];
bool hang[9][10],lie[9][10],ge[9][10];
vector<int> canput[9][9];
int total=0;
void put(int x,int y,int n){
	a[x][y]=n;
	hang[x][n]=1;
	lie[y][n]=1;
	ge[x/3*3+y/3][n]=1;
}
void unput(int x,int y,int n){
	a[x][y]=0;
	hang[x][n]=0;
	lie[y][n]=0;
	ge[x/3*3+y/3][n]=0;
}
void dfs(int x,int y){
	if(x==9){
		total++;
		fprintf(out,"<%d>\n",total);
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j)
				fprintf(out,"%d ",a[i][j]);
			fprintf(out,"\n");
		}
		fprintf(out,"\n");
		return;
	}
	if(a[x][y]){
		dfs(x+(y+1)/9,(y+1)%9);
		return;
	}
	for(int n:canput[x][y])
		if(!hang[x][n] && !lie[y][n] && !ge[x/3*3+y/3][n]){
			put(x,y,n);
			dfs(x+(y+1)/9,(y+1)%9);
			unput(x,y,n);
		}
}
int main(){
	in=fopen("in.in","r");
	out=fopen("out.out","w");
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j){
			fscanf(in,"%1d",&a[i][j]);
			if(a[i][j])
				put(i,j,a[i][j]);
		}
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			for(int n=1;n<=9;++n)
				if(!hang[i][n] && !lie[j][n] && !ge[i/3*3+j/3][n])
					canput[i][j].push_back(n);
	dfs(0,0);
	if(total==0)
		fprintf(out,"无解");
	else
		fprintf(out,"共%d种",total);
	return 0;
}