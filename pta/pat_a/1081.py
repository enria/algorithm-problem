import math

lcm = 0
def clcm(n: int):
    global lcm
    if lcm == 0:
        lcm = n
    else:
        lcm = lcm*n//math.gcd(lcm, n)

n = int(input())
rs = (input().split())
rs = [[int(i) for i in r.split("/")] for r in rs]

for r in rs:
    clcm(r[1])

total = 0
s=""
for r in rs:
    total += r[0]*lcm//r[1]
if total<0:
    s="-"
    total=abs(total)
print(s,end="")
inte=total//lcm
fra=total%lcm
fragcd=math.gcd(fra,lcm)
if fra==0:
    print(inte)
elif inte==0:
    print("{}/{}".format(fra//fragcd,lcm//fragcd))
else:
    print("{} {}/{}".format(inte,fra//fragcd,lcm//fragcd))