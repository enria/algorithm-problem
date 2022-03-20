from linecache import getline

def gcd(a,b):
    if not b: 
        return a
    else:
        return gcd(b,a%b)

# class Solution:
#     def maxPoints(self, points) -> int:
#         if len(points)<=2: return len(points)
#         points=[tuple(x) for x in points]
#         lines=set()
#         def get_line(p1,p2):
#             if p1[0]==p2[0]:
#                 return (p2[0],)
#             a=(p2[1]-p1[1],p2[0]-p1[0])
#             ga=gcd(a[0],a[1])
#             a=(a[0]//ga,a[1]//ga)
#             b=(p1[1]*a[1]-a[0]*p1[0],a[1])
#             gb=gcd(b[0],b[1])
#             b=(b[0]//gb,b[1]//gb)
#             return (a,b)
#         def in_line(line,p):
#             if len(line)==1:
#                 return p[0]==line[0]
#             else:
#                 return line[0][0]*p[0]*line[1][1]+line[1][0]*line[0][1]==p[1]*line[0][1]*line[1][1]
#         max_l=0
#         for p1 in points:
#             for p2 in points:
#                 if p2==p1: continue
#                 line=get_line(p1,p2)
#                 if line in lines:continue # 这条线已经算过了
#                 ps=[p1,p2]
#                 for p3 in points:
#                     if p3==p2 or p3==p1: continue
#                     if in_line(line,p3):
#                         ps.append(p3)
#                 if len(ps)>max_l:
#                     max_l=len(ps)
#                 lines.add(line)
#         return max_l

class Solution:
    def maxPoints(self, points) -> int:
        if len(points)<=2: return len(points)
        points={tuple(x):{} for x in points}
        def get_line(p1,p2):
            if p1[0]==p2[0]:
                return (p2[0],)
            a=(p2[1]-p1[1],p2[0]-p1[0])
            ga=gcd(a[0],a[1])
            a=(a[0]//ga,a[1]//ga)
            b=(p1[1]*a[1]-a[0]*p1[0],a[1])
            gb=gcd(b[0],b[1])
            b=(b[0]//gb,b[1]//gb)
            return (a,b)
        max_l=0
        for p1 in points:
            for p2 in points:
                if p1==p2:continue
                line=get_line(p1,p2)
                if len(line)==2:
                    line=line[0]
                points[p1].setdefault(line,[p1])
                points[p1][line].append(p2)
                if len(points[p1][line])>max_l:
                    max_l=len(points[p1][line])
        return max_l


s=Solution()
print(s.maxPoints([[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]))
print(s.maxPoints([[1,1],[2,2],[3,3]]))
print(s.maxPoints([[-184,-551],[-105,-467],[-90,-394],[-60,-248],[115,359],[138,429],[60,336],[150,774],[207,639],[-150,-686],[-135,-613],[92,289],[23,79],[135,701],[0,9],[-230,-691],[-115,-341],[-161,-481],[230,709],[-30,-102]]))
