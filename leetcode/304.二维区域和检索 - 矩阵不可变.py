class NumMatrix:

    def __init__(self, matrix):
        self.cache={}
        s=0
        for i in range(-1,len(matrix)):
            row_sum=0
            for j in range(-1,len(matrix[i])):
                if i==-1 or j==-1:
                    self.cache[(i,j)]=0
                    continue
                row_sum+=matrix[i][j]
                self.cache[(i,j)]=row_sum+self.cache[(i-1,j)]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (self.cache[(row2,col2)]
               -self.cache[(row2,col1-1)]
               -self.cache[(row1-1,col2)]
               +self.cache[(row1-1,col1-1)])



# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)

numMatrix =  NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]])
print(numMatrix.sumRegion(2, 1, 4, 3))
print(numMatrix.sumRegion(1, 1, 2, 2))
print(numMatrix.sumRegion(1, 2, 2, 4))
