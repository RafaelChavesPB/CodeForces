from math import sqrt
for _ in range(int(input())):
    n, = [int(x) for x in input().split()]
    value = sum([int(x) for x in input().split()])
    a = int(sqrt(value))
    if a*a == value:
        print("YES")
    else:
        print("NO")
    
