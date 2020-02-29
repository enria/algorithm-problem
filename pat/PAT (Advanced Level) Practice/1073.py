import re
notion = input()
matchs = re.match(r"([+-])([1-9])\.([0-9]+)E([+-])([0-9]+)", notion)
ns, bn, sn, es, en = matchs.groups()
en = int(en)

if es == "+":
    if len(sn)>en:
        nums = bn+sn[0:en]+"."+sn[en:]
    elif len(sn)<en:
        nums = bn+sn+(en-len(sn))*"0"
    else:
        nums=bn+sn#注意如果刚好变整数，未尾不能有0
else:
    if en==0:
        nums=bn+"."+sn
    else:
        nums="0."+"0"*(en-1)+bn+sn

if ns=="+":
    ns=""
print(ns+nums)