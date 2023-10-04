for _ in range(int(input())):
    a, b = input().split()
    tam = max(len(a), len(b))
    a = a.zfill(tam)
    b = b.zfill(tam)
    ans = 0
    for idx in range(tam):
        if a[idx] != b[idx]:
            ans = ord(b[idx]) - ord(a[idx])
            ans += (tam - idx - 1)*9
            break
    print(ans)

