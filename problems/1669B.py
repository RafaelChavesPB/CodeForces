for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    mem = {}
    ans = -1
    for i in arr:
        if i in mem:
            mem[i]+=1
            if mem[i] >= 3:
                ans = i
                break
        else:
            mem[i] = 1
    print(ans)