import re
while True:
    try:
        s=input()
        result=[]
        cur_l=-1
        for i,c in enumerate(s):
            if i==0 or c>s[i-1]:
                if cur_l==len(result)-1:
                    result.append([" "]*len(s))
                cur_l+=1
            elif c<s[i-1]:
                cur_l=cur_l-1
                if cur_l<0:
                    result=[[" "]*len(s)]+result
                    cur_l=0
            result[cur_l][i]=c

        for i in result[::-1]:
            print(re.sub(" *$","","".join(i)))
    except EOFError:
        break