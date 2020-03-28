def isPalindrome(num):
    for i in range(0, len(num)//2):
        if(num[i] != num[-(i+1)]):
            return False
    return True

cur = input()
time = 0
while time < 10 and not isPalindrome(cur):
    nextNum=int(cur)+int(str(cur[::-1]))
    print("%s + %s = %d"%(cur,str(cur[::-1]),nextNum))
    cur = str(nextNum)
    time += 1

if isPalindrome(cur):
    print("%s is a palindromic number."%cur)
else:
    print("Not found in 10 iterations.")
