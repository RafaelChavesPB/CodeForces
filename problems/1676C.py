def diff(a, b):
    d = 0
    for i in range(len(a)):
        d += abs(ord(a[i])-ord(b[i]))
    return d


for _ in range(int(input())):
    n, m = [int(x) for x in input().split()]
    s = [input() for x in range(n)]
    ans = 26*50*8
    for i in range(n):
        for j in range(i+1, n):
            ans = min(ans, diff(s[i], s[j]))
    print(ans)
