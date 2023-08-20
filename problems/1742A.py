t = int(input())
for _ in range(t):
    arr = [int(x) for x in input().split()]
    total = sum(arr)
    flag = False
    for i in arr:
        if total == 2*i:
            flag = True
            print("YES")
            break
    if not flag:
        print("NO")