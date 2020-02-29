n = input()
n, k = [int(i) for i in n.split(" ")]


def palindromic(num: int):
    num = str(num)
    if num == num[::-1]:
        return True
    return False


t = 0
while t < k:
    if palindromic(n):
        break
    n = n+int(str(n)[::-1])
    t += 1

print(n)
print(t)
