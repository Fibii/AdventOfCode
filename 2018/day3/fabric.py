class Fabric:
    def __init__(self,id,leftEdge,topEdge,width,height):
        self.id = id
        self.leftEdge = leftEdge
        self.topEdge = topEdge
        self.width = width
        self.height = height

    #getters
    def getId(self):
        return self.id

    def getLeftEdge(self):
        return self.leftEdge

    def getTopEdge(self):
        return self.topEdge

    def getWidth(self):
        return self.width

    def getHeight(self):
        return self.height
