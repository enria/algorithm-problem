from math import log

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        x=log(n,3)
        return 3**x==n