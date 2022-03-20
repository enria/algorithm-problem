from queue import PriorityQueue

class Solution:
    def findItinerary(self, tickets):
        ports={}
        for t in tickets:
            ports.setdefault(t[0],[])
            ports[t[0]].append(t[1])
        
        for t in ports:
            ports[t]=sorted(ports[t])

        def visit(ps,cur,line):
            if len(line)==len(tickets)+1:
                return line
            elif cur not in ports:
                return None
            else:
                for ti in range(len(ps[cur])):
                    t=ps[cur][ti]
                    org=ps[cur]
                    ps[cur]=ps[cur][:ti]+ps[cur][ti+1:]
                    path=visit(ps,t,line+[t])
                    if path:
                        return path
                    ps[cur]=org

        outputs=visit(ports,"JFK",["JFK"])
        return outputs

# tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
# tickets = [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]

s=Solution()
print(s.findItinerary(tickets))
