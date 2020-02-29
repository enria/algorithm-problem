origin = input()
actual = input()

i = -1
brokens = []
for c in actual:
    while True:
        i += 1
        oc = origin[i]
        if oc == c:
            break
        else:
            if oc >= 'a' and oc <= 'z':
                oc = oc.upper()
            if brokens.count(oc) == 0:
                brokens.append(oc)
for j in range(i+1, len(origin)):
    oc = origin[j]
    if oc >= 'a' and oc <= 'z':
        oc = oc.upper()
    if brokens.count(oc) == 0:
        brokens.append(oc)
print("".join(brokens))
