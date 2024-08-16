#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void fun(int a){
    if(a==0)
        return;
    ans.push_back(a%10);
    fun(a/10);
}
int main(){
    FILE *fout;
    fout=fopen("out.cpp","w");
    string w[5]={"个","十","百","千","万"};
    fprintf(fout,"#include<iostream>\nusing namespace std;\nint main(){\n\tint n;\n\tcout<<\"请给出一个不多于5位的正整数:\";\n\tcin>>n;\n\tswitch(n){\n");
    for(int i=1;i<=99999;i++){
        fprintf(fout,"\tcase %d:\n",i);
        ans.clear();
        fun(i);
        fprintf(fout,"\t\tcout<<\"是%zu位数\"<<endl;\n",ans.size());
        for(int j=0;j<ans.size();j++)
            fprintf(fout,"\t\tcout<<\"%s位数是:%d\"<<endl;\n",w[j].c_str(),ans[j]);
        fprintf(fout,"\t\tcout<<\"倒过来是:");
        for(int j=0;j<ans.size();j++)
            fprintf(fout,"%d",ans[j]);
        fprintf(fout,"\"<<endl;\n\t\tbreak;\n");
    }
    fprintf(fout,"\t}\n\tgetchar();\n\tgetchar();\n\tgetchar();\n\tgetchar();\n\tgetchar();\n\treturn 0;\n}");
    fclose(fout);
    return 0;
}