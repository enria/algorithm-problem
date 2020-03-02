ns = input()
while True:
    ns = "0"*(4-len(ns))+ns
    ns = "".join(sorted(ns, reverse=True))
    rns = ns[::-1]
    result = int(ns)-int(rns)
    print("%04d - %04d = %04d" % (int(ns), int(rns), result))
    if result == 6174 or result == 0:
        break
    ns = str(result)