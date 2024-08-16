#include<bits/stdc++.h>
using namespace std;
int nian=0,yue=0,ri=0,n[6];
string qian;
void chouqian(){
    ++n[0];
    srand(time(0));
    int t=rand()%10+1;
    if(t==1){
        qian="上上签";
        ++n[1];
    }
    else if(t<=3){
        qian="上签";
        ++n[2];
    }
    else if(t<=7){
        qian="中签";
        ++n[3];
    }
    else if(t<=9){
        qian="下签";
        ++n[4];
    }
    else{
        qian="下下签";
        ++n[5];
    }
}
int main(){
    memset(n,0,sizeof(n));
    ifstream fin("data");
    if(!fin.is_open())
        cout<<"未找到数据文件，将自动创建"<<endl;
    else{
        fin>>nian>>yue>>ri>>qian;
        for(int i=0;i<=5;++i)
            fin>>n[i];
    }
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
    cout<<"你今天抽到的签为"<<qian<<endl;
    cout<<"抽签统计:"<<endl;
    cout<<"共抽"<<n[0]<<"次"<<endl;
    cout<<"上上签"<<n[1]<<"次"<<endl;
    cout<<"上签"<<n[2]<<"次"<<endl;
    cout<<"中签"<<n[3]<<"次"<<endl;
    cout<<"下签"<<n[4]<<"次"<<endl;
    cout<<"下下签"<<n[5]<<"次"<<endl;
    fout<<nian<<" "<<yue<<" "<<ri<<endl<<qian<<endl;
    for(int i=0;i<=5;++i)
        fout<<n[i]<<endl;
    fout.close();
    return 0;
}
