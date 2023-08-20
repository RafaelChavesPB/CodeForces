for _ in range(int(input())):
    n = int(input())
    arr = sorted([int(x) for x in input().split()])
    flag = True
    for i in range(1, len(arr)):
        if arr[i] == arr[i-1]:
            flag = False
    print("YES" if flag else "NO")