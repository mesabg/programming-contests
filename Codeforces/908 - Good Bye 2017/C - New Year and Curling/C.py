from sys import stdin
import operator

class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "(x:" + str(self.x) + ", y:" + str(self.y) + ")"

def calculateDistance():
    global n, r, positions
    distance = 0
    for i in range(n):
        b = r
        if i > 0: 
            _positions = sorted(positions[0:i], key=operator.attrgetter('y'), reverse=True)
            matchPosition = None
            for j in range(len(_positions)):
                dt = abs( positions[i].x - _positions[j].x )
                if dt <= 2*r : #Choque
                    matchPosition = Pair(_positions[j].x, _positions[j].y)
                    break
            
            if matchPosition != None: # Hubo un choque con matchPosition
                a = abs( positions[i].x - matchPosition.x )
                b = ( 4*r**2 - a**2 ) ** (0.5)
        positions[i] = Pair(positions[i].x, b)
    return positions

[n, r] = list(map(int,stdin.readline().strip().split()))
positions = list(map( lambda x: Pair(x, 0), list(map(int,stdin.readline().strip().split())) ))
print( *calculateDistance() )