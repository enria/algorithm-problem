import decimal,re
from decimal import getcontext
n=int(input())

for i in range(n):
    oc=input()[2:]
    getcontext().prec=3*len(oc)
    c=decimal.Decimal(int(oc,base=8))
    c=c/decimal.Decimal(8**len(oc))
    print(f"case #{i}:\n{c}")