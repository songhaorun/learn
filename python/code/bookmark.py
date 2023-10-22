from bs4 import BeautifulSoup

def add_if_exist(object,name):
    # 若object.name存在返回\t\t+object.name,否则返回""
    return ("\t\t"+getattr(object,name)) if hasattr(object,name) else ""

class node:
    #children为node和leaf组成的列表
    def __init__(self,name):
        self.name=name
        self.children=[]

    def str(self,n=0):
        ans="\t"*n+self.name+"\n"
        for i in self.children:
            ans+=i.str(n+1)
        return ans

class leaf:
    def __init__(self,name):
        self.name=name

    def str(self,n=0):
        return "\t"*n+self.name+"\t\t"+self.href+"\n"


def dfs(now,ans):
    for tag in now:
        if tag.name==None:
            continue
        elif tag.name=="dl":
            dfs(tag,ans.children[-1])
        else:
            if tag.name=="h3":
                ans.children.append(node(tag.string))
            elif tag.name=="a":
                ans.children.append(leaf(tag.string))
            for i in tag.attrs:
                setattr(ans.children[-1],i,tag.attrs[i])


soup = BeautifulSoup(open("favorite.html",'r',encoding="UTF-8"),"lxml")
for i in soup(["p","dt"]):
    i.unwrap()
ans=node("bookmarks")
dfs(soup.dl,ans)


with open("out.html",'w',encoding="UTF-8") as f:
    f.write(ans.str())