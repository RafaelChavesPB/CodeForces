for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = 0
    mem = set()
    for c in s:
        if c in mem:
            ans += 1
        else:
            ans += 2
            mem.add(c)
    print(ans)