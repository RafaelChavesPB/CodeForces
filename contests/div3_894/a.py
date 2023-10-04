for _ in range(int(input())):
    n, m = [int(x) for x in input().split()]
    grid = [input() for x in range(n)] 
    name = 'vika'
    idx = 0
    flag = False
    for i in range(m):
        for j in range(n):
            if name[idx] == grid[j][i]:
                idx+=1
                if idx == 4:
                    flag = True
                break
        if idx == 4:
            break
    if flag:
        print("YES")
    else:
        print("NO")
