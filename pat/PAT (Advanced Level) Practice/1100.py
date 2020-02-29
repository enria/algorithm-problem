low = "tret,jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec".replace(
    " ", "")
high = ",tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou".replace(
    " ", "")
low, high = low.split(","), high.split(",")


def convert(num):
    if num[0] <= "9":
        num = int(num)
        if num//13:
            if num%13==0:
                return high[num//13]
            return high[num//13]+" "+low[num % 13]
        return low[num]
    else:
        num = num.split()
        result = 0
        if len(num) == 1:
            num=num[0]
            if low.count(num):
                result=low.index(num)
            else:
                result=high.index(num)*13
        else:
            result = high.index(num[0])*13+low.index(num[1])
        return result

n = int(input())
for i in range(n):
    num = input()
    print(convert(num))

