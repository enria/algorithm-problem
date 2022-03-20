s=int(input())

for si in range(s):
    b,i=input().split()
    b,i=int(b),int(i)
    am=[[0]*(b+1) for bi in range(b+1)]
    for ii in range(i):
        f,s=input().split()
        f,s=int(f),int(s)
        am[f][s],am[s][f]=1,1
    
    color=[-1]*(b+1)
    nodes=set(range(1,b+1))
    cur=[list(nodes)[0]]
    color[cur[0]]=0
    found=False
    while nodes and not found:
        nbs=set()
        if not cur:
            cur=[list(nodes)[0]]
            color[cur[0]]=0
        for n in cur:
            cur_c=color[n]
            for x in range(1,b+1):
                if not am[n][x]:continue
                nc=color[x]
                if nc==-1: 
                    color[x]=abs(cur_c-1)
                    nbs.add(x)
                elif nc==cur_c: 
                    found=True
            nodes.remove(n)
        cur=nbs
    print("Scenario #%d:"%(si+1))
    if found:
        print("Suspicious bugs found!")
    else:
        print("No suspicious bugs found!")
    print()
