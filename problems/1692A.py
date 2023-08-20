t =int(input())
for _ in range(t):
    arr = [int(x) for x in input().split()]
    q = 0
    for i in arr:
        if i > arr[0]:
            q+=1
    print(q)