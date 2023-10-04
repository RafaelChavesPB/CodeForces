for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    even = [0, 0]
    odd = [0, 0]
    for i in range(len(arr)):
        if arr[i] % 2:
            odd[i % 2] = 1
        else:
            even[i % 2] = 1
    if even[0] != odd[0] and even[1] != odd[1]:
        print("YES")
    else:
        print("NO")
