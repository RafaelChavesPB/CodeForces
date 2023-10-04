for _ in range(int(input())):
    n = int(input())
    s = input()
    mem = {}
    flag = True
    for i in range(n):
        if s[i] in mem:
            flag = flag and mem[s[i]] == i % 2
        else:
            mem[s[i]] = i % 2
    print("YES" if flag else "NO")
