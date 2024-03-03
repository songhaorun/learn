import random
mx=0
n=int(input("选项个数："))
flag=bool(input("是否等比例："))
a={}
print(f"请输入{n}个选项")
for i in range(0,n):
    t=input().split(' ')
    if flag:
        tt=1
    else:
        tt=float(t[1])
    a[t[0]]=tt
    mx+=tt
ran=random.uniform(0,mx)
for key,value in a.items():
    if(ran<=value):
        ans=key
        break
    ran-=value
print(ans)