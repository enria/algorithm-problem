# 循环增加会

s=input()
output=[]
cur=0
i=0
while i<len(s):
    c=s[i]
    if c<='9' and c>='0':
        j=i+1
        while j<len(s) and s[j]<='9' and s[j]>='0':
            j+=1
        num=int(s[i:j])
        output.append(s[cur:i]*num)
        i=j
        cur=i
    else:
        i+=1
        if i==len(s):
            output.append(s[cur:i])
print("".join(output))