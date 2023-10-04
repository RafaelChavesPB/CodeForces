from math import sqrt,ceil
t = int(input())
for T in range(t):
    array = [int(x) for x in input().split()]
    a = min(array)
    b = max(array)
    ans = a + b
    for c in range(1,int(1+1e5)):
        qh = a//c + bool(a%c)
        qv = b//c + bool(b%c)
        ans = min(qh+qv+c-1, ans)
    print(ans)