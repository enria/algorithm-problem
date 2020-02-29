import re

# 1=@ 0=% l=L O=o

n=int(input())
result=[]
for i in range(0,n):
    i=input()
    i=i.split(" ")
    name=i[0]
    pwd=i[1]
    if re.search("1|0|l|O",pwd):
        pwd=pwd.replace("1","@").replace("0","%").replace("l","L").replace("O","o")
        result.append(name+" "+pwd)
if n==1:
    print("There is 1 account and no account is modified")
    exit(0)
if len(result):
    print(len(result))
    for item in result:
        print(item)
else:
    print("There are %d accounts and no account is modified"%(n))