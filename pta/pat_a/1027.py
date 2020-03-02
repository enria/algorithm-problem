import re
i=input()
i=i.split(" ")
di=['0','1','2','3','4','5','6','7','8','9','A','B',"C"]
def to13(n):
    gw=n%13
    sw=n//13
    return di[sw]+di[gw]

print("#{}{}{}".format(to13(int(i[0])),to13(int(i[1])),to13(int(i[2]))))