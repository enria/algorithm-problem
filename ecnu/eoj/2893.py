# hex,oct,bin
from collections import Counter

def simple(a,b):
    for i in range(a,1,-1):
        if a%i==0 and b%i==0:
            return a//i,b//i
    return a,b

n=int(input())
for i in range(n):
    origins=input()
    # s="".join(list(map(lambda x: bin(int(chr(x)))[2:],s)))
    s="".join(list(map(lambda x: bin(int(ord(x)))[2:],origins)))
    c=Counter(s)
    c1=c["1"]
    a,b=simple(c1,8*len(origins))
    print(f"{a}/{b}")
    

