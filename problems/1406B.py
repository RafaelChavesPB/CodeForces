def product(arr):
    prod = 1
    for x in arr:
        prod *= x
    return prod


for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    neg = [x for x in arr if x < 0]
    pos = [x for x in arr if x >= 0]
    if len(pos) == 0 or (len(arr) == 5 and len(pos) % 2 == 0):
        aux = sorted(list(map(abs, arr)))
        print(-product(aux[:5]))
    else:
        neg.sort()
        pos.sort()
        ans = -1000000000000000
        for i in range(0, 6):
            j = 5 - i
            if len(neg) < j or len(pos) < i:
                continue
            elif i == 0:
                ans = max(product(neg[:j]), ans)
            elif j == 0:
                ans = max(product(pos[-i:]), ans)
            else:
                ans = max(product(pos[-i:])*product(neg[:j]), ans)
        print(ans)
