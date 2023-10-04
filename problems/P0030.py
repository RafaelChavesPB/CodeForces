from math import sqrt

x = 0
y = 1

def sum(a, b):
    return a[x]+b[x], a[y]+b[y]

def dist(a, b):
    return round(sqrt((a[x]-b[x])**2 + (a[y]-b[y])**2), 5)

def diff(a, b):
    return a[x]-b[x], a[y]-b[y]

for _ in range(int(input())):
    t, = [int(x) for x in input().split()]
    coords = [list(map(float, input().split())) for i in range(3)]
    for i in range(3):
        curr = coords[i]
        a = coords[i-1]
        b = coords[i-2]
        if(dist(curr,a) == dist(curr, b)):
            print(t, *sum(a, diff(b, curr)))




    
