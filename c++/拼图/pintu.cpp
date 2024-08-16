// 输入：
// 横 竖 障碍个数 猫类数
// 障碍1横 竖
// ...
// 猫类1形状（1表示此格有，以@结尾） 个数
// ...
#include<bits/stdc++.h>
using namespace std;
bool kong[20][20];							//此格非空？
int ans[20][20];							//结果（所有格）
int heng,shu,num=0,tnum=0;							//横长，竖长，猫总数，已放下的猫总数

struct xingzhuang{
	bool xz[6][6];
	int z,s;
};

class cat{
public:
	xingzhuang xing[4];						//4种形状
	int shu;								//个数
	void ru(){								//输入猫的形状和个数
		for(int i=0;i<4;++i){
			xing[i].z=7;
			xing[i].s=7;
		}
		string a;
		for(int i=0;i<6;++i){
			cin>>a;
			for(int j=0;j<a.length();++j)
				if(a[j]=='1'){
					xing[0].xz[j][i]=1;
					xing[0].z=min(j,xing[0].z);
					xing[0].s=min(i,xing[0].s);
				}
			if(a[a.length()-1]=='@')
				break;
		}
		for(int i=1;i<=3;++i){
			for(int j=0;j<6;++j)
				for(int k=0;k<6;++k){
					xing[i].xz[j][k]=xing[i-1].xz[5-k][j];
					if(xing[i].xz[j][k]){
						xing[i].z=min(j,xing[i].z);
						xing[i].s=min(k,xing[i].s);
					}
				}
		}
		cin>>shu;
		num+=shu;
	}
	void print(){
		cout<<shu<<endl;
		for(int i=0;i<4;++i){
			cout<<xing[i].z<<" "<<xing[i].s<<endl;
			for(int j=0;j<6;++j){
				for(int k=0;k<6;++k)
					cout<<xing[i].xz[k][j];
				cout<<endl;
			}
			cout<<endl;
		}
	}
};
cat mao[31];//30种猫

void shuru(){
	int a,b;
	cin>>heng>>shu>>a>>b;
	for(int i=1;i<=a;++i){
		int x,y;
		cin>>x>>y;
		kong[x][y]=1;
	}
	for(int i=1;i<=b;++i)
		mao[i].ru();
}

bool candowm(int x,int y,int a,int b){		//在x，y处能否放下第a种猫的第b种形状
	for(int i=0;mao[a].xing[b].z+i<6;++i)
		for(int j=0;mao[a].xing[b].s+j<6;++j)
			if((x+i>heng || y+j>shu || kong[x+i][y+j]) && mao[a].xing[b].xz[mao[a].xing[b].z+i][mao[a].xing[b].s+j])
				return 0;
	return 1;
}
void down(int x,int y,int a,int b){			//在x，y处放第a种猫的第b种形状
	--mao[a].shu;
	++tnum;
	for(int i=0;mao[a].xing[b].z+i<6;++i)
		for(int j=0;mao[a].xing[b].s+j<6;++j)
			if(mao[a].xing[b].xz[mao[a].xing[b].z+i][mao[a].xing[b].s+j]){
				kong[x+i][y+j]=1;
				ans[x+i][y+j]=tnum;
			}
}
void undown(int x,int y,int a,int b){		//取消在x，y处放第a种猫的第b种形状
	++mao[a].shu;
	--tnum;
	for(int i=0;mao[a].xing[b].z+i<6;++i)
		for(int j=0;mao[a].xing[b].s+j<6;++j)
			if(mao[a].xing[b].xz[mao[a].xing[b].z+i][mao[a].xing[b].s+j])
				kong[x+i][y+j]=0;
}
void print(){
	for(int i=1;i<=shu;++i){
		for(int j=1;j<=heng;++j)
			cout<<ans[j][i]<<"\t";
		cout<<endl;
	}
}

void dfs(int a){							//尝试放一只第a种猫
	for(int x=1;x<=heng;++x)
		for(int y=1;y<=shu;++y)
			for(int i=0;i<4;++i)
				if(candowm(x,y,a,i)){
					down(x,y,a,i);
					if(tnum==num){
						print();
						exit(0);
						cout<<"1";
					}
					dfs(mao[a].shu==0?a+1:a);
					undown(x,y,a,i);
				}
}

int main(){
	shuru();
	dfs(1);
	cout<<"no answer";
	return 0;
}