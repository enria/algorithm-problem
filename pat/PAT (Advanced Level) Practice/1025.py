import functools
n = int(input())

testees = []


def _cmp(t1, t2):
    if t1["sc"] == t2["sc"]:
        return -1 if t1["num"] < t2["num"] else 1
    else:
        return -1 if t1["sc"] > t2["sc"] else 1


def addOrd(ts, key: str, pt=False):
    ts = sorted(ts, key=functools.cmp_to_key(_cmp))
    od = 0
    for num in range(len(ts)):
        i = ts[num]
        if od == 0:
            od = 1
        else:
            if i["sc"] != ts[num-1]["sc"]:
                od = num+1
        ts[num][key] = od
        if pt:
            print(i["num"], od, i["lo"], i["lcr"])


for i in range(1, n+1):
    k = int(input())
    los = []
    for j in range(k):
        te = input()
        te = te.split()
        los.append({"num": int(te[0]), "lo": i, "sc": int(te[1])})
    addOrd(los, "lcr")
    for te in los:
        testees.append(te)

print(len(testees))
addOrd(testees, "glr", pt=True)
