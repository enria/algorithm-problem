n = int(input())

maxn, sqc = 1, n
start = 2
while (maxn+1)*start < n:
    cur, temp, t = start, start, 1
    if n % start != 0:
        start += 1
        continue
    while True:
        cur = cur+1
        temp *= cur
        t += 1
        if n % temp != 0 or temp > n:
            break
        else:
            if t > maxn:
                maxn = t
                sqc = start
    start += 1

print(maxn)
print("*".join([str(i) for i in range(sqc, sqc+maxn)]))
