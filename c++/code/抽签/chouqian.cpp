#include<bits/stdc++.h>
using namespace std;
int nian=0,yue=0,ri=0,n=0;
string qian;
void chouqian(){
    srand(time(0));
    int t=rand()%10+1;
    if(t==1){
        qian="上上签";
        ++n;
    }
    else if(t<=3)
        qian="上签";
    else if(t<=7)
        qian="中签";
    else if(t<=9)
        qian="下签";
    else
        qian="下下签";
}
int main(){
    ifstream fin("data");
    if(!fin.is_open())
        cout<<"未找到数据文件，将自动创建"<<endl;
    else
        fin>>nian>>yue>>ri>>qian>>n;
    fin.close();
    ofstream fout("data");
    time_t now=time(0);
    tm* tnow=localtime(&now);
    if(ri!=tnow->tm_mday||yue!=tnow->tm_mon+1||nian!=tnow->tm_year+1900){
        chouqian();
        ri=tnow->tm_mday;
        yue=tnow->tm_mon+1;
        nian=tnow->tm_year+1900;
    }
    cout<<"你今天抽到的签为"<<qian<<endl<<"截止到今日，你共抽到上上签"<<n<<"次"<<endl;
    fout<<nian<<" "<<yue<<" "<<ri<<endl<<qian<<endl<<n;
    return 0;
}
