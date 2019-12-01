import numpy as np

class Diagram:
    def __init__(self,x,y):
        self.grid = np.zeros( (x,y), dtype=np.int)
        self.res = set([]) #stores the intersection fabrics
        self.count = 0

    #fill the grid with all the fabrics
    def fillGrid(self,fabric):

        left = fabric.getLeftEdge()
        top =  fabric.getTopEdge()
        height = fabric.getHeight()
        width = fabric.getWidth()

        for row in range(top,top + height,1):
            for col in range(left,left + width,1):
                if self.grid[row][col] != 0: #there's an overlap
                    self.res.add(fabric.getId())
                    self.res.add(self.grid[row][col])
                    self.grid[row][col] = 2000
                    self.count = self.count + 1
                else:
                    self.grid[row][col] = fabric.getId()

    def getRes(self):
        res = 0
        for i,val in enumerate(self.grid):
            for j,val in enumerate(self.grid[i]):
                if val == 2000:
                    res = res + 1
        return res